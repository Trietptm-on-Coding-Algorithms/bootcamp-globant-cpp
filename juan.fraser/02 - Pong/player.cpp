#include "stdafx.h"
#include "player.h"


player::player(sf::Keyboard::Key up, sf::Keyboard::Key down) {
	this->up = up;
	this->down = down;
	myTab = tab();
}


player::~player()
{
}


void player::reset() {
	myTab = tab();
	score = 0;
}
void player::addScore() {
	score++;
}
int player::getScore() {
	return score;
}
void player::pressedUp(float dt) {
	myTab.moveUp(dt);
}
void player::pressedDown(float dt) {
	myTab.moveDown(dt);
}
