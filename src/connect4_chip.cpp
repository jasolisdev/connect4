#include "../include/connect4_chip.h"
#include "../include/connect4_game.h"
#include "../include/connect4_gg.h"

#include <iostream>

Chip::Chip(float x, float y, bool isRed) {
  if (isRed) {
    this->group_id = 2;
    this->Load("assets/redchip.png", sf::IntRect());
  } else {
    this->group_id = 3;
    this->Load("assets/blackchip.png", sf::IntRect());
  }

  this->setScale(sf::Vector2f(.8f, .8f));
  this->setPosition(sf::Vector2f(x, y));
}

void Chip::Update() {
  std::cout << "Hellop" << std::endl;
  if (this->active) {
    /* sf::Event event; */

    if (group_id == 2) {
      this->active = 0;

      redCount -= 1;

      if (redCount < 0) {
        redCount = 0;
        std::cout << "Red is out of plays!" << std::endl;
        /* coreState->SetState(new game_over()); */
      }
    } else if (group_id == 3) {
      this->active = 0;
      blackCount -= 1;

      if (blackCount < 0) {
        blackCount = 0;
        std::cout << "Black is out of plays!" << std::endl;
        /* coreState->SetState(new game_over()); */
      }
    }
  }

  if (redCount == 0 and blackCount == 0) {
    coreState->SetState(new connect4_gg());
  }

  // implement gravity and bounding box collision when chip placed.
}
