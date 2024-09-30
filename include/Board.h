#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <utility> // For std::pair

const int ROWS = 6;
const int COLS = 7;

class Board {
public:
    // Static constants for board dimensions (board.png)
    static const float BOARD_WIDTH;
    static const float BOARD_HEIGHT;

    // Static variables for grid dimensions
    static float GRID_WIDTH;
    static float GRID_HEIGHT;

    // Constructor accepting offsets
    Board(float offsetX, float offsetY);

    void draw(sf::RenderWindow& window);
    bool startDiscDrop(int col, int player); // Start the disc drop for a player
    void update(float deltaTime); // Update the falling disc's position
    bool isDiscFalling() const; // Check if a disc is currently falling
    bool checkWin(int player); // Check if the given player has won
    bool isBoardFull() const; // Check if the board is full
    void skipDiscAnimation(); // Method to skip the animation

    // Method to clear the board for a new game (Added for game reset)
    void clear();

private:
    std::vector<std::vector<int>> grid; // The grid representing the board

    // Animation-related members
    bool falling; // Is a disc falling
    int fallingPlayer; // The player whose disc is falling
    int fallingColumn; // Column where the disc is falling
    int fallingRow;    // Target row for the falling disc
    float fallingDiscY;  // Current Y position of the falling disc

    // Member to store winning positions
    std::vector<std::pair<int, int>> winningPositions;

    // Helper function to check win in a direction and record positions
    bool checkDirection(int startX, int startY, int dx, int dy, int player);

    // Members for offsets (to position the board)
    float offsetX;
    float offsetY;
};

#endif // BOARD_H
