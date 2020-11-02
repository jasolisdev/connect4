#include "../include/connect4_box.h"

#include <iostream>

Box::Box(float x, float y, bool isEmpty, bool isFilled) {
  this->group_id = 3;
  this->box.setFillColor(sf::Color::Transparent);
  this->box.setOutlineColor(sf::Color::Magenta);
  this->box.setOutlineThickness(3);
  this->box.setSize(sf::Vector2f(100, 100));
  this->box.setPosition(sf::Vector2f(x, y));
}

void Box::Update() {
  // TODO: If the red chip's turn is over and it has collided with a bounding
  // box change the color of the bounding box and set isEmpty to false and
  // isFilled to true. Same with yellow.
  //  if (endTurn && isRed && chip.getPosition().x == this->box.getPosition().x)
  //    this->box.setOutlineColor(sf::Color::Red);
  //  else if (endTurn && !isRed &&
  //           chip.getPosition().x == this->box.getPosition().x)
  //    this->box.setOutlineColor(sf::Color::Yellow);
}

void Box::Render(sf::RenderWindow *window) { window->draw(this->box); }
