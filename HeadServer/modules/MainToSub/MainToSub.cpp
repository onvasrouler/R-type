#include "MainToSub.hpp"
#include <mutex>
#include <thread>
#include <chrono>
#include <filesystem>
#include <fstream>

MainToSub::MainToSub(const std::string name, const std::string id)
    : AbstractModule(name, id)
{
}

MainToSub::~MainToSub() {
    {
        std::cout << "Module: " << _ModuleName << " is destroying" << std::endl;
        stop(); // Ensure the module is stopped before destruction
        std::cout << "Module: " << _ModuleName << " is destructed" << std::endl;
    }
}

void MainToSub::run() {
    std::cout << "Module: " << _ModuleName << " run" << std::endl;


    while (_Running) {
    }

    std::cout << "Module: " << _ModuleName << " stopped running" << std::endl;
}

void MainToSub::stop() {
    // std::lock_guard<std::mutex> lock(_destroyMutex); // Lock to ensure thread safety
    if (!_Running) return;

    _Running = false; // Mark as not running
    std::cout << "Module: " << _ModuleName << " is stopping" << std::endl;

    // Process remaining logs if necessary (this is commented out for now)
    std::cout << "Module: " << _ModuleName << " stopped" << std::endl;
}

std::string MainToSub::encodeInterCommunication(const std::string message) {
    return message;
}

std::string MainToSub::decodeInterCommunication(const std::string message) {
    return message;
}