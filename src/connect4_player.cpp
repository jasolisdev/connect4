#include "../include/connect4_player.h"
#include "../include/connect4_gamestate.h"
#include "../include/connect4_chip.h"

#include <iostream>

Player::Player()
{
    this->group_id = 3;
	this->Load("assets/chip.png", sf::IntRect(0, 0, 0, 0));
	this->setPosition(100, 300);
}

void Player::Update()
{
}
