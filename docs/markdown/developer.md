# Server Development Tool Documentation

This documentation outlines the structure and functionality of the `server_dev_tools` for the R-Type project. This tool provides the framework for creating and managing server modules.

---

## Directory Structure

### Root Directories

- `server_dev_tools/`
    - **modules/**: Contains custom modules, such as the `adminPanelModule`, and a module template for new modules.
    - **server/**: Includes configuration files and headers for server functionality.
    - **serverModules/**: Placeholder directory for compiled modules.
    - **source_code/**: Contains core source code files for server utilities, such as threading and unique ID generation.

---

## Modules Directory

### `modules/`
The `modules` directory contains submodules and templates for extending server functionality.

- `adminPanelModule/`: Module providing an administrative client connection and control panel.
    - **adminClient.hpp / .cpp**: Handles administrative client connections, including reading and sending messages.
    - **adminPanelModule.hpp / .cpp**: Manages the Admin Panel, including accepting connections and processing administrative commands.
- `template/`: Contains a basic template for creating new modules.
    - **ModuleTemplate.hpp / .cpp**: Provides a structure with common methods like `run()`, `stop()`, `encodeInterCommunication()`, and `decodeInterCommunication()`.

### `server/config/`
This directory contains core configuration files and utilities for server modules.

- **AbstractModule.hpp**: Base class for all modules, defining a shared interface.
- **MultiThread.hpp**: Handles multithreading support.
- **UUID.hpp**: Manages unique identifier generation for modules and clients.
- **modules.json**: JSON configuration file for listing and initializing modules.

### Platform-Specific Directories
- **server/config/unix/** and **server/config/windows/**: Platform-specific configuration files and utilities, including:
  - `generate` / `module`: Scripts and executable files for module generation.
  - `uuid`: Utility for generating unique identifiers for the adminPanel module example.
  - `moduleSourceCode.a` (Unix) / `windows.exe` (Windows): Precompiled binaries for module interaction.

### `source_code/`
Contains the core implementation files for threading, unique IDs, and abstract module structures. Key files include:
- **AbstractModule.cpp / .hpp**: Defines the base structure for all server modules.
- **MultiThread.cpp / .hpp**: Provides multithreading support.
- **UUID.cpp / .hpp**: Generates and manages UUIDs for unique client and module identification.

---

## Key Classes and Functions

### Module Template

The `ModuleTemplate` provides a base structure for developing new modules. It includes default methods to start, stop, and handle inter-module communication.

- **run()**: Starts the module's main operations.
- **stop()**: Stops the module's operations.
- **encodeInterCommunication() / decodeInterCommunication()**: Handles encoding and decoding messages between modules.

### Admin Panel Module Example

The `AdminPanelModule` allows for administrative interactions with the server. It sets up a TCP server to handle connections from admin clients, verifies login credentials, and provides real-time communication.

#### Key Methods
- **run()**: Initializes the TCP server, accepts connections, and handles administrative commands.
- **start_accept()**: Sets up asynchronous acceptance of new client connections.
- **handle_client()**: Processes incoming messages from clients, manages authentication, and executes commands.
- **sendMessageToClients()**: Sends formatted messages to connected clients.

### AdminClient

The `AdminClient` class represents a connected admin client, providing methods for managing client messages and states.

#### Key Methods
- **WriteTo()**: Sends messages to the client.
- **addMessage() / clearMessages()**: Manages client message history.
- **IsConnected() / IsLogged()**: Checks client connection and login status.
- **GetUUID()**: Returns the unique identifier for the client.

---

## Platform Compatibility

- **Windows**: Uses `CreateProcessW` to handle commands for administrative tools.
- **Unix**: Uses `popen()` to execute commands and handle networking tasks.

---

## Example Usage

### Admin Panel Setup
1. Initialize `AdminPanelModule` in your server's main function.
2. Start the module by calling `run()` to begin listening for admin connections.

### Module Creation
1. Use `ModuleTemplate.hpp` as a starting point for new modules.
2. Implement custom functionality in `run()`, `stop()`, and communication methods.

### Compilation
- **Unix**: Run `./compile.sh` in the root directory.
- **Windows**: Run `compile.bat` in the root directory.

---

## Notes

- Ensure all necessary configuration files (`modules.json`, `AbstractModule.hpp`, etc.) are present for proper module loading.
- The Admin Panel relies on Boost Asio for asynchronous networking and requires Boost library setup on your system.
- Each module uses a UUID for unique identification, managed by the `UUID` utility in `source_code/`.

---

This server development tool provides a modular framework for server administration and control, enabling extensible functionality and easy management of server processes.
