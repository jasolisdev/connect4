#include "../include/connect4_chip.h"

#include <iostream>

#include "../include/connect4_game.h"
#include "../include/connect4_gg.h"

Chip::Chip(float x, float y, bool isRed) {
  if (isRed) {
    redCount -= 1;
    this->group_id = 1;
    this->Load("assets/redchip.png");
    this->setScale(sf::Vector2f(0.99f, 0.99f));
    this->setPosition(sf::Vector2f(x, y));

  } else {
    yellowCount -= 1;
    this->group_id = 2;
    this->Load("assets/yellowchip.png");
    this->setScale(sf::Vector2f(1.f, 1.f));
    this->setPosition(sf::Vector2f(x, y));
  }
}

void Chip::Update() {
  if (this->active) {
    if (group_id == 1) {
      // Hardcoded bottom bounds
      // TODO: get the bottom position of the bottom bounding boxes
      if (this->getPosition().y > 825) {
        this->move(sf::Vector2f(0.f, 0.f));
      } else {
        this->move(sf::Vector2f(0.f, 2.f));
      }
    } else if (group_id == 2) {
      if (this->getPosition().y > 830) {
        this->move(sf::Vector2f(0.f, 0.f));
      } else {
        this->move(sf::Vector2f(0.f, 2.f));
      }
    }
  }
  if (redCount == 0 && yellowCount == 0) {
    coreState->SetState(new connect4_gg());
  }
}
