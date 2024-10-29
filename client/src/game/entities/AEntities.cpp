/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** AEntities
*/

#include "AEntities.hpp"

AEntities::AEntities()
{
}

void AEntities::setPos(const Vector2 pos) {
    _Pos = pos;
}

void AEntities::setPosX(const float x) {
    _Pos.x = x;
}

void AEntities::setPosY(const float y) {
    _Pos.y = y;
}

void AEntities::setSpeed(const Vector2 speed) {
    _Speed = speed;
}

void AEntities::setSpeedX(const float x) {
    _Speed.x = x;
}

void AEntities::setSpeedY(const float y) {
    _Speed.y = y;
}

void AEntities::setHealth(const int health) {
    _Health = health;
}

void AEntities::setDamage(const int damage) {
    _Damage = damage;
}

void AEntities::setAlive(const bool alive) {
    _Alive = alive;
}

void AEntities::setTexturePath(const std::string texture) {
    _TexturePath = texture;
}

void AEntities::setTexture(const Texture2D texture) {
    _Texture = texture;
}

void AEntities::setSize(const Vector2 size) {
    _Size = size;
}

void AEntities::setScale(const float scale) {
    _Scale = scale;
}

void AEntities::setRotation(const float rotation) {
    _Rotation = rotation;
}

void AEntities::setId(const std::string id) {
    _Id = id;
}

void AEntities::draw() const {
    // Drawing logic here
}

Vector2 AEntities::getPos() const {
    return _Pos;
}

float AEntities::getPosX() const {
    return _Pos.x;
}

float AEntities::getPosY() const {
    return _Pos.y;
}

Vector2 AEntities::getSpeed() const {
    return _Speed;
}

float AEntities::getSpeedX() const {
    return _Speed.x;
}

float AEntities::getSpeedY() const {
    return _Speed.y;
}

int AEntities::getHealth() const {
    return _Health;
}

int AEntities::getDamage() const {
    return _Damage;
}

bool AEntities::getAlive() const {
    return _Alive;
}

std::string AEntities::getTexturePath() const {
    return _TexturePath;
}

Texture2D AEntities::getTexture() const {
    return _Texture;
}

Vector2 AEntities::getSize() const {
    return _Size;
}

float AEntities::getScale() const {
    return _Scale;
}

float AEntities::getRotation() const {
    return _Rotation;
}

std::string AEntities::getId() const {
    return _Id;
}