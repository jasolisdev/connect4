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

  this->column1.setSize(sf::Vector2f(80, 640));
  this->column1.setOutlineColor(sf::Color::Magenta);
  this->column1.setFillColor(sf::Color::Transparent);
  this->column1.setOutlineThickness(5);
  this->column1.setPosition(655, 260);

  this->column2.setSize(sf::Vector2f(80, 640));
  this->column2.setOutlineColor(sf::Color::Magenta);
  this->column2.setFillColor(sf::Color::Transparent);
  this->column2.setOutlineThickness(5);
  this->column2.setPosition(748, 260);

  this->column3.setSize(sf::Vector2f(80, 640));
  this->column3.setOutlineColor(sf::Color::Magenta);
  this->column3.setFillColor(sf::Color::Transparent);
  this->column3.setOutlineThickness(5);
  this->column3.setPosition(840, 260);

  this->column4.setSize(sf::Vector2f(80, 640));
  this->column4.setOutlineColor(sf::Color::Magenta);
  this->column4.setFillColor(sf::Color::Transparent);
  this->column4.setOutlineThickness(5);
  this->column4.setPosition(930, 260);

  this->column5.setSize(sf::Vector2f(80, 640));
  this->column5.setOutlineColor(sf::Color::Magenta);
  this->column5.setFillColor(sf::Color::Transparent);
  this->column5.setOutlineThickness(5);
  this->column5.setPosition(1023, 260);

  this->column6.setSize(sf::Vector2f(80, 640));
  this->column6.setOutlineColor(sf::Color::Magenta);
  this->column6.setFillColor(sf::Color::Transparent);
  this->column6.setOutlineThickness(5);
  this->column6.setPosition(1115, 260);

  this->column7.setSize(sf::Vector2f(80, 640));
  this->column7.setOutlineColor(sf::Color::Magenta);
  this->column7.setFillColor(sf::Color::Transparent);
  this->column7.setOutlineThickness(5);
  this->column7.setPosition(1208, 260);
}

void connect4_game::ProcessInput(sf::RenderWindow* window, sf::Event event) {
  int X = event.mouseButton.x;
  int Y = event.mouseButton.y;

  if (event.type == sf::Event::MouseButtonPressed) {
    if (event.mouseButton.button == sf::Mouse::Left && redTurn == true) {
      if (column1.getGlobalBounds().contains(
              window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 1\n";

        isRed = true;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Red Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Red Chip", new Chip(655, 260, isRed));
      } else if (column2.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 2\n";

        isRed = true;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Red Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Red Chip", new Chip(748, 260, isRed));
      } else if (column3.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 3\n";

        isRed = true;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Red Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Red Chip", new Chip(840, 260, isRed));
      } else if (column4.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 4\n";

        isRed = true;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Red Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Red Chip", new Chip(930, 260, isRed));
      } else if (column5.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 5\n";

        isRed = true;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Red Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Red Chip", new Chip(1023, 260, isRed));
      } else if (column6.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 6\n";

        isRed = true;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Red Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Red Chip", new Chip(1115, 260, isRed));
      } else if (column7.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 7\n";

        isRed = true;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Red Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Red Chip", new Chip(1208, 260, isRed));
      }

      redTurn = false;
      yellowTurn = true;

    } else if (event.mouseButton.button == sf::Mouse::Left &&
               redTurn == false) {
      if (column1.getGlobalBounds().contains(
              window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 1\n";

        isRed = false;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Yellow Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Yellow Chip", new Chip(655, 260, isRed));
      } else if (column2.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 2\n";

        isRed = false;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Yellow Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Yellow Chip", new Chip(748, 260, isRed));
      } else if (column3.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 3\n";

        isRed = false;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Yellow Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Yellow Chip", new Chip(840, 260, isRed));
      } else if (column4.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 4\n";

        isRed = false;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Yellow Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Yellow Chip", new Chip(930, 260, isRed));
      } else if (column5.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 5\n";

        isRed = false;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Yellow Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Yellow Chip", new Chip(1023, 260, isRed));
      } else if (column6.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 6\n";

        isRed = false;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Yellow Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Yellow Chip", new Chip(1115, 260, isRed));
      } else if (column7.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        std::cout << "Mouse Clicked on Column 7\n";

        isRed = false;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        // this->manager.AddEntity("Yellow Chip", new Chip(X - 30.f, Y - 30.f,
        // isRed));
        this->manager.AddEntity("Yellow Chip", new Chip(1208, 260, isRed));
      }

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
  window->draw(column1);
  window->draw(column2);
  window->draw(column3);
  window->draw(column4);
  window->draw(column5);
  window->draw(column6);
  window->draw(column7);
}

void connect4_game::Destroy(sf::RenderWindow* window) {}
