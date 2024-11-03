/*
** EPITECH PROJECT, 2024
** R-type-2
** File description:
** Entities
*/

#include "Entities.hpp"

Entities::Entities()
{
}

void Entities::setPos(const Vector2 pos) {
    _Pos = pos;
}

void Entities::setPosX(const float x) {
    _Pos.x = x;
}

void Entities::setPosY(const float y) {
    _Pos.y = y;
}

void Entities::setRelativePosX(const float pos, const int windowWidth) {
    _Pos.x = (pos / 1920) * windowWidth;
}

void Entities::setRelativePosY(const float pos, const int windowHeight) {
    _Pos.y = (pos / 1080) * windowHeight;
}

void Entities::setSpeed(const Vector2 speed) {
    _Speed = speed;
}

void Entities::setSpeedX(const float x) {
    _Speed.x = x;
}

void Entities::setSpeedY(const float y) {
    _Speed.y = y;
}

void Entities::setHealth(const int health) {
    _Health = health;
}

void Entities::setDamage(const int damage) {
    _Damage = damage;
}

void Entities::setAlive(const bool alive) {
    _Alive = alive;
}

void Entities::setTexturePath(const std::string texture) {
    _TexturePath = texture;
}

void Entities::setImage(const Image image) {
    _Image = image;
}

void Entities::setTexture(const Texture2D texture) {
    _Texture = texture;
}

void Entities::setSize(const Vector2 size) {
    _Size = size;
}

void Entities::setScale(const float scale) {
    _Scale = scale;
}

void Entities::setRotation(const float rotation) {
    _Rotation = rotation;
}

void Entities::setId(const std::string id) {
    _Id = id;
}

void Entities::setUUID(const std::string uuid) {
    _UUID = uuid;
}

void Entities::setUsername(const std::string username) {
    _Username = username;
}

void Entities::draw() const {
    DrawTextureEx(_Texture, _Pos, 0, 1, WHITE);
}

Vector2 Entities::getPos() const {
    return _Pos;
}

float Entities::getPosX() const {
    return _Pos.x;
}

float Entities::getPosY() const {
    return _Pos.y;
}

float Entities::getRelativePosX() const {
    return _Pos.x / 1920;
}

float Entities::getRelativePosY() const {
    return _Pos.y / 1080;
}

Vector2 Entities::getSpeed() const {
    return _Speed;
}

float Entities::getSpeedX() const {
    return _Speed.x;
}

float Entities::getSpeedY() const {
    return _Speed.y;
}

int Entities::getHealth() const {
    return _Health;
}

int Entities::getDamage() const {
    return _Damage;
}

bool Entities::getAlive() const {
    return _Alive;
}

std::string Entities::getTexturePath() const {
    return _TexturePath;
}

Image Entities::getImage() const {
    return _Image;
}

Texture2D Entities::getTexture() const {
    return _Texture;
}

Vector2 Entities::getSize() const {
    return _Size;
}

float Entities::getScale() const {
    return _Scale;
}

float Entities::getRotation() const {
    return _Rotation;
}

std::string Entities::getId() const {
    return _Id;
}

std::string Entities::getUUID() const {
    return _UUID;
}

std::string Entities::getUsername() const {
    return _Username;
}

Entities::Entities(const Entities& other)
{
    _Pos = other._Pos;
    _Speed = other._Speed;
    _Health = other._Health;
    _Damage = other._Damage;
    _Alive = other._Alive;
    _TexturePath = other._TexturePath;
    _Image = other._Image;
    _Texture = other._Texture;
    _Size = other._Size;
    _Scale = other._Scale;
    _Rotation = other._Rotation;
    _Id = other._Id;
}

Entities& Entities::operator=(const Entities& other)
{
    _Pos = other._Pos;
    _Speed = other._Speed;
    _Health = other._Health;
    _Damage = other._Damage;
    _Alive = other._Alive;
    _TexturePath = other._TexturePath;
    _Image = other._Image;
    _Texture = other._Texture;
    _Size = other._Size;
    _Scale = other._Scale;
    _Rotation = other._Rotation;
    _Id = other._Id;
    return *this;
}