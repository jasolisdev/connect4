#include "Board.h"

// Initialize static constants
const float Board::BOARD_WIDTH = 780.0f;  // Dimensions of board.png
const float Board::BOARD_HEIGHT = 750.0f;

// Initialize grid dimensions (can be adjusted)
float Board::GRID_WIDTH = 770.0f;  // Start with values close to BOARD_WIDTH
float Board::GRID_HEIGHT = 740.0f;

Board::Board(float offsetX, float offsetY)
    : offsetX(offsetX), offsetY(offsetY),
      falling(false), fallingPlayer(0), fallingColumn(-1), fallingRow(-1), fallingDiscY(0.0f) {
    grid = std::vector<std::vector<int>>(COLS, std::vector<int>(ROWS, 0));
}

void Board::draw(sf::RenderWindow& window) {
    // Optionally, draw the grid lines to help with alignment (can be commented out)

    // Draw the discs (chips)
    float discRadiusX = (GRID_WIDTH / COLS) / 2.0f * 0.9f; // Adjust multiplier as needed
    float discRadiusY = (GRID_HEIGHT / ROWS) / 2.0f * 0.9f;

    sf::CircleShape disc(std::min(discRadiusX, discRadiusY));
    disc.setOrigin(disc.getRadius(), disc.getRadius());

    for (int col = 0; col < COLS; ++col) {
        for (int row = 0; row < ROWS; ++row) {
            int player = grid[col][row];
            if (player != 0) {
                float posX = offsetX + (col + 0.5f) * (GRID_WIDTH / COLS);
                float posY = offsetY + (row + 0.5f) * (GRID_HEIGHT / ROWS);

                disc.setPosition(posX, posY);

                // Check if this position is a winning position
                bool isWinningPosition = false;
                for (const auto& pos : winningPositions) {
                    if (pos.first == col && pos.second == row) {
                        isWinningPosition = true;
                        break;
                    }
                }

                if (isWinningPosition) {
                    // Highlight the disc with a green outline
                    disc.setOutlineThickness(5.0f);
                    disc.setOutlineColor(sf::Color::Green);
                } else {
                    disc.setOutlineThickness(0);
                }

                // Set the disc color based on the player
                if (player == 1) {
                    disc.setFillColor(sf::Color::Red);
                } else if (player == 2) {
                    disc.setFillColor(sf::Color::Yellow);
                }

                window.draw(disc);
            }
        }
    }

    // Draw the falling disc, if there is one
    if (falling) {
        disc.setOutlineThickness(0); // No outline for the falling disc

        float posX = offsetX + (fallingColumn + 0.5f) * (GRID_WIDTH / COLS);

        disc.setPosition(posX, fallingDiscY);

        if (fallingPlayer == 1) {
            disc.setFillColor(sf::Color::Red);
        } else if (fallingPlayer == 2) {
            disc.setFillColor(sf::Color::Yellow);
        }
        window.draw(disc);
    }
}

bool Board::startDiscDrop(int col, int player) {
    if (col < 0 || col >= COLS || falling) return false; // Invalid column or already falling

    // Find the next available row in the selected column
    for (int row = ROWS - 1; row >= 0; --row) {
        if (grid[col][row] == 0) {
            falling = true;
            fallingPlayer = player;
            fallingColumn = col;
            fallingRow = row;
            // Start above the grid
            fallingDiscY = offsetY - (GRID_HEIGHT / ROWS) / 2.0f;
            return true;
        }
    }

    return false; // Column is full
}

void Board::update(float deltaTime) {
    if (!falling) return;

    // Falling speed
    float speed = 600.0f;

    fallingDiscY += speed * deltaTime;

    float targetY = offsetY + (fallingRow + 0.5f) * (GRID_HEIGHT / ROWS);

    // Check if the disc has reached the target position
    if (fallingDiscY >= targetY) {
        fallingDiscY = targetY;
        grid[fallingColumn][fallingRow] = fallingPlayer; // Place the disc in the grid
        falling = false;
    }
}

void Board::skipDiscAnimation() {
    if (falling) {
        // Instantly place the disc at the target position
        fallingDiscY = offsetY + (fallingRow + 0.5f) * (GRID_HEIGHT / ROWS);
        grid[fallingColumn][fallingRow] = fallingPlayer; // Place the disc in the grid
        falling = false;
    }
}

bool Board::isDiscFalling() const {
    return falling;
}

bool Board::checkWin(int player) {
    // Clear any previous winning positions
    winningPositions.clear();

    // Check horizontal lines
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col <= COLS - 4; ++col) {
            if (checkDirection(col, row, 1, 0, player)) {
                return true;
            }
        }
    }

    // Check vertical lines
    for (int col = 0; col < COLS; ++col) {
        for (int row = 0; row <= ROWS - 4; ++row) {
            if (checkDirection(col, row, 0, 1, player)) {
                return true;
            }
        }
    }

    // Check diagonal (bottom-left to top-right)
    for (int col = 0; col <= COLS - 4; ++col) {
        for (int row = 0; row <= ROWS - 4; ++row) {
            if (checkDirection(col, row, 1, 1, player)) {
                return true;
            }
        }
    }

    // Check diagonal (top-left to bottom-right)
    for (int col = 0; col <= COLS - 4; ++col) {
        for (int row = 3; row < ROWS; ++row) {
            if (checkDirection(col, row, 1, -1, player)) {
                return true;
            }
        }
    }

    // No win found
    winningPositions.clear(); // Ensure no positions are stored if no win
    return false;
}

bool Board::checkDirection(int startX, int startY, int dx, int dy, int player) {
    int count = 0;
    std::vector<std::pair<int, int>> tempPositions; // Temporary storage

    for (int i = 0; i < 4; ++i) {
        int x = startX + i * dx;
        int y = startY + i * dy;
        if (x >= 0 && x < COLS && y >= 0 && y < ROWS && grid[x][y] == player) {
            count++;
            tempPositions.push_back({x, y}); // Record the position
        } else {
            break;
        }
    }

    if (count == 4) {
        winningPositions = tempPositions; // Save the winning positions
        return true;
    } else {
        return false;
    }
}

bool Board::isBoardFull() const {
    for (int col = 0; col < COLS; ++col) {
        for (int row = 0; row < ROWS; ++row) {
            if (grid[col][row] == 0) {
                return false; // Found an empty spot
            }
        }
    }
    return true; // Board is full
}

void Board::clear() {
    for (int col = 0; col < COLS; ++col) {
        for (int row = 0; row < ROWS; ++row) {
            grid[col][row] = 0; // Clear the grid for a new game
        }
    }
}
