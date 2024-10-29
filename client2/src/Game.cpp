/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** game
*/

#include "Game.hpp"
#include <array>
#include <cstdio>
#include <iostream>
#include <memory>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

Game::Game() : _socket(nullptr)
{
    gameIsRunning = false;
    
    enemyTexture.loadFromFile("chipset/enemy.png");
    playerTexture.loadFromFile("chipset/player.png");
    bulletTexture.loadFromFile("chipset/bullet.png");
}

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

void Game::run(sf::RenderWindow &window, boost::asio::io_context &io_context, boost::asio::ip::basic_resolver_results<boost::asio::ip::udp> &endpoints)
{
    gameIsRunning = true;
    backgroundTexture.loadFromFile("chipset/background.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    _socket = std::make_unique<boost::asio::ip::udp::socket>(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::make_address(getIPv4AddressFromIpconfig()), 8081));
    std::cout << "Socket: " << _socket->local_endpoint().address().to_string() << ": " << _socket->local_endpoint().port() << std::endl;
    
    startRecieve();

    std::string message = "00\r\n";
    std::vector<char> binary_message(message.begin(), message.end());

    std::cout << "Send: ";
    for (auto &c : binary_message)
        std::cout << c;
    std::cout << " to: " << endpoints->endpoint().address().to_string() << ":" << endpoints->endpoint().port() << std::endl;

    _socket->send_to(boost::asio::buffer(binary_message), *endpoints.begin());

    while (gameIsRunning) {
        processEvents(window, endpoints);
        render(window);

        io_context.poll();
    }
    io_context.stop();
}

void Game::startRecieve()
{
    sender_endpoint_ = boost::asio::ip::udp::endpoint();

    _socket->async_receive_from(boost::asio::buffer(recv_buffer), sender_endpoint_, [this](boost::system::error_code ec, std::size_t bytes_recvd) {
        handle_receive(ec, bytes_recvd);
    });
}

std::vector<std::string> split(const std::string& str, char delimiter, std::vector<std::string> &tokens) {
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    if (!tokens.empty() && tokens.back().size() >= 2) {
        tokens.back().erase(tokens.back().size() - 2, 2);
    }
    return(tokens);
}

void Game::update(std::string message)
{
    try {
        std::vector<std::string> instruction;
        split(message, '/', instruction);
        
        if (instruction[0].compare("01") == 0) {
            objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[5]), std::stoi(instruction[6]), PLAYER, playerTexture);
            id = instruction[1];
        }
        if (instruction[0].compare("200") == 0) {
                objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[5]), std::stoi(instruction[6]), PLAYER, playerTexture);
        }
        if (instruction[0].compare("210") == 0) {
                objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[5]), std::stoi(instruction[6]), ENEMY, enemyTexture);
        }
        if (instruction[0].compare("220") == 0) {
                objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[2]), std::stoi(instruction[3]), BULLET, bulletTexture);
        }
        if (instruction[0].compare("203") == 0 || instruction[0].compare("213") == 0 || instruction[0].compare("222") == 0) {
            if (objects.find(instruction[1]) != objects.end()) {
                if(instruction[1].compare(id) == 0) {
                    gameIsRunning = false;
                }
                objects.erase(instruction[1]);
            }
        }
        if (instruction[0].compare("202") == 0 || instruction[0].compare("212") == 0 || instruction[0].compare("221") == 0) {
            if (objects.find(instruction[1]) != objects.end()) {
                objects[instruction[1]]->setPosition(std::stoi(instruction[2]), std::stoi(instruction[3]));
            } else {
                if (instruction[0].compare("202") == 0) {
                    objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[2]), std::stoi(instruction[3]), PLAYER, playerTexture);
                } else if (instruction[0].compare("212") == 0) {
                    objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[2]), std::stoi(instruction[3]), ENEMY, enemyTexture);
                } else if (instruction[0].compare("212") == 0) {
                    objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[2]), std::stoi(instruction[3]), BULLET, bulletTexture);
                }
            }
        }
    }
    catch (const std::invalid_argument& e) {
        std::cout << "non\n";
    }
}

void Game::handle_receive(const boost::system::error_code& error, std::size_t bytes_recvd)
{
    if (!error) {
        std::string message(recv_buffer.data(), bytes_recvd);

        std::cout << message << std::endl;
        
        update(message);

        startRecieve();
    } else {
            std::cerr << "Error on receive: " << error.message() << std::endl;
    }
}

void Game::render(sf::RenderWindow &window)
{
    window.clear();

    window.draw(backgroundSprite);

    for (std::map<std::string, std::shared_ptr<GameObject>>::iterator it = objects.begin(); it != objects.end(); ++it)
    {
        window.draw(it->second->Sprite);
    }

    window.display();
}

void Game::processEvents(sf::RenderWindow &window, boost::asio::ip::basic_resolver_results<boost::asio::ip::udp> &endpoints){
    sf::Event event;
    std::string message;
    bool action = false;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Up) {
                message = "1/up\r\n";
                action = true;
            } else if(event.key.code == sf::Keyboard::Down) {
                message = "1/down\r\n";
                action = true;
            } else if(event.key.code == sf::Keyboard::Left) {
                message = "1/left\r\n";
                action = true;
            } else if(event.key.code == sf::Keyboard::Right) {
                message = "1/right\r\n";
                action = true;
            } else if(event.key.code == sf::Keyboard::Space) {
                message = "1/shoot\r\n";
                action = true;
            } else if(event.key.code == sf::Keyboard::Escape)
                gameIsRunning = false;
        }
    }

    if (action) {
        std::vector<char> binary_message(message.begin(), message.end());
        _socket->send_to(boost::asio::buffer(binary_message), *endpoints.begin());
    }
}
