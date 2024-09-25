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
    // Create a Raylib window
    RlibWindow window("./config/window_settings.json");
    window.InitRlib();
    
    // Create a FpsCounter
    std::unique_ptr<FpsCounter> rlibFpsCounter = std::make_unique<FpsCounter>(Vector2{100, 0}, 30, BLACK);
    window.setFpsCounter(std::move(rlibFpsCounter));
    // Main game loop
    while (!window.ShouldClose()) {
        window.ClearRlibBackground();
        window.BeginRlibDraw();
        window.EndRlibDraw();
    }
    return 0;
}