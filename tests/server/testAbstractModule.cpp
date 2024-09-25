/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** buffer tests
*/

#include <gtest/gtest.h>
#include <sys/resource.h>
#include "AbstractModule.hpp"
#include <netinet/in.h>
#include "sys/socket.h"
#include <arpa/inet.h>

TEST(AbstractModule, testAbstractModuleWithSocket)
{
    ASSERT_NO_THROW(AbstractModule module = AbstractModule(55));
}

TEST(AbstractModule, testAbstractModuleWithoutSocket)
{
    ASSERT_NO_THROW(AbstractModule module = AbstractModule());
}

TEST(AbstractModule, testAbstractModuleFailedBasicConstructor)
{
    struct rlimit lim;

    // Etape 1 : Définir la limite des fichiers ouverts à 1
    lim.rlim_cur = 1;     // Limite soft : 1 fichier ouvert
    lim.rlim_max = 1;     // Limite hard : 1 fichier maximum

    if (setrlimit(RLIMIT_NOFILE, &lim) == 0) {
        std::cout << "La limite des descripteurs de fichiers a été définie à 1." << std::endl;
    } else {
        std::cerr << "Erreur : impossible de définir la limite des descripteurs de fichiers à 1 : "
                  << strerror(errno) << std::endl;
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    ASSERT_EQ(sock, -1);
    ASSERT_THROW(AbstractModule module = AbstractModule(), std::runtime_error);
}

TEST(AbstractModule, testAbstractModuleFailedConstructor)
{
    struct rlimit lim;

    // Etape 1 : Définir la limite des fichiers ouverts à 1
    lim.rlim_cur = 1;     // Limite soft : 1 fichier ouvert
    lim.rlim_max = 1;     // Limite hard : 1 fichier maximum

    if (setrlimit(RLIMIT_NOFILE, &lim) == 0) {
        std::cout << "La limite des descripteurs de fichiers a été définie à 1." << std::endl;
    } else {
        std::cerr << "Erreur : impossible de définir la limite des descripteurs de fichiers à 1 : " << strerror(errno) << std::endl;
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    ASSERT_EQ(sock, -1);
    ASSERT_THROW(AbstractModule module = AbstractModule(55), std::runtime_error);
}

TEST(AbstractModule, testAbstractModuleStart)
{
    struct rlimit lim;

    // Etape 1 : Définir la limite des fichiers ouverts à 1
    lim.rlim_cur = 1000;     // Limite soft : 1 fichier ouvert
    lim.rlim_max = 1000;     // Limite hard : 1 fichier maximum

    if (setrlimit(RLIMIT_NOFILE, &lim) == 0) {
        std::cout << "La limite des descripteurs de fichiers a été définie à 1." << std::endl;
    } else {
        std::cerr << "Erreur : impossible de définir la limite des descripteurs de fichiers à 1 : " << strerror(errno) << std::endl;
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    ASSERT_NE(sock, -1);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    int binded = bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
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
