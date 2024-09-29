/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "MultiThread.hpp"
#ifdef _WIN32
    // Initialisation de Winsock
    void init_winsock() {
        WSADATA wsaData;
        int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (result != 0) {
            std::cerr << "WSAStartup failed: " << result << std::endl;
            exit(1);
        }
    }
#endif

MultiThreadElement::MultiThreadElement() {
    _datas = std::vector<MultiThreadData>();
    _sendingIntern = std::vector<std::string>();
    _receivedIntern = std::vector<std::string>();
    #ifdef _WIN32
        _otherModules = std::vector<SOCKET>();
        _socket = socket(AF_INET, SOCK_STREAM, 0);
        if (_socket == INVALID_SOCKET) {
            std::throw_with_nested(std::runtime_error("Error: socket creation failed"));
        }
    #else
        _otherModules = std::vector<int>();
        _socket = socket(AF_INET, SOCK_STREAM, 0);
        if (_socket == -1) {
            std::throw_with_nested(std::runtime_error("Error: socket creation failed"));
        }
    #endif
}

#ifdef _WIN32
    MultiThreadElement::MultiThreadElement(const SOCKET serverInterSocket) {
        if (serverInterSocket == INVALID_SOCKET) {
            std::throw_with_nested(std::runtime_error("Error: invalid socket"));
        }
        _datas = std::vector<MultiThreadData>();
        _otherModules = std::vector<SOCKET>();
        _otherModules.push_back(serverInterSocket);
        _sendingIntern = std::vector<std::string>();
        _receivedIntern = std::vector<std::string>();
        _socket = socket(AF_INET, SOCK_STREAM, 0);
        if (_socket == INVALID_SOCKET) {
            std::throw_with_nested(std::runtime_error("Error: socket creation failed"));
        }
    }
#else
    MultiThreadElement::MultiThreadElement(const int serverInterSocket) {
        if (serverInterSocket == -1) {
            std::throw_with_nested(std::runtime_error("Error: invalid socket"));
        }
        _datas = std::vector<MultiThreadData>();
        _otherModules = std::vector<int>();
        _otherModules.push_back(serverInterSocket);
        _sendingIntern = std::vector<std::string>();
        _receivedIntern = std::vector<std::string>();
        _socket = socket(AF_INET, SOCK_STREAM, 0);
        if (_socket == -1) {
            std::throw_with_nested(std::runtime_error("Error: socket creation failed"));
        }
    }
#endif

MultiThreadData::MultiThreadData() {
    _data = std::any();
}

MultiThreadData::MultiThreadData(const std::any data) {
    _data = data;
}
std::any MultiThreadData::getData() const {
    return _data;
}

void MultiThreadData::setData(const std::any data) {
    _data = data;
}

void MultiThreadData::setData(std::any &data) {
    _data = data;
}
