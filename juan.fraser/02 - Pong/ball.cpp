#include "stdafx.h"
#include "ball.h"


ball::ball()
{
}


ball::~ball()
{
}


sf::Vector2f ball::getSpeed() {	return vel;	}
void ball::setSpeedX(float x) {	vel.x = x;	}
void ball::setSpeedY(float y) { vel.y = y; }
void ball::setSpeed(float x, float y) {
	vel.x = x;
	vel.y = y;
}

bool ball::isColliding(const tab& tab) {
	return getGlobalBounds().intersects(tab.getGlobalBounds());
}
bool ball::isColliding(const ball& ball) {
	const sf::Vector2f otherPos = ball.getPosition();
	float distance = sqrt(powf(otherPos.x - pos.x, 2) + powf(otherPos.y - pos.y, 2));
	return (distance <= ball.getRadius() + this->getRadius());
}

void ball::setPosition(const sf::Vector2f& pos) {
	setPosition(pos.x, pos.y);
}
void ball::setPosition(float x, float y) {
	oldPos = pos;
	pos.x = x;
	pos.y = y;
	sf::CircleShape setPosition(x, y);
}
void ball::move(const sf::Vector2f& by) {
	move(by.x, by.y);
}
void ball::move(float x, float y) {
	sf::Vector2f val = getPosition();
	setPosition(x + val.x, y + val.y);
}

