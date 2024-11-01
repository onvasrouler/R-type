/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** AEntities
*/

#pragma once

#include "IEntities.hpp"
#include <raylib.h>

class AEntities : public IEntities {
public:
    AEntities();
    virtual ~AEntities() = default;

    void setPos(const Vector2 pos) override;
    void setPosX(const float x) override;
    void setPosY(const float y) override;
    void setSpeed(const Vector2 speed) override;
    void setSpeedX(const float x) override;
    void setSpeedY(const float y) override;
    void setHealth(const int health) override;
    void setDamage(const int damage) override;
    void setAlive(const bool alive) override;

    void setTexturePath(const std::string texture) override;
    void setTexture(const Texture2D texture) override;
    void setSize(const Vector2 size) override;
    void setScale(const float scale) override;
    void setRotation(const float rotation) override;

    void setId(const std::string id) override;

    void draw() const override;

    Vector2 getPos() const override;
    float getPosX() const override;
    float getPosY() const override;
    Vector2 getSpeed() const override;
    float getSpeedX() const override;
    float getSpeedY() const override;
    int getHealth() const override;
    int getDamage() const override;
    bool getAlive() const override;

    std::string getTexturePath() const override;
    Texture2D getTexture() const override;
    Vector2 getSize() const override;
    float getScale() const override;
    float getRotation() const override;

    std::string getId() const override;
protected:
    Vector2 _Pos;
    Vector2 _Speed;
    int _Health;
    int _Damage;
    bool _Alive;
    std::string _TexturePath;
    Texture2D _Texture;
    Vector2 _Size;
    float _Scale;
    float _Rotation;
    std::string _Id;
};
