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

const size_t numberOfColumns = 7;
const size_t numberOfRows = 6;

void connect4_game::Initialize(sf::RenderWindow* window) {
  buffer.loadFromFile("assets/chipPlaced.wav");
  dropSound.setBuffer(buffer);
  dropSound.setVolume(50);

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

  redTurnTexture.loadFromFile("assets/redturn.png");
  redTurnImage.setTexture(redTurnTexture);
  redTurnImage.setPosition(40, 400);
  redTurnImage.setScale(.7f, .7f);

  yellowTurnTexture.loadFromFile("assets/yellowturn.png");
  yellowTurnImage.setTexture(yellowTurnTexture);
  yellowTurnImage.setPosition(1440, 400);
  yellowTurnImage.setScale(.7f, .7f);

  grayTexture.loadFromFile("assets/gray.png");
  grayImage.setTexture(grayTexture);
  grayImage.setScale(.7f, .7f);

  gridTexture.loadFromFile("assets/connect4_board.png");
  gridImage.setTexture(gridTexture);
  gridImage.setScale(1.2f, 1.2f);
  gridImage.setPosition(sf::Vector2f(480, 140));

  // Bounding Boxes for spawning chip entities
  this->column1.setSize(sf::Vector2f(98, 660));
  this->column1.setOutlineColor(sf::Color::Magenta);
  this->column1.setFillColor(sf::Color::Transparent);
  this->column1.setOutlineThickness(5);
  this->column1.setPosition(573, 275);

  this->column2.setSize(sf::Vector2f(98, 660));
  this->column2.setOutlineColor(sf::Color::Magenta);
  this->column2.setFillColor(sf::Color::Transparent);
  this->column2.setOutlineThickness(5);
  this->column2.setPosition(683, 275);

  this->column3.setSize(sf::Vector2f(98, 660));
  this->column3.setOutlineColor(sf::Color::Magenta);
  this->column3.setFillColor(sf::Color::Transparent);
  this->column3.setOutlineThickness(5);
  this->column3.setPosition(793, 275);

  this->column4.setSize(sf::Vector2f(98, 660));
  this->column4.setOutlineColor(sf::Color::Magenta);
  this->column4.setFillColor(sf::Color::Transparent);
  this->column4.setOutlineThickness(5);
  this->column4.setPosition(903, 275);

  this->column5.setSize(sf::Vector2f(98, 660));
  this->column5.setOutlineColor(sf::Color::Magenta);
  this->column5.setFillColor(sf::Color::Transparent);
  this->column5.setOutlineThickness(5);
  this->column5.setPosition(1013, 275);

  this->column6.setSize(sf::Vector2f(98, 660));
  this->column6.setOutlineColor(sf::Color::Magenta);
  this->column6.setFillColor(sf::Color::Transparent);
  this->column6.setOutlineThickness(5);
  this->column6.setPosition(1123, 275);

  this->column7.setSize(sf::Vector2f(94, 660));
  this->column7.setOutlineColor(sf::Color::Magenta);
  this->column7.setFillColor(sf::Color::Transparent);
  this->column7.setOutlineThickness(5);
  this->column7.setPosition(1233, 275);

  gridSize = sf::Vector2f(gridImage.getLocalBounds().width / numberOfColumns,
                          gridImage.getLocalBounds().height / numberOfRows);

  for (int x = 0; x < numberOfColumns; x++) {
    for (int y = 0; y < numberOfRows; y++) {
      sf::RectangleShape cell(gridSize);

      cell.setFillColor(sf::Color::Transparent);
      cell.setOutlineColor(sf::Color::Green);
      cell.setOutlineThickness(3);
      cell.setSize(sf::Vector2f(100, 100));
      cell.setPosition(((gridSize.x) * x) + 565, ((gridSize.y - 15) * y) + 275);

      grid.push_back(cell);
    }
  }
}
void connect4_game::ProcessInput(sf::RenderWindow* window, sf::Event event) {
  int X = event.mouseButton.x;
  int Y = event.mouseButton.y;

  if (event.type == sf::Event::MouseButtonPressed) {
    if (event.mouseButton.button == sf::Mouse::Left && redTurn == true) {
      if (column1.getGlobalBounds().contains(
              window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 1\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = true;
        this->manager.AddEntity("Red Chip", new Chip(575, 150, isRed));
        dropSound.play();
        /* this->manager.AddEntity("Box", new Box(570, 150)); */

      } else if (column2.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 2\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = true;
        this->manager.AddEntity("Red Chip", new Chip(685, 150, isRed));
        dropSound.play();
      } else if (column3.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 3\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = true;
        this->manager.AddEntity("Red Chip", new Chip(795, 150, isRed));
        dropSound.play();
      } else if (column4.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 4\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = true;
        this->manager.AddEntity("Red Chip", new Chip(905, 150, isRed));
        dropSound.play();
      } else if (column5.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 5\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = true;
        this->manager.AddEntity("Red Chip", new Chip(1015, 150, isRed));
        dropSound.play();
      } else if (column6.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 6\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = true;
        this->manager.AddEntity("Red Chip", new Chip(1125, 150, isRed));
        dropSound.play();
      } else if (column7.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 7\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = true;
        this->manager.AddEntity("Red Chip", new Chip(1235, 150, isRed));
        dropSound.play();
      }

      redTurn = false;
      yellowTurn = true;

    } else if (event.mouseButton.button == sf::Mouse::Left &&
               redTurn == false) {
      if (column1.getGlobalBounds().contains(
              window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 1\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = false;
        this->manager.AddEntity("Yellow Chip", new Chip(575, 150, isRed));
        dropSound.play();
      } else if (column2.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 2\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = false;
        this->manager.AddEntity("Yellow Chip", new Chip(685, 150, isRed));
        dropSound.play();
      } else if (column3.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 3\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = false;
        this->manager.AddEntity("Yellow Chip", new Chip(795, 150, isRed));
        dropSound.play();
      } else if (column4.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 4\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = false;
        this->manager.AddEntity("Yellow Chip", new Chip(905, 150, isRed));
        dropSound.play();
      } else if (column5.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 5\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = false;
        this->manager.AddEntity("Yellow Chip", new Chip(1015, 150, isRed));
        dropSound.play();
      } else if (column6.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 6\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = false;
        this->manager.AddEntity("Yellow Chip", new Chip(1125, 150, isRed));
        dropSound.play();
      } else if (column7.getGlobalBounds().contains(window->mapPixelToCoords(
                     sf::Mouse::getPosition(*window)))) {
        /* std::cout << "Mouse Clicked on Column 7\n"; */
        /* std::cout << "X: " << X << " Y: " << Y << std::endl; */
        isRed = false;
        this->manager.AddEntity("Yellow Chip", new Chip(1235, 150, isRed));
        dropSound.play();
      }

      yellowTurn = false;
      redTurn = true;
    }
  }

  // * * * * * * *
  // * * * * * * *
  // * * * * * * *
  // * * * * * * *
  // * * * * * * *
  // * * * * * * * <- create loop to access the box/cells.

  // Each box/cell will start with a bool isEmpty
  // As the chip entity falls down the column, every time it intersects with a
  // cell it will check if it isEmpty or isFilled. If cell isEmpty, the chip
  // will continue to fall until it reaches a cell that contains a bool
  // isFilled. The bottom row will all have bool isBottom
  // to indicate that it is the bottom cell and to not let the chip go out of
  // bounds.
  // If a chip entity encounters a cell that isFilled, it will stop the move
  // action and its position will be set. That cell will then have the bool
  // isFilled set to true.
  // If a chip entity encounters a cell with a isFilled set to true, it will
  // check if isRedChip is set to true and if it is, it will a int fourConnected
  // counter.
  // When int fourConnected == 4, game is over.

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

  if (!isRed) {
    grayImage.setPosition(1440, 400);
    window->draw(grayImage);
    window->draw(redTurnImage);
  } else {
    grayImage.setPosition(40, 400);
    window->draw(grayImage);
    window->draw(yellowTurnImage);
  }

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

  for (auto boundingBox : grid) {
    window->draw(boundingBox);
  }
}

void connect4_game::Destroy(sf::RenderWindow* window) {}
