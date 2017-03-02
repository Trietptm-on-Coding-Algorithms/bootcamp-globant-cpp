#include "stdafx.h"
#include "player.h"


player::player(int x, int y, sf::Keyboard::Key up, sf::Keyboard::Key down) {
	this->up = up;
	this->down = down;
	myTab = new tab(x,y);
	this->id = this->idCounter;
	idCounter++;
}
player::player() {

}
player::~player() {
	delete myTab;
}


void player::addScore() {
	score++;
}
int player::getScore() {
	return score;
}
void player::pressedUp(int dt) {
	myTab->moveUp(dt);
}
void player::pressedDown(int dt) {
	myTab->moveDown(dt);
}

tab* player::getTab() {
	return myTab;
}

int player::getID() {
	return id;
}

sf::Keyboard::Key player::getUp() {
	return up;
}
sf::Keyboard::Key player::getDown() {
	return down;
}

void player::pUpdate(int dt) {

}