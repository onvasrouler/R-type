// components.hpp
#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <SFML/Graphics.hpp>

struct Position {
    float x, y;
};

struct Velocity {
    float vx, vy;
};

struct Drawable {
    sf::CircleShape shape;

    Drawable(sf::Color color = sf::Color::Green) {
        shape.setRadius(10);
        shape.setFillColor(color);
    }

    void draw(sf::RenderWindow& window, float x, float y) {
        shape.setPosition(x, y);
        window.draw(shape);
    }
};

struct Controllable {
    // Implementation details for controllable component
};

struct Acceleration {
    float ax, ay;
};

struct Missile {
    // Implementation details for missile component
};

struct Target {
    // Implementation details for target component
};

#endif // COMPONENTS_HPP