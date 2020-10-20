#include "../include/connect4_game.h"

#include <stdio.h>

#include <iostream>
#include <string>

#include "../include/connect4_chip.h"

int redCount = 21;
int yellowCount = 21;

bool redTurn = true;
bool yellowTurn = false;
bool isRed = false;

void connect4_game::Initialize(sf::RenderWindow* window) {
  sf::Font* font = new sf::Font();
  font->loadFromFile("assets/connect4_font.otf");

  this->connect4Text = new sf::Text("CONNECT4", *font, 60U);
  this->connect4Text->setFillColor(sf::Color::Black);
  this->connect4Text->setStyle(sf::Text::Bold);
  this->textRect = connect4Text->getLocalBounds();
  this->connect4Text->setOrigin(textRect.left + textRect.width / 2.0f,
                                textRect.top + textRect.height / 2.0f);
  connect4Text->setPosition(sf::Vector2f(1920 / 2.0f, 80));

  this->redChipsText = new sf::Text("Red Chips: 21", *font, 32U);
  this->redChipsText->setFillColor(sf::Color::Red);
  this->redChipsText->setPosition(sf::Vector2f(20, 1010));

  this->yellowChipsText = new sf::Text("Yellow Chips: 21", *font, 32U);
  this->yellowChipsText->setFillColor(sf::Color::Yellow);
  this->yellowChipsText->setPosition(
      sf::Vector2f(this->yellowChipsText->getGlobalBounds().width + 1370, 990));

  bgTexture.loadFromFile("assets/connect4_bg.jpg");
  bgImage.setTexture(bgTexture);

  gridTexture.loadFromFile("assets/connect4_board.png");
  gridImage.setTexture(gridTexture);
  /* gridImage.setOrigin(gridRect.left + gridRect.width / 2.0f, */
  /*                   gridRect.top + gridRect.height / 2.0f); */
  gridImage.setPosition(sf::Vector2f(580, 240));
}

void connect4_game::ProcessInput(sf::Event event) {
  int X = event.mouseButton.x;
  int Y = event.mouseButton.y;

  if (event.type == sf::Event::MouseButtonPressed) {
    if (event.mouseButton.button == sf::Mouse::Left && redTurn == true) {
      isRed = true;

      /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
      this->manager.AddEntity("Red Chip", new Chip(X - 30, Y - 30, isRed));

      // TODO: the rectangle must be created for every entity generated
      this->rectangle.setSize(sf::Vector2f(80, 80));
      this->rectangle.setOutlineColor(sf::Color::Red);
      this->rectangle.setFillColor(sf::Color::Transparent);
      this->rectangle.setOutlineThickness(5);

      this->rectangle.setPosition(X - 30, Y - 30);

      redTurn = false;
      yellowTurn = true;
    } else if (event.mouseButton.button == sf::Mouse::Left &&
               redTurn == false) {
      isRed = false;

      /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
      this->manager.AddEntity("Yellow Chip", new Chip(X - 30, Y - 30, isRed));

      yellowTurn = false;
      redTurn = true;
    }
  }

  this->manager.ProcessInput();
}

void connect4_game::Update(sf::RenderWindow* window) {
  if (redCount == 0 && yellowCount == 0) {
    this->redChipsText->setString("Red Chips: 0");
    this->yellowChipsText->setString("Yellow Chips: 0");
  } else {
    this->redChipsText->setString("Red Chips: " + std::to_string(redCount));
    this->yellowChipsText->setString("Yellow Chips: " +
                                     std::to_string(yellowCount));
  }

  this->manager.Update();
}

void connect4_game::Render(sf::RenderWindow* window) {
  window->draw(bgImage);
  this->manager.Render(window);
  window->draw(gridImage);
  window->draw(*this->connect4Text);
  window->draw(*this->redChipsText);
  window->draw(*this->yellowChipsText);
  window->draw(rectangle);
}

void connect4_game::Destroy(sf::RenderWindow* window) {}
