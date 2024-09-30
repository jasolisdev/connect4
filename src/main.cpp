#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // Include SFML Audio module
#include "Board.h"
#include "Game.h"
#include <iostream>

int main() {
    // Set window size to 1280x720
    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Connect 4");

    // Set the frame rate limit to 60 FPS
    window.setFramerateLimit(60);

    // Load the background image from assets folder (optional)
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/background.jpg")) {
        std::cerr << "Error: Could not load assets/background.jpg" << std::endl;
        return -1;
    }

    // Create a sprite for the background
    sf::Sprite backgroundSprite(backgroundTexture);

    // Scale the background to fit the window
    float bgScaleX = static_cast<float>(WINDOW_WIDTH) / backgroundTexture.getSize().x;
    float bgScaleY = static_cast<float>(WINDOW_HEIGHT) / backgroundTexture.getSize().y;
    backgroundSprite.setScale(bgScaleX, bgScaleY);

    // Load the board image
    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("assets/board.png")) {
        std::cerr << "Error: Could not load assets/board.png" << std::endl;
        return -1;
    }

    // Create a sprite for the board
    sf::Sprite boardSprite(boardTexture);

    // Dimensions of the board image
    const float BOARD_WIDTH = Board::BOARD_WIDTH;
    const float BOARD_HEIGHT = Board::BOARD_HEIGHT;

    // Calculate position to center the board
    float boardPosX = (WINDOW_WIDTH - BOARD_WIDTH) / 2.0f;
    float boardPosY = (WINDOW_HEIGHT - BOARD_HEIGHT) / 2.0f;

    // **Define grid position adjustments (if needed)**
    float gridOffsetX = 71.0f; // Adjust this value to move the grid horizontally
    float gridOffsetY = 107.0f; // Adjust this value to move the grid vertically

    // **Set the position of the board sprite without offsets**
    boardSprite.setPosition(boardPosX, boardPosY);

    // **Offsets for the grid and discs**
    float offsetX = boardPosX + gridOffsetX;
    float offsetY = boardPosY + gridOffsetY;

    // **Set grid dimensions (adjust to align with board.png)**
    Board::GRID_WIDTH = 640.0f;  // Adjust these values as needed
    Board::GRID_HEIGHT = 560.0f;

    // Load the turn indicator images from assets folder
    sf::Texture redTurnTexture;
    if (!redTurnTexture.loadFromFile("assets/redTurn.png")) {
        std::cerr << "Error: Could not load assets/redTurn.png" << std::endl;
        return -1;
    }

    sf::Texture yellowTurnTexture;
    if (!yellowTurnTexture.loadFromFile("assets/yellowTurn.png")) {
        std::cerr << "Error: Could not load assets/yellowTurn.png" << std::endl;
        return -1;
    }

    sf::Texture grayTexture;
    if (!grayTexture.loadFromFile("assets/gray.png")) {
        std::cerr << "Error: Could not load assets/gray.png" << std::endl;
        return -1;
    }

    // Create sprites for the turn indicators
    sf::Sprite leftTurnSprite;
    sf::Sprite rightTurnSprite;

    // Scale factors for the turn indicator images (adjust these as needed)
    float turnIndicatorScaleX = 0.4f; // Adjust as needed
    float turnIndicatorScaleY = 0.4f;

    // Set the scales
    leftTurnSprite.setScale(turnIndicatorScaleX, turnIndicatorScaleY);
    rightTurnSprite.setScale(turnIndicatorScaleX, turnIndicatorScaleY);

    // Load the font from assets folder
    sf::Font font;
    if (!font.loadFromFile("assets/connect4_font.otf")) {
        std::cerr << "Error: Could not load assets/connect4_font.otf" << std::endl;
        return -1;
    }

    // Font sizes (adjust as needed)
    unsigned int titleFontSize = 50; // Title font size
    unsigned int chipsFontSize = 30; // Chips count font size

    // Create text for the title
    sf::Text titleText;
    titleText.setFont(font);
    titleText.setString("Connect4");
    titleText.setFillColor(sf::Color::Black);
    titleText.setCharacterSize(titleFontSize);

    // Position the title at the center top
    sf::FloatRect titleBounds = titleText.getLocalBounds();
    titleText.setOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
    titleText.setPosition(WINDOW_WIDTH / 2.0f, titleFontSize); // Adjust Y position as needed

    // Create text for the chip counts
    sf::Text redChipsText;
    redChipsText.setFont(font);
    redChipsText.setFillColor(sf::Color::Red);
    redChipsText.setCharacterSize(chipsFontSize);

    sf::Text yellowChipsText;
    yellowChipsText.setFont(font);
    yellowChipsText.setFillColor(sf::Color::Yellow);
    yellowChipsText.setCharacterSize(chipsFontSize);

    // Load the chip placed sound from assets folder
    sf::SoundBuffer chipSoundBuffer;
    if (!chipSoundBuffer.loadFromFile("assets/chipPlaced.wav")) {
        std::cerr << "Error: Could not load assets/chipPlaced.wav" << std::endl;
        return -1;
    }

    sf::Sound chipSound;
    chipSound.setBuffer(chipSoundBuffer);

    // Set the volume level (adjust as needed)
    chipSound.setVolume(50.0f); // Volume level between 0.0f (mute) and 100.0f (max)

    // Create the board and game objects, passing the offsets
    Board board(offsetX, offsetY);
    Game game(&board);

    sf::Clock clock;
    bool gameJustReset = false; // Flag to check if the game was just reset

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            // Handle window close event
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Handle resetting the game after a win when the player taps
            if (game.isGameWon() && (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::KeyPressed)) {
                game.resetGame(); // Reset the game
                gameJustReset = true; // Set the flag to true to ignore the next input
            }

            // Handle mouse button press event
            if (!game.isGameWon() && event.type == sf::Event::MouseButtonPressed) {
                if (gameJustReset) {
                    gameJustReset = false; // Ignore the first click after reset
                } else if (board.isDiscFalling()) {
                    // Skip the falling animation
                    board.skipDiscAnimation();
                } else {
                    // Adjust the column calculation to account for updated offsetX and GRID_WIDTH
                    int col = (event.mouseButton.x - offsetX) / (Board::GRID_WIDTH / COLS);
                    // Handle the turn and check if the chip started to fall
                    if (game.handleTurn(col)) {
                        // The chip has started to fall, play the sound
                        chipSound.play();
                    }
                }
            }
        }

        // Update the game state
        game.update(deltaTime);

        // Update the turn indicator sprites based on the current player
        if (game.getCurrentPlayer() == 1) {
            // Red player's turn
            leftTurnSprite.setTexture(redTurnTexture);
            rightTurnSprite.setTexture(grayTexture);
        } else if (game.getCurrentPlayer() == 2) {
            // Yellow player's turn
            leftTurnSprite.setTexture(grayTexture);
            rightTurnSprite.setTexture(yellowTurnTexture);
        }

        // Set the scales (in case they change)
        leftTurnSprite.setScale(turnIndicatorScaleX, turnIndicatorScaleY);
        rightTurnSprite.setScale(turnIndicatorScaleX, turnIndicatorScaleY);

        // Update positions of the turn indicators
        float leftIndicatorY = (WINDOW_HEIGHT - leftTurnSprite.getGlobalBounds().height) / 2.0f;
        float rightIndicatorY = (WINDOW_HEIGHT - rightTurnSprite.getGlobalBounds().height) / 2.0f;

        float leftIndicatorX = 20.0f; // 20 pixels from the left edge
        float rightIndicatorX = WINDOW_WIDTH - rightTurnSprite.getGlobalBounds().width - 20.0f; // 20 pixels from the right edge

        leftTurnSprite.setPosition(leftIndicatorX, leftIndicatorY);
        rightTurnSprite.setPosition(rightIndicatorX, rightIndicatorY);

        // Update the chip counts
        int redChipsRemaining = game.getRedChipsRemaining();
        int yellowChipsRemaining = game.getYellowChipsRemaining();

        redChipsText.setString("Red Chips " + std::to_string(redChipsRemaining));
        yellowChipsText.setString("Yellow Chips " + std::to_string(yellowChipsRemaining));

        // Update positions of chip count texts
        // For redChipsText at bottom left
        sf::FloatRect redTextBounds = redChipsText.getLocalBounds();
        redChipsText.setOrigin(redTextBounds.left, redTextBounds.top + redTextBounds.height); // Set origin to bottom left
        redChipsText.setPosition(10.0f, WINDOW_HEIGHT - 10.0f); // 10 pixels from bottom left corner

        // For yellowChipsText at bottom right
        sf::FloatRect yellowTextBounds = yellowChipsText.getLocalBounds();
        yellowChipsText.setOrigin(yellowTextBounds.left + yellowTextBounds.width, yellowTextBounds.top + yellowTextBounds.height); // Set origin to bottom right
        yellowChipsText.setPosition(WINDOW_WIDTH - 10.0f, WINDOW_HEIGHT - 10.0f); // 10 pixels from bottom right corner

        // Drawing code
        window.clear();
        // Draw the background first
        window.draw(backgroundSprite);

        // Draw the discs (chips)
        board.draw(window);

        // Draw the board sprite (board.png)
        window.draw(boardSprite);

        // Draw the turn indicators
        window.draw(leftTurnSprite);
        window.draw(rightTurnSprite);

        // Draw the title
        window.draw(titleText);

        // Draw the chip counts
        window.draw(redChipsText);
        window.draw(yellowChipsText);

        // If the game is won, dim the screen and show the win message
        if (game.isGameWon()) {
            sf::RectangleShape dimRect(sf::Vector2f(window.getSize().x, window.getSize().y));
            dimRect.setFillColor(sf::Color(0, 0, 0, 150)); // Dim the screen
            window.draw(dimRect);

            // Display the winner message
            sf::Text winText;
            winText.setFont(font);
            winText.setString(game.getWinner() == 1 ? "Red Player Wins!" : "Yellow Player Wins!");
            winText.setCharacterSize(80);
            winText.setFillColor(sf::Color::White);
            sf::FloatRect winTextBounds = winText.getLocalBounds();
            winText.setOrigin(winTextBounds.left + winTextBounds.width / 2.0f, winTextBounds.top + winTextBounds.height / 2.0f);
            winText.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f - 50); // Adjust position as needed
            window.draw(winText);

            // Display "Tap to Play Again" message
            sf::Text playAgainText;
            playAgainText.setFont(font);
            playAgainText.setString("Tap to Play Again.");
            playAgainText.setCharacterSize(40);
            playAgainText.setFillColor(sf::Color::White);
      
            // Get the bounding box of the text to center it
            sf::FloatRect playAgainTextBounds = playAgainText.getLocalBounds();
            playAgainText.setOrigin(playAgainTextBounds.left + playAgainTextBounds.width / 2.0f, playAgainTextBounds.top + playAgainTextBounds.height / 2.0f);
            playAgainText.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f + 50); // Adjust position as needed
            window.draw(playAgainText);
      
        }

        window.display();
    }

    return 0;
}
