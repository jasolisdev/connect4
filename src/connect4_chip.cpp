#include "../include/connect4_chip.h"

#include <iostream>

#include "../include/connect4_game.h"
#include "../include/connect4_gg.h"

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
  if (this->active) {
    if (group_id == 2) {
      this->active = 0;
      redCount -= 1;
    } else if (group_id == 3) {
      this->active = 0;
      blackCount -= 1;
    }
  }

  if (redCount == 0 && blackCount == 0) {
    coreState->SetState(new connect4_gg());
  }

  // implement gravity and bounding box collision when chip placed.
}
