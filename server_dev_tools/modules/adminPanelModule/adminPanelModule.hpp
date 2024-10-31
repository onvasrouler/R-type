/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "AbstractModule.hpp"
#include <boost/asio.hpp>
#include <sstream>
#include <mutex>
#include <system_error>
#include "adminClient.hpp"

#define ADMIN_PANEL_MODULE_PORT 8084

#define ADMIN_PASSWORD "123456passwordazerty00000013082004"

//admin protocol
#define ADMIN_END_OF_MESSAGE "\r\n"
#define ADMIN_PROTOCOL_LOGIN "LOGIN"
#define ADMIN_PROTOCOL_LOGOUT "LOGOUT"

class AdminPanelModule : public AbstractModule {
    public:
        /**
        * @brief Constructor of AdminPanelModule.
        */
        AdminPanelModule() = default;
        /**
        * @brief Constructor of AdminPanelModule.
        * @param name The name of the module.
        * @param id The id of the module.
        */
        AdminPanelModule(const std::string name, const std::string id);
        /**
        * @brief Destructor of AdminPanelModule.
        * if the module is running, it will stop it.
        */
        ~AdminPanelModule();
        /**
        * @brief The main loop of the module
        */
        void run() override;
        /**
        * @brief Stop the module.
        */
        void stop() override;
    private:
        /**
        * @brief Encode the message to send to the server.
        * @param message The message to encode.
        */
        std::string encodeInterCommunication(const std::string message)override;
        /**
        * @brief Decode the message received from the server.
        * @param message The message to decode.
        */
        std::string decodeInterCommunication(const std::string message) override;

        void handle_client(std::shared_ptr<boost::asio::ip::tcp::socket> socket);

        void start_accept(boost::asio::ip::tcp::acceptor& acceptor);

        bool isClient(const std::shared_ptr<boost::asio::ip::tcp::socket> socket);

        void addMessage(const std::shared_ptr<boost::asio::ip::tcp::socket> socket, const std::string message);

        void sendMessageToClients(const std::string &uuid, const std::string &message);

        std::vector<std::shared_ptr<AdminClient>> _clients;
};
