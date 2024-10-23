/*
** EPITECH PROJECT, 2024
** Server UDP R-Type
** File description:
** main.cpp
*/
#include "HeadServer.hpp"
#include <csignal> // For signal handling
#include <iostream>

/**
 * @mainpage R-Type Project
 * 
 * # R-TYPE: A GAME ENGINE THAT ROARS!
 * 
 * ## Preliminaries
 * - **Binary**: `r-type_server`, `r-type_client`
 * - **Language**: C++
 * - **Build System**: CMake, Package Manager Vcpkg CMake
 * 
 * This project of the Advanced C++ knowledge unit introduces you to networked video game development, and explores advanced development techniques as well as good software engineering practices.
 * The goal is to implement a multi-threaded server and a graphical client for the legacy video game R-Type using a custom-designed game engine.
 * 
 * ## Project Goals
 * 
 * 1. **Part 1: Software Architecture & First Game Prototype**  
 * Develop the core foundations and software architecture of your networked game engine, delivering a first working prototype.
 * 
 * 2. **Part 2: Advanced Topics**  
 * Expand and enhance several aspects of the prototype. Explore topics in advanced software architecture, advanced networking, and advanced gameplay/game design.
 * 
 * ## R-Type, The Game
 * 
 * R-Type is a horizontal shoot-em-up (shmup) where players fight waves of enemies in space. Originally a popular game in the 90s, R-Type has seen numerous ports and remakes. In this project, you will create your own version of R-Type with additional requirements:
 * 
 * - The game MUST be networked, allowing multiple players to fight enemies.
 * - The internal design MUST demonstrate architectural features of a real game engine.
 * 
 * ## Project Organization
 * 
 * The project is divided into two parts, with each part leading to a delivery and an evaluation. The document is structured as follows:
 * 
 * ### Common Part: Software Engineering, Documentation, and Accessibility Requirements
 * - Focus on technical documentation, build system tooling, dependency management, development workflow, and packaging.
 * - Each defense evaluates the progress in these areas.
 * 
 * ### Part 1: Software Architecture & First Game Prototype
 * - Develop core foundations of the game engine.
 * - Deliver a working game prototype within 4 weeks.
 * 
 * ### Part 2: Advanced Topics
 * - Enhance different aspects of the prototype in areas of your choice (Advanced Software Architecture, Networking, Gameplay).
 * - Complete final delivery in 7 weeks.
 * 
 * ## Software Engineering Requirements
 * 
 * - **Build System**: CMake.
 * - **Package Manager**: Conan, Vcpkg, or CMake CPM for third-party dependencies.
 * - **Cross-Platform Support**: The game MUST run on both Linux and Windows with cross-play support.
 * - **Version Control**: Follow good Git practices, such as feature branches, merge requests, and tagging important milestones.
 * - **Continuous Integration (CI)**: While CI/CD setup is encouraged, don't put a dedicated member solely on this task.
 * - **Linters/Formatters**: Tools like `clang-tidy` or `clang-format` should be used.
 * 
 * ## Documentation Requirements
 * 
 * - **README**: A concise, practical README with project details, dependencies, build instructions, and licensing.
 * - **Developer Documentation**: High-level descriptions of architecture and systems, including architectural diagrams, system overviews, tutorials, and how-tos.
 * - **Protocol Documentation**: Network protocol descriptions for client-server communication.
 * - **Technical and Comparative Study**: Justify the technology choices, with comparisons on algorithms, data structures, storage, and security.
 * 
 * ## Accessibility Requirements
 * 
 * The project and its documentation should be accessible to people with disabilities. Consider:
 * - **Physical and Motor Disabilities**: Provide customizable input options.
 * - **Audio and Visual Disabilities**: Support for visual aids or alternative audio cues.
 * 
 * ## Gameplay
 * 
 * The client MUST display a scrolling star-field background. Players MUST control spaceships, fire missiles, and confront waves of enemies. Bydos slaves (enemies) and missiles must be part of the gameplay. The server MUST maintain authority over gameplay logic.
 * 
 * ## Advanced Topics (Part 2)
 * ### Track selected Advanced Networking
 * 
 * Implement multi-instance server management, data transmission efficiency (compression, UDP error handling), and real-time distributed simulation architecture. Address issues like lag and desynchronization.
 * 
 * @version 4.2-dev
 * @date 2024
 */

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

HeadServer Headserver;

void signalHandler(int signum) {
    try {
        // server.stop();  // Stop the server
        std::cout << "Interrupt signal (" << signum << ") received." << std::endl;
        exit(0); // Exit the program
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(1); // Exit the program with error
    }
}

int main() {
    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, signalHandler);

    try {
        Headserver.start();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
    Headserver.run();
    return 0;
}