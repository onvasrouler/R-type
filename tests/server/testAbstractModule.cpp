/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** buffer tests
*/

#include <gtest/gtest.h>
#include "AbstractModule.hpp"
#ifdef _WIN32
    #include <winsock2.h>  // For Windows socket functions
    #include <stdexcept>   // For exception handling
    #include <cassert>     // For assert
    #pragma comment(lib, "Ws2_32.lib")  // Link with Ws2_32.lib for Winsock
#else
    #include <sys/resource.h>
    #include <netinet/in.h>
    #include "sys/socket.h"
    #include <arpa/inet.h>
#endif

TEST(AbstractModule, testAbstractModuleWithSocket)
{
    #ifdef _WIN32
        WSADATA wsaData;
        int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (result != 0) {
            std::cerr << "WSAStartup failed: " << result << std::endl;
            ASSERT_FALSE(true);
        }
        SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
        ASSERT_NO_THROW(AbstractModule module = AbstractModule(sock));
        WSACleanup();
    #else
        ASSERT_NO_THROW(AbstractModule module = AbstractModule(55));
    #endif
}

TEST(AbstractModule, testAbstractModuleWithoutSocket)
{
    #ifdef _WIN32
        WSADATA wsaData;
        int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (result != 0) {
            std::cerr << "WSAStartup failed: " << result << std::endl;
            ASSERT_FALSE(true);
        }
        ASSERT_NO_THROW(AbstractModule module = AbstractModule());
        WSACleanup();
    #else
        ASSERT_NO_THROW(AbstractModule module = AbstractModule());
    #endif
}

TEST(AbstractModule, testAbstractModuleFailedBasicConstructor)
{
    #ifdef _WIN32
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        ASSERT_EQ(sock, INVALID_SOCKET);
        ASSERT_THROW(AbstractModule module = AbstractModule(), std::runtime_error);
    #else
        struct rlimit lim;

        lim.rlim_cur = 1;
        lim.rlim_max = 1;

        if (setrlimit(RLIMIT_NOFILE, &lim) == 0) {
            std::cout << "La limite des descripteurs de fichiers a été définie à 1." << std::endl;
        } else {
            std::cerr << "Erreur : impossible de définir la limite des descripteurs de fichiers à 1 : "
                    << strerror(errno) << std::endl;
        }
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        ASSERT_EQ(sock, -1);
        ASSERT_THROW(AbstractModule module = AbstractModule(), std::runtime_error);
    #endif
}
TEST(AbstractModule, testAbstractModuleFailedConstructor)
{
    #ifdef _WIN32
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        ASSERT_EQ(sock, INVALID_SOCKET);
        ASSERT_THROW(AbstractModule module = AbstractModule(sock), std::runtime_error);
    #else
        struct rlimit lim;
        lim.rlim_cur = 1;
        lim.rlim_max = 1;
        if (setrlimit(RLIMIT_NOFILE, &lim) == 0) {
            std::cout << "La limite des descripteurs de fichiers a été définie à 1." << std::endl;
        } else {
            std::cerr << "Erreur : impossible de définir la limite des descripteurs de fichiers à 1 : " << strerror(errno) << std::endl;
        }
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        ASSERT_EQ(sock, -1);
        ASSERT_THROW(AbstractModule module = AbstractModule(55), std::runtime_error);
    #endif
}

TEST(AbstractModule, testAbstractModuleStart)
{
    #ifdef _WIN32
        WSADATA wsaData;
        int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (result != 0) {
            std::cerr << "WSAStartup failed: " << result << std::endl;
            ASSERT_FALSE(true);
        }
        SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
        int opt = 1;
        setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));
        ASSERT_NE(sock, INVALID_SOCKET);
        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);
        serv_addr.sin_addr.s_addr = INADDR_ANY;
    #else
        struct rlimit lim;
        lim.rlim_cur = 1000;
        lim.rlim_max = 1000;
        if (setrlimit(RLIMIT_NOFILE, &lim) == 0) {
            std::cout << "La limite des descripteurs de fichiers a été définie à 1000." << std::endl;
        } else {
            std::cerr << "Erreur : impossible de définir la limite des descripteurs de fichiers à 1000 : " << strerror(errno) << std::endl;
        }
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        int opt = 1;
        setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
        ASSERT_NE(sock, -1);
        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);
        serv_addr.sin_addr.s_addr = INADDR_ANY;
    #endif
    int binded = bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    #ifdef _WIN32
        if (binded < 0) {
            std::cout << WSAGetLastError() << std::endl;
        }
    #endif
    ASSERT_EQ(binded, 0);
    int listenSock = listen(sock, 3);
    ASSERT_EQ(listenSock, 0);
    AbstractModule module = AbstractModule(sock);
    ASSERT_NO_THROW(module.start());
    int serverInterSocket = accept(sock, (struct sockaddr *)NULL, NULL);
    ASSERT_NE(serverInterSocket, -1);
    send(serverInterSocket, "200\n\t", 5, 0);
    char buffer[1024] = {0};
    int valread = recv(serverInterSocket, buffer, 1024, 0);
    ASSERT_EQ(valread, 5);
    std::string message = buffer;
    ASSERT_EQ(message, "200\n\t");
    module.stop();
    close(serverInterSocket);
}
