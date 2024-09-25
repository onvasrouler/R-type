/*
** EPITECH PROJECT, 2024
** B-CPP-500-NAN-5-1-bsrtype-maxence.perronie
** File description:
** system
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "registry.hpp"
#include "components.hpp"
#include "indexed_zipper.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

void position_system(Registry& r, sparse_array<Position>& positions, sparse_array<Velocity>& velocities);
void control_system(Registry& r, sparse_array<Controllable>& controllables, sparse_array<Velocity>& velocities, const sf::Keyboard& keyboard);
void draw_system(Registry& r, sparse_array<Drawable>& drawables, sparse_array<Position>& positions, sf::RenderWindow& window);
void logging_system(Registry& r, const sparse_array<Position>& positions, const sparse_array<Velocity>& velocities);
void missile_system(Registry& registry, sparse_array<Controllable>& controllables, sparse_array<Position>& positions, sparse_array<Missile>& missiles);
void collision_system(Registry& registry, sparse_array<Missile>& missiles, sparse_array<Position>& missile_positions, sparse_array<Target>& targets, sparse_array<Position>& target_positions);

#endif /* !SYSTEM_HPP_ */
