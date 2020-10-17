#include "../include/connect4_gg.h"
#include <iostream>

void connect4_gg::Initialize(sf::RenderWindow *window) {
  enterKey = false;
  sf::Font *font = new sf::Font();
  font->loadFromFile("assets/Ubuntu.ttf");

  this->gameOverText =
      new sf::Text("\t\t\tGame Over! \n Press Enter to Exit Game.", *font, 60U);
  this->gameOverText->setFillColor(sf::Color::Red);
  this->gameOverText->setStyle(sf::Text::Bold);
  this->gameOverText->setOrigin(
      sf::Vector2f(this->gameOverText->getGlobalBounds().width / 2,
                   this->gameOverText->getGlobalBounds().height / 2));
  this->gameOverText->setPosition(
      sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
}
void connect4_gg::Update(sf::RenderWindow *window) {
  if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && enterKey) {
    exitGame = true;
  }

  enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}
void connect4_gg::Render(sf::RenderWindow *window) {
  window->draw(*this->gameOverText);
}
void connect4_gg::Destroy(sf::RenderWindow *window) {}
