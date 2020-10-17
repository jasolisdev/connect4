#include "../include/connect4_chip.h"
#include "../include/connect4_game.h"
#include "../include/connect4_gamestate.h"

#include <iostream>

using namespace std;

connect4_gamestate *coreState;

bool exitGame = false;
bool redTurn = true;
bool blackTurn = false;
bool isRed = false;

int main() {
  sf::Vector2i screenDimensions(780, 750);
  sf::RenderWindow window;
  window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y),
                "Connect4");

  /* window.setVerticalSyncEnabled(true); */
  window.setFramerateLimit(120);

  sf::Texture bgTexture;
  sf::Sprite bImage;

  if (!bgTexture.loadFromFile("assets/s01.png"))
    std::cout << "Could not find s01.png" << std::endl;
  bImage.setTexture(bgTexture);
  bImage.setScale(1.0f, (float)screenDimensions.y / bgTexture.getSize().y);

  sf::Clock clock;

  // Create Main Menu Window
  coreState = new connect4_gamestate(&window);
  coreState->SetState(new connect4_game());

  // Main Loop
  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      int X = event.mouseButton.x;
      int Y = event.mouseButton.y;

      if (sf::Event::MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Left && redTurn == true) {
        isRed = true;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        coreState->state->manager.AddEntity("Red Chip", new Chip(X, Y, isRed));

        redTurn = false;
        blackTurn = true;
      }
      if (sf::Event::MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Right && blackTurn == true) {
        isRed = false;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        coreState->state->manager.AddEntity("Black Chip",
                                            new Chip(X, Y, isRed));

        blackTurn = false;
        redTurn = true;
      }
    }

    // FrameRate Clock
    sf::Time time = clock.getElapsedTime();
    /* std::cout << 1.0f / time.asSeconds() << std::endl; */
    clock.restart().asSeconds();

    window.clear(sf::Color::White);

    if (exitGame) {
      window.close();
    }

    window.draw(bImage);
    coreState->Update();
    window.display();
  }

  return 0;
}
