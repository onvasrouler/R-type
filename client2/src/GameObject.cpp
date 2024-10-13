/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** game object
*/

#include "GameObject.hpp"
#include <iostream>

GameObject::GameObject(int x, int y, enum Type type, sf::Texture &text)
{
    Sprite.setTexture(text);

    Sprite.setPosition(sf::Vector2f(x, y));
}

GameObject::~GameObject()
{

}

void GameObject::setPosition(int x, int y)
{
    Sprite.setPosition(sf::Vector2f(x, y));
}
