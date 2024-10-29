#include "MainToClients.hpp"
#include <mutex>
#include <thread>
#include <chrono>
#include <filesystem>
#include <fstream>

MainToClients::MainToClients(const std::string name, const std::string id)
    : AbstractModule(name, id)
{
}

MainToClients::~MainToClients() {
    {
        std::cout << "Module: " << _ModuleName << " is destroying" << std::endl;
        stop(); // Ensure the module is stopped before destruction
        std::cout << "Module: " << _ModuleName << " is destructed" << std::endl;
    }
}

void MainToClients::run() {
    std::cout << "Module: " << _ModuleName << " run" << std::endl;


    while (_Running) {
    }

    std::cout << "Module: " << _ModuleName << " stopped running" << std::endl;
}

void MainToClients::stop() {
    // std::lock_guard<std::mutex> lock(_destroyMutex); // Lock to ensure thread safety
    if (!_Running) return;

    _Running = false; // Mark as not running
    std::cout << "Module: " << _ModuleName << " is stopping" << std::endl;

    // Process remaining logs if necessary (this is commented out for now)
    std::cout << "Module: " << _ModuleName << " stopped" << std::endl;
}

std::string MainToClients::encodeInterCommunication(const std::string message) {
    return message;
}

std::string MainToClients::decodeInterCommunication(const std::string message) {
    return message;
}
