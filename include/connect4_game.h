#ifndef CONNECT4_GAME_H
#define CONNECT4_GAME_H

#include <SFML/Audio.hpp>

#include "EntityManager.h"
#include "connect4_gamestate.h"

class connect4_game : public tiny_state {
 public:
  connect4_game() {}
  void Initialize(sf::RenderWindow* window);
  void ProcessInput(sf::RenderWindow* window, sf::Event event);
  void Update(sf::RenderWindow* window);
  void Render(sf::RenderWindow* window);
  void Destroy(sf::RenderWindow* window);

 private:
  sf::FloatRect textRect;

  sf::RectangleShape column1;
  sf::RectangleShape column2;
  sf::RectangleShape column3;
  sf::RectangleShape column4;
  sf::RectangleShape column5;
  sf::RectangleShape column6;
  sf::RectangleShape column7;

  sf::Text* connect4Text;
  sf::Text* redChipsText;
  sf::Text* yellowChipsText;

  sf::Texture bgTexture;
  sf::Sprite bgImage;

  sf::Texture redTurnTexture;
  sf::Sprite redTurnImage;

  sf::Texture yellowTurnTexture;
  sf::Sprite yellowTurnImage;

  sf::Texture grayTexture;
  sf::Sprite grayImage;

  sf::Texture gridTexture;
  sf::Sprite gridImage;
  sf::View view;

  sf::SoundBuffer buffer;
  sf::Sound dropSound;

  std::vector<sf::RectangleShape> grid;
  sf::Vector2f gridSize;
};

#endif /* ifndef CONNECT4_GAME_H */
