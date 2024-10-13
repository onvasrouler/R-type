/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** game object
*/

#include <SFML/Graphics.hpp>

enum Type {
    ENEMY,
    BULLET,
    PLAYER
};

class GameObject
{
public:
    GameObject(int x, int y, enum Type type);
    ~GameObject();

    void setPosition(int x, int y);

    sf::Texture Texture;
    sf::Sprite Sprite;
};
