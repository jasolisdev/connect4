#ifndef CONNECT4_BOX_H
#define CONNECT4_BOX_H

#include "Entity.h"

class Box : public Entity, public sf::RectangleShape {
public:
  Box(float x, float y, bool isEmpty, bool isFilled);
  void Update();
  void Render(sf::RenderWindow *window);

private:
  bool leftMouseButton;
  sf::RenderWindow *window;
  sf::RectangleShape box;
};

#endif /* ifndef CONNECT4_BOX_H */
