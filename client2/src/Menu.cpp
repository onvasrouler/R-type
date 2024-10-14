/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** menu
*/

#include "Menu.hpp"
#include <iostream>

Menu::Menu() : window(sf::VideoMode::getDesktopMode(), "RTYPE", sf::Style::Fullscreen)
{
    if (!backgroundTexture.loadFromFile("chipset/background.jpg"))
        throw std::runtime_error("Impossible de charger l'image de fond.");
    backgroundSprite.setTexture(backgroundTexture);

    if (!font.loadFromFile("chipset/arial.ttf"))
        throw std::runtime_error("Impossible de charger la police.");

    sf::RectangleShape startOption(sf::Vector2f(200, 50));
    startOption.setFillColor(sf::Color::White);
    startOption.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 - 30);
    menuOptions[START] = startOption;

    sf::Text startText("Start", font, 30);
    startText.setFillColor(sf::Color::Black);
    startText.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2 - 20);
    menuTexts[START] = startText;

    sf::RectangleShape quitOption(sf::Vector2f(200, 50));
    quitOption.setFillColor(sf::Color::White);
    quitOption.setPosition(window.getSize().x - 210, 30);
    menuOptions[QUIT] = quitOption;

    sf::Text quitText("Quit", font, 30);
    quitText.setFillColor(sf::Color::Black);
    quitText.setPosition(window.getSize().x - 200, 40);
    menuTexts[QUIT] = quitText;

    sf::RectangleShape ipOption(sf::Vector2f(300, 50));
    ipOption.setFillColor(sf::Color::White);
    ipOption.setPosition(window.getSize().x / 2 - 150, window.getSize().y / 2 - 100);
    menuOptions[IP] = ipOption;

    ip = "Enter Ip";
    isTypingIp = false;

    sf::Text ipText(ip, font, 30);
    ipText.setFillColor(sf::Color::Black);
    ipText.setPosition(window.getSize().x / 2 - 130, window.getSize().y / 2 - 100);
    menuTexts[IP] = ipText;

    sf::RectangleShape portOption(sf::Vector2f(80, 50));
    portOption.setFillColor(sf::Color::White);
    portOption.setPosition(window.getSize().x / 2 + 180, window.getSize().y / 2 - 100);
    menuOptions[PORT] = portOption;

    port = "Port";
    isTypingPort = false;

    sf::Text portText(ip, font, 30);
    portText.setFillColor(sf::Color::Black);
    portText.setPosition(window.getSize().x / 2 + 180, window.getSize().y / 2 - 100);
    menuTexts[PORT] = portText;

    Game game;
}

void Menu::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

bool Menu::isClicked(sf::RectangleShape &shape, sf::Vector2i mousePos) {
    sf::FloatRect rect = shape.getGlobalBounds();
    if (rect.contains(mousePos.x, mousePos.y))
        return true;
    return false;
}

void Menu::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (isClicked(menuOptions[QUIT], mousePos))
                    window.close();

                if (isClicked(menuOptions[START], mousePos))
                   tryToConnect();

                isTypingIp = isClicked(menuOptions[IP], mousePos);
                isTypingPort = isClicked(menuOptions[PORT], mousePos);
            }
        }

        if (event.type == sf::Event::KeyPressed && isTypingIp == true) {
            if ((event.key.code >= sf::Keyboard::Num0 && event.key.code <= sf::Keyboard::Num9) || event.key.code == sf::Keyboard::Semicolon || event.key.code == sf::Keyboard::BackSpace || event.key.code == sf::Keyboard::Apostrophe) {
                if (ip.compare("Enter Ip") == 0)
                    ip.clear();
                if (event.key.code == sf::Keyboard::BackSpace && ip.length() != 0)
                    ip.pop_back();
                else if (ip.length() < 15){
                    std::cout << "event key code is " << event.key.code << std::endl;
                    if (keyMap.find(event.key.code) != keyMap.end())
                        ip += keyMap[event.key.code];
                        }
            }
        }

        if (event.type == sf::Event::KeyPressed && isTypingPort == true) {
            std::cout << "event key code is " << event.key.code << std::endl;
            if ((event.key.code >= sf::Keyboard::Num0 && event.key.code <= sf::Keyboard::Num9) || event.key.code == sf::Keyboard::BackSpace || event.key.code == sf::Keyboard::Semicolon || event.key.code == sf::Keyboard::Apostrophe) {
                if (port.compare("Port") == 0)
                    port.clear();
                if (event.key.code == sf::Keyboard::BackSpace && port.length() != 0)
                    port.pop_back();
                else if (port.length() < 5)
                    if (keyMap.find(event.key.code) != keyMap.end())
                        port += keyMap[event.key.code];
            }
        }
    }
}

void Menu::update() {
}

void Menu::render() {
    window.clear();
    
    window.draw(backgroundSprite);

    window.draw(menuOptions[QUIT]);
    window.draw(menuTexts[QUIT]);
    window.draw(menuOptions[START]);
    window.draw(menuTexts[START]);

    menuTexts[IP].setString(ip);
    window.draw(menuOptions[IP]);
    window.draw(menuTexts[IP]);

    menuTexts[PORT].setString(port);
    window.draw(menuOptions[PORT]);
    window.draw(menuTexts[PORT]);

    window.display();
}

void Menu::tryToConnect() {
    try {
        boost::asio::io_context io_context;

        udp::socket socket(io_context);
        socket.open(udp::v4());

        udp::resolver resolver(io_context);
        udp::resolver::results_type endpoints = resolver.resolve(udp::v4(), ip, port);

        game.run(window, io_context, endpoints);

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}