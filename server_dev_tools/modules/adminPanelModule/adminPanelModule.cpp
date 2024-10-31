#include "adminPanelModule.hpp"
#include <mutex>
#include <thread>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <system_error>
#include <regex>

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

void AdminPanelModule::handle_client(std::shared_ptr<boost::asio::ip::tcp::socket> socket) {
    auto buffer = std::make_shared<std::array<char, 128>>();

    socket->async_read_some(boost::asio::buffer(*buffer), 
        [this, socket, buffer](boost::system::error_code error, std::size_t len) {
            if (!error) {
                std::string message(buffer->data(), len);
                std::cout << "Received from admin: " << message << std::endl;

                if (!isClient(socket)) {
                    _clients.push_back(std::make_shared<AdminClient>(socket));
                }
                if (message.find(ADMIN_END_OF_MESSAGE) == message.size() - 2) {
                    message = message.substr(0, message.size() - 2);  // Remove delimiter
                    addMessage(socket, message);
                }
                
                // Recursively call `handle_client` for the next message
                handle_client(socket);
            } else {
                std::cout << "Client disconnected: " << error.message() << std::endl;
            }
        });
}

void AdminPanelModule::start_accept(boost::asio::ip::tcp::acceptor& acceptor) {
    auto socket = std::make_shared<boost::asio::ip::tcp::socket>(acceptor.get_executor());

    acceptor.async_accept(*socket, [this, socket, &acceptor](boost::system::error_code ec) {
        if (!ec) {
            std::cout << "Client connected!" << std::endl;
            handle_client(socket);
        }
        start_accept(acceptor); // Start accepting the next connection
    });
}

AdminPanelModule::AdminPanelModule(const std::string name, const std::string id)
    : AbstractModule(name, id)
{
}

AdminPanelModule::~AdminPanelModule() {
    std::cout << "Module: " << _ModuleName << " is destroying" << std::endl;
    stop(); // Ensure the module is stopped before destruction
    std::cout << "Module: " << _ModuleName << " is destructed" << std::endl;
}

