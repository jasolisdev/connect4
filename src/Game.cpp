#include "Game.h"
#include "Board.h"
#include <iostream>

Game::Game(Board* board)
    : board(board), currentPlayer(1), gameWon(false), winner(0), prevFalling(false),
      redChipsRemaining(21), yellowChipsRemaining(21), gameOver(false), winnerMessage("") {}

bool Game::handleTurn(int col) {
    // Only proceed if the disc is not currently falling and the game is not over
    if (!board->isDiscFalling() && !gameOver) {
        if (board->startDiscDrop(col, currentPlayer)) {
            return true; // Indicate that the chip started to fall
        }
    }
    return false; // Disc did not start to fall
}

void Game::update(float deltaTime) {
    board->update(deltaTime);

    // Check if the disc has just finished falling
    if (prevFalling && !board->isDiscFalling() && !gameWon) {
        // The disc has just landed

        // Decrement the chip count for the current player
        if (currentPlayer == 1) {
            redChipsRemaining--;
        } else if (currentPlayer == 2) {
            yellowChipsRemaining--;
        }

        // Check for a win
        if (board->checkWin(currentPlayer)) {
            gameWon = true;
            winner = currentPlayer; // Store the winner
            gameOver = true;
            winnerMessage = (winner == 1) ? "Red Player Wins!" : "Yellow Player Wins!";
        } else if (board->isBoardFull()) {
            gameWon = true;
            winner = 0; // It's a draw
            gameOver = true;
            winnerMessage = "It's a Draw!";
        } else {
            // Switch to the other player
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }

    // Update prevFalling after checking
    prevFalling = board->isDiscFalling();
}

bool Game::isGameWon() const {
    return gameWon;
}

int Game::getWinner() const {
    return winner; // Returns 0 if it's a draw or the game isn't over
}

int Game::getCurrentPlayer() const {
    return currentPlayer;
}

// New methods to get remaining chips
int Game::getRedChipsRemaining() const {
    return redChipsRemaining;
}

int Game::getYellowChipsRemaining() const {
    return yellowChipsRemaining;
}

void Game::resetGame() {
    board->clear(); // Clear the board
    gameOver = false;
    winnerMessage = "";
    currentPlayer = 1; // Reset to Red player
    redChipsRemaining = 21;
    yellowChipsRemaining = 21;
    gameWon = false;
}
