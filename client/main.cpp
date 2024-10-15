/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** main
*/

#include "src/raylibWindow/raylibWindow.hpp"
#include "src/fpsCounter/fpsCounter.hpp"
#include "src/include.hpp"

int main() {
    if (!HealthCheck())
        return 84;
    // Create a Raylib window
    RlibWindow window("./config/window_settings.json");
    window.InitRlib();
    
    // Main game loop
    while (!window.ShouldClose())
        window.update();
    return 0;
}