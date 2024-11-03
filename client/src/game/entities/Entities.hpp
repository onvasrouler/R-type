/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** Entities
*/

#pragma once


#include <string>
#include <raylib.h>
#include <iostream>

class Entities {
public:
    Entities();
    virtual ~Entities() = default;

    void setPos(const Vector2 pos);
    void setPosX(const float x);
    void setPosY(const float y);
    void setRelativePosX(const float pos, const int windowWidth);
    void setRelativePosY(const float pos, const int windowHeight);
    void setSpeed(const Vector2 speed);
    void setSpeedX(const float x);
    void setSpeedY(const float y);
    void setHealth(const int health);
    void setDamage(const int damage);
    void setAlive(const bool alive);
    void setUUID(const std::string uuid);
    void setUsername(const std::string username);

    void setTexturePath(const std::string texture);
    void setImage(const Image image);
    void setTexture(const Texture2D texture);
    void setSize(const Vector2 size);
    void setScale(const float scale);
    void setRotation(const float rotation);

    void setId(const std::string id);

    void draw() const;

    Vector2 getPos() const;
    float getPosX() const;
    float getPosY() const;
    float getRelativePosX() const;
    float getRelativePosY() const;
    Vector2 getSpeed() const;
    float getSpeedX() const;
    float getSpeedY() const;
    int getHealth() const;
    int getDamage() const;
    bool getAlive() const;
    std::string getUsername() const;

    std::string getTexturePath() const;
    Image getImage() const;
    Texture2D getTexture() const;
    Vector2 getSize() const;
    float getScale() const;
    float getRotation() const;

    std::string getId() const;
    std::string getUUID() const;

    Entities(const Entities& other);
    Entities& operator=(const Entities& other);
private:
    Vector2 _Pos;
    Vector2 _Speed;
    int _Health;
    int _Damage;
    bool _Alive;
    std::string _TexturePath;
    Image _Image;
    Texture2D _Texture;
    Vector2 _Size;
    float _Scale;
    float _Rotation;
    std::string _Id;
    std::string _UUID;
    std::string _Username;
};
