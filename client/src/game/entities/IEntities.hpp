/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** IEntities
*/

#pragma once

#include <raylib.h>
#include <string>

class IEntities {
public:
    virtual ~IEntities() = default;

    virtual void setPos(const Vector2 pos) = 0;
    virtual void setPosX(const float x) = 0;
    virtual void setPosY(const float y) = 0;
    virtual void setSpeed(const Vector2 speed) = 0;
    virtual void setSpeedX(const float x) = 0;
    virtual void setSpeedY(const float y) = 0;
    virtual void setHealth(const int health) = 0;
    virtual void setDamage(const int damage) = 0;
    virtual void setAlive(const bool alive) = 0;

    virtual void setTexture(const std::string texture) = 0;
    virtual void setSize(const Vector2 size) = 0;
    virtual void setScale(const float scale) = 0;
    virtual void setRotation(const float rotation) = 0;

    virtual void draw() const = 0;

    virtual Vector2 getPos() const = 0;
    virtual float getPosX() const = 0;
    virtual float getPosY() const = 0;
    virtual Vector2 getSpeed() const = 0;
    virtual float getSpeedX() const = 0;
    virtual float getSpeedY() const = 0;
    virtual int getHealth() const = 0;
    virtual int getDamage() const = 0;
    virtual bool getAlive() const = 0;

    virtual Vector2 getSize() const = 0;
    virtual float getScale() const = 0;
    virtual float getRotation() const = 0;
};
