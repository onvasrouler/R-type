/*
** EPITECH PROJECT, 2024
** Server UDP R-Type
** File description:
** main.cpp
*/

#include "UDPError.hpp"
#include "UDPServer.hpp"
#include <boost/asio.hpp>
#include <iostream>

int main() {
    try {
        boost::asio::io_context io_context;
        UDPServer server(io_context, 8080);
        io_context.run();
    } catch (const UDPError& e) {
        std::cerr << "Caught UDPError: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
