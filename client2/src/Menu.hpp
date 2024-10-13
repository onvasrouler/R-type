/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** menu
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include <map>
#include <array>
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::udp;

enum menuType {
    START,
    QUIT,
    IP,
    PORT
};

class Menu {
public:
    Menu();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void tryToConnect();

    sf::RenderWindow window;
    std::map<enum menuType, sf::RectangleShape> menuOptions;
    std::map<enum menuType, sf::Text> menuTexts;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    std::string ip;
    bool isTypingIp;

    std::string port;
    bool isTypingPort;

    Game game;

    sf::Font font;
};
