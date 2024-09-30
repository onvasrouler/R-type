#include <iostream>
#include <csignal>  // For signal handling
#include "Server.hpp"

Server server;

void signalHandler(int signum) {
    try {
        server.stop();  // Stop the server
        exit(0);   // Exit the program
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit(1);  // Exit the program with error
    }
}

int main() {
    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, signalHandler);

    #ifdef _WIN32
        WSADATA wsaData;
        int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (result != 0) {
            throw std::runtime_error("WSAStartup failed");
        }
        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);
        serv_addr.sin_addr.s_addr = INADDR_ANY;
    #endif

    server.start();
    server.run();

    // Normal shutdown after Ctrl+C
    // server.stop();
    return 0;
}
