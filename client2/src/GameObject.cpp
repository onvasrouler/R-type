/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** game object
*/

#include "GameObject.hpp"

GameObject::GameObject(int x, int y, enum Type type)
{
    sf::Image originalImage;

    if (type == ENEMY) {
        originalImage.loadFromFile("chipset/player.png");
    } else if (type == PLAYER) {
        originalImage.loadFromFile("chipset/player.png");
    } else {
        originalImage.loadFromFile("chipset/player.png");
    }

    sf::Image resizedImage;
    resizedImage.create(100, 100);

    for (unsigned int y = 0; y < 100; ++y) {
        for (unsigned int x = 0; x < 100; ++x) {
            unsigned int originalX = x * originalImage.getSize().x / 100;
            unsigned int originalY = y * originalImage.getSize().y / 100;

            resizedImage.setPixel(x, y, originalImage.getPixel(originalX, originalY));
        }
    }

    Texture.loadFromImage(resizedImage);
    Sprite.setTexture(Texture);
}

GameObject::~GameObject()
{

}

void GameObject::setPosition(int x, int y)
{
    Sprite.setPosition(sf::Vector2f(x, y));
}
