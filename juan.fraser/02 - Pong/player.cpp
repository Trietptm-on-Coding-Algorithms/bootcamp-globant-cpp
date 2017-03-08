#include "stdafx.h"
#include "Player.h"

sf::Shape* Player::getShape() {	return this->getUpdatedShape(this->getPos());	}

void Player::updatePos(int ms)
{
	bool up = this->isUpPressed();
	bool down = this->isDownPressed();
	if (up && !down) {
		sf::Vector2f pos = this->getPos();
		pos.y -= getPosAdjustment()*ms;
		XYPosition::updateXYPos(pos);
	}
	else if (down && !up) {
		sf::Vector2f pos = this->getPos();
		pos.y += getPosAdjustment()*ms;
		XYPosition::updateXYPos(pos);
	}
}
void Player::collision(float yMin, float yMax)
{
	float x = this->getPos().x;
	float y = this->getPos().y;
	float height = this->getShape()->getGlobalBounds().height;
	if (y < yMin) {
		this->jumpPos(sf::Vector2f(x, yMin));
	}
	else if (y > yMax - height) {
		this->jumpPos(sf::Vector2f(x, yMax - height));
	}
}

void Player::reset() {
	this->resetPoints();
	this->jumpPos(initPos);
}

Player::Player(string name, sf::Vector2f size, sf::Vector2f pos, sf::Keyboard::Key up, sf::Keyboard::Key down)
	: Presence( new sf::RectangleShape(size))
	, XYPosition(pos)
	, ReceivesVInput(up, down)
{
	this->name = name;
	this->initPos = pos;
}


Player::~Player()
{
	killPresence();
}
