/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** install
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <thread>
#include <fstream>
#include <string>
#include "assets/elements/text/textManager.hpp"
#include "assets/elements/progressBar/progressBar.hpp"
#include "assets/elements/button/button.hpp"

/**
 * @class Installer
 * @brief Manages the installation process of the R-type project.
 *
 * The Installer class handles the user interaction and progress tracking
 * for the installation process. It provides methods to run the installation,
 * handle user input, and update the progress.
 *
 *  @details
 * The Installer class provides methods to start the installation process,
 * handle user input events, and update the installation progress. It also
 * manages the rendering of text and progress bar updates.
 *
 * @note This class uses SFML for rendering and event handling.
 *
 * @var sf::RenderWindow Installer::window
 * The window used for rendering the installation interface.
 *
 * @var TextManager Installer::textManager
 * Manages the text elements displayed during the installation.
 *
 * @var sf::Text Installer::confirmText
 * Text displayed to confirm the start of the installation.
 *
 * @var sf::Text Installer::progressText
 * Text displaying the current progress of the installation.
 *
 * @var sf::Text Installer::completeText
 * Text displayed when the installation is complete.
 *
 * @var ProgressBar Installer::progressBar
 * Visual representation of the installation progress.
 *
 * @var bool Installer::installationStarted
 * Indicates whether the installation process has started.
 *
 * @var bool Installer::installationComplete
 * Indicates whether the installation process is complete.
 *
 * @var bool Installer::waitingForConfirmation
 * Indicates whether the installer is waiting for user confirmation to start.
 *
 * @var float Installer::progress
 * The current progress of the installation as a percentage.
 *
 * @var float Installer::threadProcess
 * The progress of the installation process handled by a separate thread.
 */
class Installer
{
public:
    /**
     * @brief Constructs a new Installer object.
     */
    Installer();

    /**
     * @brief Starts the installation process.
     */
    void run();

    /**
     * @brief Handles user input events.
     *
     * @param event The SFML event to process.
     */
    void askUser(sf::Event event);

    /**
     * @brief Main loop to update the installation progress.
     */
    void progressLoop();

    /**
     * @brief Waits for the user to confirm an action.
     * 
     * This function halts the execution until the user provides a confirmation.
     * It is typically used in scenarios where a user needs to acknowledge or 
     * confirm a step before proceeding.
     */
    void waitForConfirm();

    /**
     * @brief Handles the button click event.
     * 
     * This function processes the button click event based on the mouse position.
     * It determines which button was clicked and performs the corresponding action.
     * 
     * @param mousePos The position of the mouse cursor at the time of the click event.
     */
    void handleButtonClick(sf::Vector2i mousePos);


private:
    /**
     * 
     */
    void runShellScript();
    float getProgressFromFile();

    sf::RenderWindow window;
    TextManager textManager;

    sf::Text confirmText;
    sf::Text progressText;
    sf::Text completeText;

    Button yesButton;
    Button noButton;

    ProgressBar progressBar;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    bool installationStarted = false;
    bool installationComplete = false;
    bool waitingForConfirmation = true;
    float progress = 0.0f;
    float threadProcess = 0.0f;

    std::string scriptFile;

};
