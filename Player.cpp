#include "Player.h"

Player::Player(string _n, color _C)
{
	this-> name = _n;
	this->C = _C;
}

string Player::getName()
{
	return name;
}

color Player::getColor()
{
	return C;
}
