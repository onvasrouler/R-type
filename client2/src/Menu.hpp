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

    bool isClicked(sf::RectangleShape &shape, sf::Vector2i mousePos);

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

    std::map<sf::Keyboard::Key, char> keyMap = {
        {sf::Keyboard::Num0, '0'}, {sf::Keyboard::Num1, '1'}, {sf::Keyboard::Num2, '2'},
        {sf::Keyboard::Num3, '3'}, {sf::Keyboard::Num4, '4'}, {sf::Keyboard::Num5, '5'},
        {sf::Keyboard::Num6, '6'}, {sf::Keyboard::Num7, '7'}, {sf::Keyboard::Num8, '8'},
        {sf::Keyboard::Num9, '9'}, {sf::Keyboard::Semicolon, '.'}, {sf::Keyboard::Apostrophe, '4'}
    };
};
