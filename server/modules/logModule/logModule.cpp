#include "logModule.hpp"
#include <mutex>
#include <thread>
#include <chrono>
#include <filesystem>
#include <fstream>

static void checkDir(std::filesystem::path path) {
    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directory(path);
    }
}

static void checkFile(std::filesystem::path path) {
    if (!std::filesystem::exists(path)) {
        std::ofstream file(path, std::ios::app);
        file.close();
    }
}

static std::string getHourMinuteSeconds() {
    // Get current time as time_t object
    std::time_t t = std::time(nullptr);

    // Convert time_t to tm struct for local time
    std::tm* localTime = std::localtime(&t);

    // Output the time in "hour:minute:seconds" format
    std::ostringstream oss;
    oss << std::put_time(localTime, "%H:%M:%S");
    std::string timeString = oss.str();
    return timeString;
}

static std::string getDayName() {
    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);
    const char* days[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };
    std::string dayName = days[localTime->tm_wday];
    return dayName;
}

static std::string getMonthName() {
    std::time_t t = std::time(nullptr);

    // Convert time_t to tm struct for local time
    std::tm* localTime = std::localtime(&t);

    // Array of month names
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Get the month from the tm struct (tm_mon is 0-based, so add 0 to access the correct month)
    std::string monthName = months[localTime->tm_mon];
    return monthName;
}

static std::string getYear() {
    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);
    int year = localTime->tm_year + 1900;
    std::string yearString = std::to_string(year);
    return yearString;
}

static std::string getDayNumber() {
    std::time_t t = std::time(nullptr);

    // Convert time_t to tm struct for local time
    std::tm* localTime = std::localtime(&t);

    // Calculate the day number
    std::ostringstream oss;
    oss << std::put_time(localTime, "%d");
    std::string day = oss.str();
    return day;
}

static std::string getIsoDate() {
    std::time_t t = std::time(nullptr);

    // Convert time_t to tm struct for local time
    std::tm* localTime = std::localtime(&t);

    // Calculate the ISO date
    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y-%d-%m");
    std::string date = oss.str();
    return date;
}

LogModule::LogModule(const std::string name, const std::string id)
    : AbstractModule(name, id)
{
    checkLogDir(); // Ensure the log directory exists
    _date = getIsoDate();
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
    std::cout << "Module: " << _ModuleName << " run" << std::endl;
    std::ostringstream buffer; // Buffer to capture logs
    std::ostringstream tempbuffer; // Temporary buffer to handle logs
    auto old_buf = std::cout.rdbuf(); // Save the original buffer
    std::cout.rdbuf(buffer.rdbuf()); // Redirect cout to our buffer
    std::string path = "logs/" + getYear() + "/" + getMonthName() + "/" + getIsoDate() + ".txt";
    std::ofstream file;


    while (_Running) {
        std::string actualPath = "logs/" + getYear() + "/" + getMonthName() + "/" + getIsoDate() + ".txt";
        if (path != actualPath) {
            path = actualPath;
        }
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
            if (line.find(DEBUG_MACRO) != std::string::npos) {
                line = line.substr(std::string(DEBUG_MACRO).size(), line.size());
                std::ostream old_stream(old_buf);
                old_stream << line << "\n";
            }
            std::string logFormat = getHourMinuteSeconds() + " " + getDayName() + "-" + getDayNumber() + "-" + getMonthName() + "-" + getYear() + ": " + line + "\n";
            file.open(path, std::ios::app);
            file.write(logFormat.c_str(), logFormat.size());
            file.close();
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

void LogModule::checkLogDir() {
    std::filesystem::path path = "logs";
    checkDir(path);

    path += "/" + getYear();
    checkDir(path);

    std::string monthName = getMonthName();
    std::string monthPath = path.string() + "/" + monthName;
    checkDir(monthPath);

    std::string date = getIsoDate();
    std::cout << "date: " << date << std::endl;
    std::string datePath = monthPath + "/" + date + ".txt";
    checkFile(datePath);
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
