#ifndef CONNECT4_PLAYER_H
#define CONNECT4_PLAYER_H 

#include "Entity.h"

class Player: public Entity
{
public:
	Player();
	void Update();
private:
	bool upKey, downKey, leftKey, rightKey, spaceKey, leftMouseButton;
};

#endif /* ifndef CONNECT4_PLAYER_H */
