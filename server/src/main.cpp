#include "registry.hpp"
#include "components.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "system.hpp"

int main() {
    Registry registry;

    // Enregistrer les composants
    registry.register_component<Position>();
    registry.register_component<Velocity>();
    registry.register_component<Drawable>();
    registry.register_component<Controllable>();
    registry.register_component<Missile>();
    registry.register_component<Target>();

    // Créer une entité mobile avec tous les composants
    auto entity = registry.create_entity();
    registry.add_component(entity, Position{400.0f, 300.0f});
    registry.add_component(entity, Velocity{0.0f, 0.0f});
    registry.add_component(entity, Drawable(sf::Color::Red));
    registry.add_component(entity, Controllable{});

    // Créer des entités statiques avec des composants de position et de dessin
    for (int i = 0; i < 5; ++i) {
        auto static_entity = registry.create_entity();
        registry.add_component(static_entity, Position{50.0f * i, 50.0f * i});
        registry.add_component(static_entity, Drawable{});
        registry.add_component(static_entity, Target{});
    }

    sf::RenderWindow window(sf::VideoMode(1800, 800), "ECS Example");

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float delta_time = clock.restart().asSeconds();

        control_system(registry, registry.get_component_array<Controllable>(), registry.get_component_array<Velocity>(), sf::Keyboard());
        position_system(registry, registry.get_component_array<Position>(), registry.get_component_array<Velocity>());
        missile_system(registry, registry.get_component_array<Controllable>(), registry.get_component_array<Position>(), registry.get_component_array<Missile>());
        collision_system(registry, registry.get_component_array<Missile>(), registry.get_component_array<Position>(), registry.get_component_array<Target>(), registry.get_component_array<Position>());

        window.clear();
        draw_system(registry, registry.get_component_array<Drawable>(), registry.get_component_array<Position>(), window);
        window.display();

        logging_system(registry, registry.get_component_array<Position>(), registry.get_component_array<Velocity>());
    }

    return 0;
}