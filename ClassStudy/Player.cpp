#include <iostream>
#include "Player.h"

Player::Player() {};
Player::~Player() {};

void Player::Move(int inX, int inY)
{
	x = inX;
	y = inY;
}