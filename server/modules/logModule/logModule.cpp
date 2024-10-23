#include "logModule.hpp"
#include <mutex>
#include <thread>
#include <chrono>

LogModule::LogModule(const std::string name, const std::string id)
    : AbstractModule(name, id)
{
}

LogModule::~LogModule() {
    {
        std::lock_guard<std::mutex> lock(_destroyMutex); // Lock to ensure thread safety
        std::cout << "Module: " << _ModuleName << " is destroying" << std::endl;
        stop(); // Ensure the module is stopped before destruction
        std::cout << "Module: " << _ModuleName << " is destructed" << std::endl;
    }
}

void LogModule::run() {
    std::ostringstream buffer; // Buffer to capture logs
    std::ostringstream tempbuffer; // Temporary buffer to handle logs
    auto old_buf = std::cout.rdbuf(); // Save the original buffer
    std::cout.rdbuf(buffer.rdbuf()); // Redirect cout to our buffer

    std::cout << "Module: " << _ModuleName << " run" << std::endl;

    while (_Running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Small delay

        // Capture logs from the buffer
        std::string new_data = buffer.str();
        if (!new_data.empty()) {
            tempbuffer << new_data; // Accumulate logs
            buffer.str(""); // Clear the buffer
        }

        std::string log = tempbuffer.str(); // Get all logs for processing
        tempbuffer.str(""); // Clear temp buffer

        // Process each complete line (message)
        std::size_t pos = 0;
        while ((pos = log.find('\n')) != std::string::npos) {
            std::string line = log.substr(0, pos);
            std::cerr << "log: " << line << std::endl; // Print log message
            log.erase(0, pos + 1); // Remove processed line
        }
    }

    std::cout.rdbuf(old_buf); // Restore the original buffer
    std::cout << "Module: " << _ModuleName << " stopped running" << std::endl;
}

void LogModule::stop() {
    // std::lock_guard<std::mutex> lock(_destroyMutex); // Lock to ensure thread safety
    if (!_Running) return;

    _Running = false; // Mark as not running
    std::cout << "Module: " << _ModuleName << " is stopping" << std::endl;

    // Process remaining logs if necessary (this is commented out for now)
    std::cout << "Module: " << _ModuleName << " stopped" << std::endl;
}

std::string LogModule::encodeInterCommunication(const std::string message) {
    return message;
}

std::string LogModule::decodeInterCommunication(const std::string message) {
    return message;
}

#ifdef _WIN32
    extern "C" {
        __declspec(dllexport) AbstractModule* create_module(const std::string name, const std::string id) {
            return new LogModule(name, id);
        }
    }
#else
    extern "C" {
        AbstractModule* create_module(const std::string name, const std::string id) {
            return new LogModule(name, id);
        }
    }
#endif
