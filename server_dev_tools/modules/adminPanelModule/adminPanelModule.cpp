#include "adminPanelModule.hpp"
#include <mutex>
#include <thread>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <system_error>

void AdminPanelModule::handle_client(std::shared_ptr<boost::asio::ip::tcp::socket> socket) {
    try {
        // Read message from client
        std::array<char, 128> buffer;
        boost::system::error_code error;
        size_t len = socket->read_some(boost::asio::buffer(buffer), error);

        if (error == boost::asio::error::eof) {
            std::cout << "Client disconnected." << std::endl;
        } else if (error) {
            throw boost::system::system_error(error);
        } else {
            std::string message = std::string(buffer.data(), len);
            std::cout << "Received from admin: " << message << std::endl;
            if (!isClient(socket)) {
                _clients.push_back(std::make_shared<AdminClient>(socket));
            }
            addMessage(socket, message);
        }
    } catch (std::exception& e) {
        std::cerr << "Exception in client handler: " << e.what() << std::endl;
    }
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
    {
        std::cout << "Module: " << _ModuleName << " is destroying" << std::endl;
        stop(); // Ensure the module is stopped before destruction
        std::cout << "Module: " << _ModuleName << " is destructed" << std::endl;
    }
}

void AdminPanelModule::run() {
    std::cout << "Module: " << _ModuleName << " run" << std::endl;
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::acceptor acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), ADMIN_PANEL_MODULE_PORT));
    std::cout << "Server started on: " << acceptor.local_endpoint().address().to_string() << ":" << acceptor.local_endpoint().port() << std::endl;
    start_accept(acceptor); // Start accepting connections
    _thread = std::thread([&io_context] {
        io_context.run();
    });

    fd_set readfds;
    fd_set writefds;
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100;

    while (_Running) {
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
        if (FD_ISSET(_socket, &writefds)) {
            for (auto client : _clients) {
                if (client->hasMessage()) {
                    std::vector<std::string> messages = client->getMessages();
                    for (auto message : messages) {
                        std::cout << "Message from client: " << message << std::endl;
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
    // std::lock_guard<std::mutex> lock(_destroyMutex); // Lock to ensure thread safety
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
            std::string formatMessage = client->GetUUID() + ": " + message;
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
