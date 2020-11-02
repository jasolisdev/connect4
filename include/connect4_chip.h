#ifndef CONNECT4_CHIP_H
#define CONNECT4_CHIP_H

#include "Entity.h"

class Chip : public Entity {
public:
  Chip(float x, float y, bool isColor);
  void Update();

private:
  bool leftMouseButton;
  sf::RenderWindow *window;
};

extern size_t redCount;
extern size_t yellowCount;

#endif /* ifndef CONNECT4_CHIP_H */
