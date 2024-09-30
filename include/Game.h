#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
public:
    Game(Board* board);
    bool handleTurn(int col); // Return true if the disc started to fall
    void update(float deltaTime);
    bool isGameWon() const;
    int getWinner() const;      // Optional: To determine the winner
    int getCurrentPlayer() const; // Method to get the current player

    // New methods to get remaining chips
    int getRedChipsRemaining() const;
    int getYellowChipsRemaining() const;

    // New method to reset the game when tapping to play again
    void resetGame();

private:
    Board* board;
    int currentPlayer;
    bool gameWon;
    int winner;       // To keep track of the winner (1 or 2)
    bool prevFalling; // To detect when the disc has just finished falling

    // New variables for game-over state and message
    bool gameOver;
    std::string winnerMessage;

    // New member variables for chip counts
    int redChipsRemaining;
    int yellowChipsRemaining;
};

#endif // GAME_H
