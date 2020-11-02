#ifndef CONNECT4_GG_H
#define CONNECT4_GG_H

#include "connect4_gamestate.h"

class connect4_gg : public tiny_state {
public:
  void Initialize(sf::RenderWindow *window);
  void Update(sf::RenderWindow *window);
  void Render(sf::RenderWindow *window);
  void Destroy(sf::RenderWindow *window);

private:
  sf::Font *font;
  sf::Text *gameOverText;
  bool enterKey, escapeKey;
};

extern size_t redCount;
extern size_t yellowCount;

#endif /* ifndef CONNECT4_GG_H */
