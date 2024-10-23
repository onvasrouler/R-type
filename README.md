# R-TYPE: A GAME ENGINE THAT ROARS!

## Overview
The **R-Type** project is a networked, multi-threaded video game engine and graphical client developed in C++ for the classic horizontal shoot 'em up game, R-Type. This project showcases advanced development techniques in game engine architecture, networking, and software engineering. The goal is to build a multiplayer version of R-Type while implementing robust, reusable game engine features.


<img src="https://i.ytimg.com/vi/0psrSHNu6wM/hq720.jpg?sqp=-oaymwE7CK4FEIIDSFryq4qpAy0IARUAAAAAGAElAADIQj0AgKJD8AEB-AH-CYAC0AWKAgwIABABGFMgXShlMA8=&rs=AOn4CLDwXkF0Zr6bRlc6WDdeW-eS3DM0gA">

## Key Features
- **Language**: C++
- **Build System**: CMake
- **Package Manager**: Vcpkg
- **Multiplayer Support**: Multiple players can fight in real-time, connected through a central server.
- **Cross-Platform**: Runs on both Linux and Windows (cross-play enabled).
- **Advanced Game Engine**: Demonstrates the design of subsystems like rendering, physics, audio, and networking.
- **Real-time Networking**: Utilizes UDP for in-game communications, ensuring fast-paced, responsive gameplay.
- **Multithreading**: Server handles multiple game instances, ensuring smooth gameplay and efficient resource management.

## Game Design
- **Classic R-Type Gameplay**: Players control spaceships, navigate through obstacles, and fight waves of enemies.
- **Enemy & Player Interaction**: Includes Bydos enemies, power-ups, missiles, and unique monster behaviors.
- **Networking Architecture**: Server is authoritative, handling game logic and updating clients in real-time. Clients focus on rendering and input handling.
- **Protocol**: A custom binary protocol is designed for efficient data transmission between client and server.

## Project Structure
1. **Part 1: Core Architecture & Game Prototype**
   - Develop core engine systems and deliver a working multiplayer prototype.
   - Deadline: 4 weeks from project start.

2. **Part 2: Advanced Features**
   - Expand on the prototype by implementing advanced topics like improved engine architecture, enhanced networking, and gameplay features.
   - Deadline: 7 weeks from project start.

## Advanced Features
- **Game Engine Modularity**: Easily extendable and decoupled systems for rendering, audio, physics, and more.
- **High-Level Networking**: Features client-side prediction, lag compensation, and efficient data transmission.
- **Gameplay Expansion**: New levels, bosses, and weapon systems, including a star-field background, monster waves, and unique player abilities.

## Documentation & Development Workflow
- **README**: Includes project setup, build instructions, and supported platforms.
- **Doxygen**: Auto-generated documentation and protocol specifications for developers.
- **Git Workflow**: Branches, merge requests, and tags are used for efficient project management.
- **Accessibility**: Thoughtful consideration for accessibility, including support for players with disabilities.

## Getting Started
1. Clone the repository and follow the build instructions using CMake and Vcpkg.
2. Run `make doc` in order to follow the installer guild and get more informations about the project

# Author
Quentin Tennerel
Julien Renard
Aimeric Rouyer
Maxence Perronie
Antoine Gonthier

## License
Open-source under [insert license].