#ifndef CONNECT4_GAME_H
#define CONNECT4_GAME_H

#include "EntityManager.h"
#include "connect4_gamestate.h"
#include "connect4_player.h"

class connect4_game : public tiny_state {
 public:
  connect4_game() {}
  void Initialize(sf::RenderWindow* window);
  void ProcessInput(sf::Event event);
  void Update(sf::RenderWindow* window);
  void Render(sf::RenderWindow* window);
  void Destroy(sf::RenderWindow* window);

 private:
  sf::Text* redChipsText;
  sf::Text* blackChipsText;
};

#endif /* ifndef CONNECT4_GAME_H */
