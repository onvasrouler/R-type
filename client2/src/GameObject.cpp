/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** game object
*/

#include "GameObject.hpp"
#include <iostream>

GameObject::GameObject(int x, int y, enum Type type)
{
    if (type == ENEMY) {
        Texture.loadFromFile("chipset/enemy.png");
    } else if (type == PLAYER) {
        Texture.loadFromFile("chipset/player.png");
    } else {
        Texture.loadFromFile("chipset/bullet.png");
    }

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
