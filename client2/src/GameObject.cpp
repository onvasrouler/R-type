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

    for (unsigned int i = 0; i < 100; ++i) {
        for (unsigned int u = 0; u < 100; +u) {
            unsigned int originalX = u * originalImage.getSize().x / 100;
            unsigned int originalY = i * originalImage.getSize().y / 100;

            resizedImage.setPixel(u, i, originalImage.getPixel(originalX, originalY));
        }
    }

    Texture.loadFromImage(resizedImage);
    Sprite.setTexture(Texture);

    Sprite.setPosition(sf::Vector2f(x, y));
}

GameObject::~GameObject()
{

}

void GameObject::setPosition(int x, int y)
{
    Sprite.setPosition(sf::Vector2f(x, y));
}
