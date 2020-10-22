#ifndef CONNECT4_CHIP_H
#define CONNECT4_CHIP_H

#include "Entity.h"

extern int redCount;
extern int yellowCount;

class Chip : public Entity {
 public:
  Chip(float x, float y, bool isColor);
  void Update();

 private:
  bool leftMouseButton;
  sf::RenderWindow* window;
};

#endif /* ifndef CONNECT4_CHIP_H */