void AdminPanelModule::run() {
    std::cout << "Module: " << _ModuleName << " run" << std::endl;
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::acceptor acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::make_address(getIPv4AddressFromIpconfig()), ADMIN_PANEL_MODULE_PORT));
    std::cout << "Server started on: " << acceptor.local_endpoint().address().to_string() << ":" << acceptor.local_endpoint().port() << std::endl;
    start_accept(acceptor); // Start accepting connections
    std::thread thread;
    thread = std::thread([&io_context] {
        io_context.run();
    });

    fd_set readfds;
    fd_set writefds;
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100;

    while (_Running) {
        for (auto client : _clients) {
            if (client->hasMessage()) {
                std::vector<std::string> messages = client->getMessages();
                for (auto message : messages) {
                    //if message start with ADMIN_PROTOCOL_LOGIN the value in this define
                    message = message.substr(message.find(":") + 1);
                    std::cout << "Message from client: \"" << message << "\"" << std::endl;
                    std::cout << message.find(ADMIN_PROTOCOL_LOGIN) << std::endl;
                    std::cout << message << std::endl;
                    std::cout << ADMIN_PROTOCOL_LOGIN << std::endl;
                    if (message.find(ADMIN_PROTOCOL_LOGIN) == 0) {
                        if (client->IsLogged()) {
                            client->WriteTo("You are already logged in");
                            continue;
                        }
                        std::cout << "Login attempt" << std::endl;
                        message = message.substr(message.find(" ") + 1);
                        std::string name = message.substr(0, message.find(":"));
                        std::string password = message.substr(message.find(":") + 1);
                        std::cout << "Name: " << name << std::endl;
                        std::cout << "Password: " << password << std::endl;
                        if (password == ADMIN_PASSWORD) {
                            client->WriteTo("Logged in as " + name + ADMIN_END_OF_MESSAGE);
                            client->WriteTo(std::string("Welcome to the admin panel") + ADMIN_END_OF_MESSAGE);
                            client->WriteTo(std::string("You can now send messages to the server") + ADMIN_END_OF_MESSAGE);
                            client->WriteTo(std::string("To logout, send: ") + ADMIN_PROTOCOL_LOGOUT + ADMIN_END_OF_MESSAGE);
                            client->setName(name);
                            client->setLogged(true);
                            client->clearMessages();
                        } else {
                            client->WriteTo("Login failed");
                        }
                        continue;
                    }
                    std::cout << message.find(ADMIN_PROTOCOL_LOGOUT) << std::endl;
                    if (message.find(ADMIN_PROTOCOL_LOGOUT) == 0) {
                        if (!client->IsLogged()) {
                            client->WriteTo(std::string("You are not logged in") + ADMIN_END_OF_MESSAGE);
                            continue;
                        }
                        client->WriteTo(std::string("Logged out") + ADMIN_END_OF_MESSAGE);
                        client->setLogged(false);
                    }
                }
                if (!client->IsLogged()) {
                    client->clearMessages();
                }
            }
        }
        FD_ZERO(&readfds);
        FD_ZERO(&writefds);
        FD_SET(_socket, &readfds);
        FD_SET(_socket, &writefds);
#ifdef _WIN32
        int ret = select(0, &readfds, &writefds, NULL, &tv);
#else
        int ret = select(_socket + 1, &readfds, &writefds, NULL, &tv);
#endif
        if (ret == -1) {
            std::throw_with_nested(std::runtime_error("Error: select failed"));
        }
        if (ret == 0) {
            continue;
        }
        // Process messages from clients
        for (auto client : _clients) {
            if (client->hasMessage()) {
                std::vector<std::string> messages = client->getMessages();
                for (auto message : messages) {
                    //if message start with ADMIN_PROTOCOL_LOGIN the value in this define
                    if (!client->IsLogged()) {
                        continue;
                    }
                    if (FD_ISSET(_socket, &writefds)) {
                        std::cout << "Message from client: " << message << std::endl;
                        send(_socket, message.c_str(), message.size(), 0);
                        client->clearMessages();
                    }
                }
            }
        }
        if (!FD_ISSET(_socket, &readfds)) {
            continue;
        }
        char buffer[1024] = {0};
        std::string messages = "";
#ifdef _WIN32
        for (int valread = recv(_socket, buffer, 1024, 0);
             valread != -1 && valread != 0;
             valread = recv(_socket, buffer, 1024, 0)) {
            messages += buffer;
        }
#else
        for (int valread = recv(_socket, buffer, 1024, MSG_DONTWAIT);
             valread != -1 && valread != 0;
             valread = recv(_socket, buffer, 1024, MSG_DONTWAIT)) {
            messages += buffer;
        }
#endif
        for (std::string message =
                 messages.substr(0, messages.find(THREAD_END_MESSAGE));
             messages.find(THREAD_END_MESSAGE) != std::string::npos;
             message = messages.substr(0, messages.find(THREAD_END_MESSAGE)),
                         messages = messages.substr(
                             messages.find(THREAD_END_MESSAGE) + 2)) {
            try {
                // encode message and send to the clients
                std::string uuid = message.substr(0, message.find(":"));
                std::cout << uuid << std::endl;
                std::string messageData = message.substr(message.find(":") + 1);
                std::cout << messageData << std::endl;
                sendMessageToClients(uuid, messageData);
            } catch (std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                continue;
            }
        }
    }
    io_context.stop();
    _thread.join();
    std::cout << "Module: " << _ModuleName << " is stopped" << std::endl;
}

void AdminPanelModule::stop() {
    if (!_Running) return;

    _Running = false; // Mark as not running
    std::cout << "Module: " << _ModuleName << " is stopping" << std::endl;

    // Process remaining logs if necessary (this is commented out for now)
    std::cout << "Module: " << _ModuleName << " stopped" << std::endl;
}

std::string AdminPanelModule::encodeInterCommunication(const std::string message) {
    return message;
}

std::string AdminPanelModule::decodeInterCommunication(const std::string message) {
    return message;
}

bool AdminPanelModule::isClient(const std::shared_ptr<boost::asio::ip::tcp::socket> socket) {
    for (auto client : _clients) {
        if (client->CompareSocket(socket)) {
            return true;
        }
    }
    return false;
}

void AdminPanelModule::addMessage(const std::shared_ptr<boost::asio::ip::tcp::socket> socket, const std::string message) {
    for (auto client : _clients) {
        if (client->CompareSocket(socket)) {
            std::string formatMessage = client->GetUUID() + ":" + message;
            client->addMessage(formatMessage);
        }
    }
}

void AdminPanelModule::sendMessageToClients(const std::string &uuid, const std::string &message) {
    for (auto client : _clients) {
        if (client->GetUUID() == uuid) {
            client->WriteTo(message);
        }
    }
}

#ifdef _WIN32
    extern "C" {
        __declspec(dllexport) AbstractModule* create_module(const std::string name, const std::string id) {
            return new AdminPanelModule(name, id);
        }
    }
#else
    extern "C" {
        AbstractModule* create_module(const std::string name, const std::string id) {
            return new AdminPanelModule(name, id);
        }
    }
#endif
