/*
** EPITECH PROJECT, 2024
** Server UDP R-Type
** File description:
** UDPServer.cpp
*/

#include "UDPServer.hpp"
#include "UDPError.hpp"
#ifdef _WIN32
#include <Windows.h>
#endif
#include <array>
#include <cstdio>
#include <iostream>
#include <memory>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

packageData::packageData(const std::string data, const std::string ip,
                         const std::size_t port)
    : _data(data), _ip(ip), _port(port){};

std::string packageData::getData() { return _data; }

std::string packageData::getIp() { return _ip; }

std::size_t packageData::getPort() { return _port; }

#ifdef _WIN32
std::string exec(const char* cmd) {
    HANDLE hRead, hWrite;
    SECURITY_ATTRIBUTES sa = {sizeof(SECURITY_ATTRIBUTES), NULL, TRUE};

    if (!CreatePipe(&hRead, &hWrite, &sa, 0)) {
        throw std::runtime_error("CreatePipe failed!");
    }

    SetHandleInformation(hRead, HANDLE_FLAG_INHERIT, 0);

    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

    STARTUPINFO si;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    si.hStdOutput = hWrite;
    si.hStdError = hWrite;
    si.dwFlags |= STARTF_USESTDHANDLES;

    // Convert cmd from char* to wchar_t*
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, cmd, -1, NULL, 0);
    std::wstring wcmd(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, cmd, -1, &wcmd[0], size_needed);

    // Use CreateProcessW for wide character string
    if (!CreateProcessW(NULL, &wcmd[0], NULL, NULL, TRUE, 0, NULL, NULL,
                        (LPSTARTUPINFOW)&si, &pi)) {
        CloseHandle(hWrite);
        CloseHandle(hRead);
        throw std::runtime_error("CreateProcess failed!");
    }

    CloseHandle(hWrite);

    std::string result;
    char buffer[128];
    DWORD bytesRead;
    while (ReadFile(hRead, buffer, sizeof(buffer) - 1, &bytesRead, NULL) &&
           bytesRead > 0) {
        buffer[bytesRead] = '\0';
        result += buffer;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    CloseHandle(hRead);

    return result;
}

std::string getIPv4AddressFromIpconfig() {
    std::string output = exec("ipconfig");
    std::string ipv4Address;

    // Search for lines containing "IPv4 Address"
    std::istringstream stream(output);
    std::string line;
    while (std::getline(stream, line)) {
        // Check for "IPv4 Address" line
        if (line.find("IPv4 Address") != std::string::npos) {
            // Extract the IP address from the line
            std::string::size_type start =
                line.find(":") + 2; // Find position after the colon and space
            std::string::size_type end =
                line.find('\r', start); // Find end of the line
            ipv4Address =
                line.substr(start, end - start); // Extract the address
            break; // Break after finding the first IPv4 address
        }
    }
    std::cout << "Public IPV4 Address: " << ipv4Address << std::endl;
    return ipv4Address;
}
#else
static std::string exec(const char* cmd) {
    // Open a pipe to the command
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    // Read the output from the command
    char buffer[128];
    std::string result;
    while (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
        result += buffer;
    }

    return result;
}

std::string getIPv4AddressFromIpconfig() {
    // Regex patterns to match IPv4 and IPv6 addresses
    std::regex ipv4_regex(R"((\d{1,3}\.){3}\d{1,3})");
    std::string ipv4 = "";

    std::smatch match;

    // Split the output into lines
    std::string output = exec("ip a");
    std::istringstream stream(output);
    std::string line;

    // Iterate through each line and find IP addresses
    while (std::getline(stream, line)) {
        if (std::regex_search(line, match, ipv4_regex)) {
            ipv4 = match.str();
        }
    }
    std::cout << "Public IPV4 Address: " << ipv4 << std::endl;
    return ipv4;
}
#endif

UDPServer::UDPServer(boost::asio::io_context& io_context, const short port)
    : _socket(io_context, udp::endpoint(boost::asio::ip::make_address(
                                            getIPv4AddressFromIpconfig()),
                                        port)) {
    std::cout << "Create UDP Server" << std::endl;
    std::cout << "Server IP: " << _socket.local_endpoint().address().to_string()
              << std::endl;
    std::cout << "Server Port: " << _socket.local_endpoint().port()
              << std::endl;
    _running = true;
    start_receive();
}

void UDPServer::stop() {
    _running = false;
    if (_sendMutex.try_lock()) {
        _sendMutex.unlock();
    }
    if (_receiveMutex.try_lock()) {
        _receiveMutex.unlock();
    }
}

void UDPServer::start_receive() {
    if (!_running) {
        return;
    }
    _socket.async_receive_from(
        boost::asio::buffer(_recv_buffer), _remote_endpoint,
        [this](std::error_code ec, std::size_t bytes_recvd) {
            if (!ec) {
                handle_receive(bytes_recvd);
            } else {
                std::cout << "Error during receiving data: " << ec.message()
                          << std::endl;
                _stopMutex.lock();
                if (ec && _running) {
#ifdef _WIN32
                    std::cerr << "Error during receiving data: " << ec.message()
                              << std::endl;
#endif
                    throw UDPError("Error during receiving data: " +
                                   ec.message());
                }
                _stopMutex.unlock();
                start_receive();
            }
        });
}

void UDPServer::handle_receive(std::size_t length) {
    if (!_running) {
        return;
    }
    try {
        if (length > 0) {
            std::string decoded_message(_recv_buffer.data(), length);
            // std::cout << "Decoded message: " << decoded_message << std::endl;

            packageData data = packageData(
                decoded_message, _remote_endpoint.address().to_string(),
                _remote_endpoint.port());
            std::cout << "Message received" << data.getData()
                      << " from: " << data.getIp() << ":" << data.getPort()
                      << std::endl;
            _receiveMutex.lock();
            _receivedData.push_back(data);
            _receiveMutex.unlock();
        }
        start_receive();
    } catch (const UDPError& e) {
        std::cerr << "UDP Server Error: " << e.what() << std::endl;
    }
}

void UDPServer::sendMessages() {
    if (!_running) {
        return;
    }
    _sendMutex.lock();
    for (auto& data : _sentData) {
        try {
            std::cout << "Send message: " << data.getData() << std::endl;
            std::cout << "Send ip: " << data.getIp() << std::endl;
            std::cout << "Send port: " << data.getPort() << std::endl;
            _remote_endpoint.address(
                boost::asio::ip::make_address(data.getIp()));
            _remote_endpoint.port(data.getPort());
            _socket.send_to(boost::asio::buffer(data.getData()),
                            _remote_endpoint);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            continue;
        }
    }
    _sentData.clear();
    _sendMutex.unlock();
}

std::mutex& UDPServer::getSendMutex() { return _sendMutex; }

std::mutex& UDPServer::getReceiveMutex() { return _receiveMutex; }

std::mutex& UDPServer::getStopMutex() { return _stopMutex; }

std::vector<packageData>& UDPServer::getReceivedData() { return _receivedData; }

std::vector<packageData>& UDPServer::getSentData() { return _sentData; }
