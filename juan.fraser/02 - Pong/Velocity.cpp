#include "stdafx.h"
#include "Velocity.h"

float Velocity::velAdjustment = 1;

sf::Vector2f Velocity::getVelocity() { return this->vel; }
void Velocity::setVelocity(sf::Vector2f newVel) { this->vel = newVel; }

float Velocity::getVelAdjustment() { return velAdjustment; }
void Velocity::setVelAdjustment(float newVelA) { velAdjustment = newVelA; }

void Velocity::move(XYPosition* pos, int ms)
{
	sf::Vector2f p = pos->getPos();
	p.x = p.x + this->getVelocity().x * getVelAdjustment() * ms;
	p.y = p.y + this->getVelocity().y * getVelAdjustment() * ms;
	pos->updateXYPos(p);
}

Velocity::Velocity(sf::Vector2f vel)
{
	setVelocity(vel);
}


Velocity::~Velocity()
{
}
