/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** install
*/
/**
 * @file install.cpp
 * @brief Implementation of the Installer class for the R-type project.
 * 
 * This file contains the implementation of the Installer class, which is responsible for
 * managing the installation process of the R-type project. The Installer class provides
 * functionalities to create an installation window, execute a shell script for installation,
 * track installation progress, and handle user input for installation confirmation.
 * 
 * The main features of the Installer class include:
 * - Creating and positioning the installation window.
 * - Loading and managing fonts and text elements.
 * - Executing a shell script to perform installation tasks.
 * - Reading installation progress from a file.
 * - Displaying installation progress and completion messages.
 * - Handling user input for installation confirmation.
 * 
 * The installation process is visualized through a progress bar and text messages, providing
 * feedback to the user about the current state of the installation.
 * 
 * @note This implementation uses the SFML library for window and event management.
 * 
 * @see install.hpp
 */

#include "install.hpp"
#include "assets/elements/utils/utils.hpp"

/**
 * @brief Constructs an Installer object.
 * 
 * This constructor initializes the installer window to half the size of the desktop resolution
 * and centers it on the screen. It also loads the necessary fonts and sets up the text and 
 * progress bar for the installation process.
 * 
 * The following steps are performed:
 * - Retrieves the desktop resolution.
 * - Calculates the window size to be half of the desktop resolution.
 * - Centers the window on the screen.
 * - Creates the window with a title and close button.
 * - Loads the font from the specified path.
 * - Sets the window ratio for text management.
 * - Creates the confirmation, progress, and completion texts.
 * - Initializes the progress bar with a fixed size and sets its window ratio.
 */
Installer::Installer()
{
    // get the windows size to decide where to place element and with which size
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    unsigned int windowWidth = desktop.width / 2;
    unsigned int windowHeight = desktop.height / 2;
    unsigned int windowPosX = (desktop.width - windowWidth) / 2;
    unsigned int windowPosY = (desktop.height - windowHeight) / 2;

    // create the window with correct size and position
    window.create(sf::VideoMode(windowWidth, windowHeight), "Installer", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(sf::Vector2i(windowPosX, windowPosY));

    // storing the window size in a var to use it later
    sf::Vector2i windowRatio = {static_cast<int>(windowWidth), static_cast<int>(windowHeight)};

    textManager.loadFont("assets/font/arial/arial.ttf"); // loading the font that will be used for every text
    textManager.setWindowRatio(windowRatio); // setting the windows ratio as it will be used to decide where to place the text and with which size
    confirmText = textManager.createText("Do you want to install the program? (Y/N)"); // creating the texts
    progressText = textManager.createText("Installing...");
    completeText = textManager.createText("Installation Complete! Press any key to exit.");

    // setting up the progressbar relative to the windowsize
    progressBar.setWindowRatio(windowRatio);

    // create the two button
    yesButton = Button("Yes", textManager.getDefaultFont(), windowRatio, 0);
    noButton = Button("No", textManager.getDefaultFont(), windowRatio);

    if (!backgroundTexture.loadFromFile("assets/img/background.jpg"))
        throw std::runtime_error("Failed to load background image");

    // Set the texture to the sprite
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        window.getSize().x / static_cast<float>(backgroundTexture.getSize().x),
        window.getSize().y / static_cast<float>(backgroundTexture.getSize().y)
    );
}


/**
 * @brief Executes a shell script to perform installation tasks.
 *
 * This function runs a shell script located at "./assets/script/install.sh".
 * The script is expected to handle the necessary installation procedures.
 */
void Installer::runShellScript() {
    system("./assets/script/install.sh");
}

/** * @brief Retrieves the installation progress from a file. *  * This function reads the progress from a file named "progress.txt" and converts it to a float value.
 * The progress value is expected to be in percentage (0-100) and is converted to a range of 0.0 to 1.0.
 * 
 * @return The installation progress as a float value between 0.0 and 1.0.
 */
