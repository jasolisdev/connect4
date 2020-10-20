#include "../include/connect4_gg.h"

#include "../include/connect4_game.h"

void connect4_gg::Initialize(sf::RenderWindow* window) {
  enterKey = false;
  escapeKey = false;
  sf::Font* font = new sf::Font();
  font->loadFromFile("assets/connect4_font.otf");

  this->gameOverText = new sf::Text(
      "\t\t\t\tGame Over!\nPress Enter to Start a New Game\n\t\t\t or Esc "
      "to Exit Game.",
      *font, 70U);
  this->gameOverText->setFillColor(sf::Color::Red);
  this->gameOverText->setStyle(sf::Text::Bold);
  this->gameOverText->setOrigin(
      sf::Vector2f(this->gameOverText->getGlobalBounds().width / 2,
                   this->gameOverText->getGlobalBounds().height / 2));
  this->gameOverText->setPosition(
      sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
}
void connect4_gg::Update(sf::RenderWindow* window) {
  if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && enterKey) {
    coreState->SetState(new connect4_game());
    redCount = 21;
    yellowCount = 21;
  }

  if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && escapeKey) {
    exitGame = true;
  }

  enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
  escapeKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
}
void connect4_gg::Render(sf::RenderWindow* window) {
  window->clear(sf::Color::White);
  window->draw(*this->gameOverText);
}
void connect4_gg::Destroy(sf::RenderWindow* window) {}
