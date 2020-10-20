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
  sf::FloatRect textRect;
  sf::FloatRect gridRect;

  sf::RectangleShape rectangle;
  
  sf::Text* connect4Text;
  sf::Text* redChipsText;
  sf::Text* yellowChipsText;

  sf::Texture bgTexture;
  sf::Sprite bgImage;

  sf::Texture gridTexture;
  sf::Sprite gridImage;
  sf::View view;
};

#endif /* ifndef CONNECT4_GAME_H */
