#include <iostream>
#include <csignal>  // For signal handling
#include "Server.hpp"

#ifdef _WIN32
    int setupWinsock() {
        WSADATA wsaData;
        int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (result != 0) {
            std::cout << "WSAStartup failed: " << result << std::endl;
            throw std::runtime_error("WSAStartup failed");
        }
        std::cout << "WSAStartup succeeded" << std::endl;
        return 0;
    };
int tmp = setupWinsock();
#endif

Server server;

void signalHandler(int signum) {
    try {
        // server.stop();  // Stop the server
        exit(0);   // Exit the program
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit(1);  // Exit the program with error
    }
}

int main() {
    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, signalHandler);

    server.start();
    server.run();
    return 0;
}
