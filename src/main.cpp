#include <iostream>

#include "../include/connect4_chip.h"
#include "../include/connect4_game.h"
#include "../include/connect4_gamestate.h"

using namespace std;

connect4_gamestate* coreState;

bool exitGame = false;

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

      coreState->ProcessInput(event);
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
    coreState->Render();
    coreState->Update();
    window.display();
  }

  return 0;
}
