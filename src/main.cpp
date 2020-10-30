#if (!DEBUG)
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include "../include/connect4_game.h"
#include "../include/connect4_gamestate.h"

connect4_gamestate *coreState;

bool exitGame = false;

int main() {
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Connect4");

  // Create Game State Window
  coreState = new connect4_gamestate(&window);
  coreState->SetState(new connect4_game());

  // Main Game Loop
  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // resize my view
      // if (event.type == sf::Event::Resized) {
      //   view.setSize({static_cast<float>(event.size.width),
      //                 static_cast<float>(event.size.height)});
      //   window.setView(view);
      // }

      coreState->ProcessInput(&window, event);
    }

    if (exitGame) {
      window.close();
    }

    window.clear();

    coreState->Render();
    coreState->Update();

    window.display();
  }

  return 0;
}
