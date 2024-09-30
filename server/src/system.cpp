#include "system.hpp"

void position_system(Registry& r, sparse_array<Position>& positions, sparse_array<Velocity>& velocities) {
    (void)r;
    const float window_width = 1800.0f;
    const float window_height = 800.0f;

    for (size_t i = 0; i < positions.size() && i < velocities.size(); ++i) {
        if (positions[i] && velocities[i]) {
            positions[i]->x += velocities[i]->vx;
            positions[i]->y += velocities[i]->vy;

            if (positions[i]->x < 0.0f) {
                positions[i]->x = 0.0f;
            } else if (positions[i]->x > window_width) {
                positions[i]->x = window_width;
            }

            if (positions[i]->y < 0.0f) {
                positions[i]->y = 0.0f;
            } else if (positions[i]->y > window_height) {
                positions[i]->y = window_height;
            }
        }
    }
}

void control_system(Registry& r, sparse_array<Controllable>& controllables, sparse_array<Velocity>& velocities, const sf::Keyboard& keyboard) {
    const float window_width = 400.0f;
    const float window_height = 400.0f;
    const float speed = 1.0f;

    for (size_t i = 0; i < controllables.size() && i < velocities.size(); ++i) {
        if (controllables[i] && velocities[i]) {
            if (keyboard.isKeyPressed(sf::Keyboard::Left)) {
                velocities[i]->vx = -speed;
            } else if (keyboard.isKeyPressed(sf::Keyboard::Right)) {
                velocities[i]->vx = speed;
            } else {
                velocities[i]->vx = 0.0f;
            }

            if (keyboard.isKeyPressed(sf::Keyboard::Up)) {
                velocities[i]->vy = -speed;
            } else if (keyboard.isKeyPressed(sf::Keyboard::Down)) {
                velocities[i]->vy = speed;
            } else {
                velocities[i]->vy = 0.0f;
            }
        }
    }
}


void draw_system(Registry& r, sparse_array<Drawable>& drawables, sparse_array<Position>& positions, sf::RenderWindow& window) {
    (void)r;
    for (size_t i = 0; i < drawables.size() && i < positions.size(); ++i) {
        if (drawables[i] && positions[i]) {
            drawables[i]->draw(window, positions[i]->x, positions[i]->y);
        }
    }
}

void logging_system(Registry& r, const sparse_array<Position>& positions, const sparse_array<Velocity>& velocities) {
    for (auto&& [i, pos, vel] : indexed_zipper(positions, velocities)) {
        std::cerr << i << " : Position = { " << pos.value().x << " , " << pos.value().y
                  << " } , Velocity = { " << vel.value().vx << " , " << vel.value().vy << " } " << std::endl;
    }
}

void missile_system(Registry& registry, sparse_array<Controllable>& controllables, sparse_array<Position>& positions, sparse_array<Missile>& missiles) {
    (void)missiles; // Indiquer que le paramètre n'est pas utilisé
    for (size_t i = 0; i < controllables.size(); ++i) {
        if (controllables[i] && positions[i]) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                auto missile = registry.create_entity();
                registry.add_component(missile, Position{positions[i]->x, positions[i]->y});
                registry.add_component(missile, Velocity{0.0f, -300.0f}); // Vitesse du missile
                registry.add_component(missile, Drawable(sf::Color::Red));
                registry.add_component(missile, Missile{});
                std::cout << "Missile created at position (" << positions[i]->x << ", " << positions[i]->y << ")\n";
            }
        }
    }
}

void collision_system(Registry& registry, sparse_array<Missile>& missiles, sparse_array<Position>& missile_positions, sparse_array<Target>& targets, sparse_array<Position>& target_positions) {
    // for (size_t i = 0; i < missiles.size(); ++i) {
    //     if (missiles[i] && missile_positions[i]) {
    //         for (size_t j = 0; j < targets.size(); ++j) {
    //             if (targets[j] && target_positions[j]) {
    //                 float dx = missile_positions[i]->x - target_positions[j]->x;
    //                 float dy = missile_positions[i]->y - target_positions[j]->y;
    //                 float distance = std::sqrt(dx * dx + dy * dy);

    //                 if (distance < 10.0f) { // Si le missile touche la cible
    //                     std::cout << "Collision detected between missile at (" << missile_positions[i]->x << ", " << missile_positions[i]->y << ") and target at (" << target_positions[j]->x << ", " << target_positions[j]->y << ")\n";
    //                     registry.destroy_entity(targets[j].entity_id); // Détruire la cible
    //                     registry.destroy_entity(missiles[i].entity_id); // Détruire le missile
    //                 }
    //             }
    //         }
    //     }
    // }
}