float Installer::getProgressFromFile() {
    std::ifstream progressFile("progress.txt");
    if (progressFile.is_open()) {
        std::string progressStr;
        std::getline(progressFile, progressStr);
        progressFile.close();
        if (progressStr.empty())
            return threadProcess;
        threadProcess = std::stof(progressStr) / 100.0f;
        return threadProcess;
    }
    return 0.0f;
}

/**
 * @brief Updates the installation progress and displays it.
 * 
 * This function updates the progress bar based on the current installation progress read from a file.
 * It also checks if the installation is complete and updates the window display accordingly.
 */
void Installer::progressLoop()
{
    progress = getProgressFromFile();
    progressBar.setProgress(progress);
    if (progress >= 1.0f)
        installationComplete = true;
    window.draw(progressText);
    progressBar.draw(window);
}

/**
 * @brief Waits for user confirmation by drawing confirmation text and buttons.
 * 
 * This function renders the confirmation text and the "Yes" and "No" buttons
 * on the window, waiting for the user to make a selection.
 */
void Installer::waitForConfirm()
{
    window.draw(confirmText);
    yesButton.draw(window);
    noButton.draw(window);
}

/**
 * @brief Handles user input for starting the installation process.
 * 
 * This function listens for specific keyboard events to determine whether
 * the user wants to start the installation process or close the window.
 * 
 * @param event The SFML event containing the user's input.
 * 
 * If the user presses the 'Y' key, the installation process is started
 * in a separate thread by calling the `runShellScript` method. The 
 * `installationStarted` flag is set to true and `waitingForConfirmation`
 * is set to false.
 * 
 * If the user presses the 'N' key, the window is closed.
 */
void Installer::askUser(sf::Event event)
{
    if (event.key.code == sf::Keyboard::Y) {
        installationStarted = true;
        waitingForConfirmation = false;
        std::thread installThread(&Installer::runShellScript, this);
        installThread.detach();
    } else if (event.key.code == sf::Keyboard::N)
        window.close();
}

/**
 * @brief Handles the button click events for the installer.
 * 
 * This function checks if the 'yes' or 'no' button is clicked based on the mouse position.
 * If the 'yes' button is clicked, it starts the installation process in a separate thread.
 * If the 'no' button is clicked, it closes the window.
 * 
 * @param mousePos The position of the mouse click.
 */
void Installer::handleButtonClick(sf::Vector2i mousePos) {
    if (yesButton.isClicked(mousePos)) {
        installationStarted = true;
        waitingForConfirmation = false;
        std::thread installThread(&Installer::runShellScript, this);
        installThread.detach();
    } else if (noButton.isClicked(mousePos)) {
        window.close();
    }
}

/**
 * @brief Runs the main loop of the installer.
 * 
 * This function handles the main event loop of the installer window. It processes
 * events such as window closing, user confirmation, and installation completion.
 * The function updates the window display based on the current state of the installation
 * process and removes the "progress.txt" file upon completion.
 * 
 * Event Handling:
 * - Closes the window if the close event is triggered.
 * - Calls askUser(event) if waiting for user confirmation and a key is pressed.
 * - Closes the window if the installation is complete and a key is pressed.
 * 
 * Window Display:
 * - Draws confirmation text if waiting for user confirmation.
 * - Calls progressLoop() if the installation has started but is not complete.
 * - Draws completion text if the installation is complete.
 * 
 * @note This function will block until the window is closed.
 */
void Installer::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (waitingForConfirmation) {
                if (event.type == sf::Event::KeyPressed)
                    askUser(event);
                else if (event.type == sf::Event::MouseButtonPressed)
                    if (event.mouseButton.button == sf::Mouse::Left)
                        handleButtonClick(sf::Mouse::getPosition(window));
            }
            if (installationComplete && event.type == sf::Event::KeyPressed)
                window.close();
        }
        window.clear();
        window.draw(backgroundSprite);
        if (waitingForConfirmation)
            waitForConfirm();
        else if (installationStarted && !installationComplete)
            progressLoop();
        else if (installationComplete)
            window.draw(completeText);
        window.display();
    }
    std::remove("progress.txt");
}
