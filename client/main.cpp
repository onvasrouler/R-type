/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** main
*/

#include <iostream>
#include <raylib.h>
#include <string>
#include <memory>
#include <nlohmann/json.hpp>
#include "src/raylibWindow/raylibWindow.hpp"
#include "src/raylibText/raylibText.hpp"
#include "src/fpsCounter/fpsCounter.hpp"

int main() {
    // Create a Raylib window
    RlibWindow window("window_settings.json");
    window.InitRlib();
    
    // Create a FpsCounter
    std::unique_ptr<FpsCounter> rlibFpsCounter = std::make_unique<FpsCounter>(100, 0, 30, BLACK);
    RaylibText text("Hello, Raylib!", 200, 0, 30, BLACK);
    window.setFpsCounter(std::move(rlibFpsCounter));
    // Main game loop
    while (!window.ShouldClose()) {
        window.ClearRlibBackground();
        window.BeginRlibDraw();
        text.DrawRlibText();
        window.EndRlibDraw();
    }
    return 0;
}