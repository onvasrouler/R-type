# R-Type Protocol Documentation

This document provides an overview of the R-Type protocol used for communication between the server, game modules, and clients. The protocol handles player creation, input handling, and entity (player, enemy, bullet) state updates during the game.

## Table of Contents

1. [Introduction](#introduction)
2. [Protocol Overview](#protocol-overview)
3. [New Player Protocol](#new-player-protocol)
4. [Input Handling](#input-handling)
5. [Data Updates](#data-updates)
    - [Player Data](#player-data)
    - [Enemy Data](#enemy-data)
    - [Bullet Data](#bullet-data)
6. [Code Integration](#code-integration)

## Introduction

The **R-Type Protocol** facilitates the real-time interaction between game clients and the server. It handles the following actions:
- Player spawning and validation
- Handling player inputs such as movement
- Updating the game state with player, enemy, and bullet information
- Broadcasting these updates to all clients

## Protocol Overview

The protocol is built on a simple message-based system using **POST** and **GET** requests. Each type of message has a unique code to signify its purpose, making the communication between clients and server efficient and clear.

### 0. New Player
- **POST 0**: Client sends a request to spawn a new player.
- **GET 1**: Server validates the new player creation and sends back the player ID.

### 1. Input
- **POST 0**: Client sends input data (e.g., movement commands) to the server.

### 2. Data
- **Player**
  - **GET 0**: Player spawned with `id/type/level/hp`.
  - **GET 1**: Player received damage `id/value`.
  - **GET 2**: Player position update `id/x-y`.
  - **GET 3**: Player death notification `id`.

- **Enemy**
  - **GET 0**: Enemy spawned with `id/type/level/hp`.
  - **GET 1**: Enemy received damage `id/value`.
  - **GET 2**: Enemy position update `id/x-y`.
  - **GET 3**: Enemy death notification `id`.

- **Bullet**
  - **GET 0**: Bullet spawned with `id/type`.
  - **GET 1**: Bullet position update `id/x-y`.
  - **GET 2**: Bullet death notification `id`.

## New Player Protocol

When a new player joins the game, the client sends a **POST** request to the server to request the player’s creation.

### Request (POST)
POST 0 socket (spawn request)
The server responds with a GET message, validating the player’s creation.

### Response (GET)
GET 1 socket/id (spawn validation)
The player receives an id and other relevant information such as type, level, and health points (hp).

### Input Handling
Input handling is done via a POST request where clients send their actions (e.g., movement, shooting) to the server.


### Input Request (POST)
POST 0 code input (ASCII)

## Data Updates

The server broadcasts game updates to all clients in the form of **GET** requests. These updates can include the state of players, enemies, and bullets. Below are the specific data structures for each entity.

### Player Data

1. **Spawn Player**
    - **GET 0**: `id/type/level/hp`
    ```plaintext
    GET 0 id/type/level/hp (spawn)
    ```

2. **Player Damage**
    - **GET 1**: `id/value`
    ```plaintext
    GET 1 id/value (damage)
    ```

3. **Player Position**
    - **GET 2**: `id/x-y`
    ```plaintext
    GET 2 id/x-y (position)
    ```

4. **Player Death**
    - **GET 3**: `id`
    ```plaintext
    GET 3 id (death)
    ```

### Enemy Data

1. **Spawn Enemy**
    - **GET 0**: `id/type/level/hp`
    ```plaintext
    GET 0 id/type/level/hp (spawn)
    ```

2. **Enemy Damage**
    - **GET 1**: `id/value`
    ```plaintext
    GET 1 id/value (damage)
    ```

3. **Enemy Position**
    - **GET 2**: `id/x-y`
    ```plaintext
    GET 2 id/x-y (position)
    ```

4. **Enemy Death**
    - **GET 3**: `id`
    ```plaintext
    GET 3 id (death)
    ```

### Bullet Data

1. **Spawn Bullet**
    - **GET 0**: `id/type`
    ```plaintext
    GET 0 id/type (spawn)
    ```

2. **Bullet Position**
    - **GET 1**: `id/x-y`
    ```plaintext
    GET 1 id/x-y (position)
    ```

3. **Bullet Death**
    - **GET 2**: `id`
    ```plaintext
    GET 2 id (death)
    ```

## Code Integration

Here’s an example of how the protocol integrates with the game code, specifically when handling player creation and game state updates.

### Example: Player Creation

In the game server, when a new player is created, the following message is constructed and sent to other players:

```cpp
bool Game::create_player(const std::string id) {
    if (_player.size() < 4) {
        Player player(500, id);
        _player.push_back(player);
        std::string message = PLAYER_SPAWN_CODE + std::string("/") + 
            player.get_id() + std::string("/") + 
            std::to_string(player.get_type()) + std::string("/") + 
            std::to_string(player.get_level()) + std::string("/") + 
            std::to_string(player.get_hp()) + std::string("/") + 
            std::to_string(player.get_x()) + std::string("/") + 
            std::to_string(player.get_y()) + END_MESSAGE_CODE;
        _sendMessages.push_back(gameMessage(player.get_id(), message));
        return true;
    }
    return false;
}
```
This message follows the protocol structure for player spawning and is broadcasted to all connected clients.

### Example: Bullet Position Update

As bullets move, the server sends position updates to all clients using the following message structure:

```cpp
void Game::update_world() {
    for (auto& bullet : _bullet) {
        bullet.move();
        std::string message = BULLET_POSITION_CODE + std::string("/") + 
            bullet.get_id() + std::string("/") + 
            std::to_string(bullet.get_x()) + std::string("/") + 
            std::to_string(bullet.get_y()) + END_MESSAGE_CODE;
        _sendMessages.push_back(gameMessage(player.get_id(), message));
    }
}
```

### Conclusion

The R-Type protocol provides a clear and efficient communication framework between clients and the server. By adhering to the structured POST and GET requests, it ensures real-time synchronization of game state across multiple clients, allowing for smooth multiplayer gameplay.
