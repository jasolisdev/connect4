#include "../include/connect4_chip.h"

#include <iostream>

#include "../include/connect4_game.h"
#include "../include/connect4_gg.h"

Chip::Chip(float x, float y, bool isRed) {
  if (isRed) {
    this->group_id = 1;
    this->Load("assets/redchip.png", sf::IntRect());

    rectangle.setSize(sf::Vector2f(80, 80));
    rectangle.setOutlineColor(sf::Color::Green);
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(x, y);
    this->setScale(sf::Vector2f(.8f, .8f));
    this->setPosition(sf::Vector2f(x, y));
  } else {
    this->group_id = 2;
    this->Load("assets/yellowchip.png", sf::IntRect());

    rectangle.setSize(sf::Vector2f(80, 80));
    rectangle.setOutlineColor(sf::Color::Green);
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition(x, y);
    this->setScale(sf::Vector2f(.8f, .8f));
    this->setPosition(sf::Vector2f(x, y));
  }
}

void Chip::Update() {
  if (this->active) {
    if (group_id == 1) {
      this->active = 0;
      redCount -= 1;

      this->active = 1;
      this->move(sf::Vector2f(0.f, .2f));
      rectangle.move(sf::Vector2f(0.f, .2f));
    } else if (group_id == 2) {
      this->active = 0;
      yellowCount -= 1;

      this->active = 1;
      this->move(sf::Vector2f(0.f, .2f));
      rectangle.move(sf::Vector2f(0.f, .2f));
    }
  }
  if (redCount == 0 && yellowCount == 0) {
    coreState->SetState(new connect4_gg());

    // implement gravity and bounding box collision when chip placed.
  }
}
