#include "stdafx.h"
#include "Ball.h"

sf::Shape* Ball::getShape() {	return this->getUpdatedShape(this->getPos()); }

void Ball::updatePos(int ms)
{
	XYPosition pos(this->getPos());
	this->move(&pos, ms);
	XYPosition::updateXYPos(pos.getPos());
}

void Ball::wallCollision(float yMin, float yMax)
{
	float y = this->getPos().y;
	float height = this->getShape()->getGlobalBounds().height;
	sf::Vector2f vel = this->getVelocity();
	if ( (y < yMin && vel.y < 0 ) || (y > yMax - height && vel.y > 0) ) {
		vel.y = -vel.y;
		this->setVelocity(vel);
	}
}
void Ball::objectCollision(sf::Shape* obj)
{
	if (this->getShape()->getGlobalBounds().intersects(obj->getGlobalBounds())) {
		

		//float x = this->getPos().x;
		//float y = this->getPos().y;
		//float height = this->getShape()->getGlobalBounds().height;
		//float height = this->getShape()->getGlobalBounds().height;
		sf::Vector2f vel = this->getVelocity();
		vel.x = -vel.x;
		vel.y = -vel.y;
		this->setVelocity(vel);



	}
	// TODO //
	// propper collision with rectangles
}

// TODO //
/*
//Collisions

if (ball.getGlobalBounds().left < rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width
&& ball.getGlobalBounds().top < rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height
&& ball.getGlobalBounds().top + ball.getGlobalBounds().height > rectangle.getGlobalBounds().top)
vx = -vx;

*/

int Ball::edgeCollision(float xMin, float xMax)
{
	float x = this->getPos().x;
	float width = this->getShape()->getGlobalBounds().width;
	sf::Vector2f vel = this->getVelocity();
	int retValue = 0;
	if (x < xMin && vel.x < 0) {
		retValue = -1;
	}
	else if (x > xMax - width && vel.x > 0) {
		retValue = 1;
	}
	return retValue;
}

void Ball::reset()
{
	this->jumpPos(startPosition);
	this->setVelocity(randomVel());
	
}

sf::Vector2f Ball::randomVel()
{
	int angle = rand() % 360;
	float s = sin(angle / 1.f);
	float c = cos(angle / 1.f);
	sf::Vector2f ret;
	if (c < 0.5f && c > -0.5f) {
		ret = sf::Vector2f(s*startVelocity, c*startVelocity);
	}
	else {
		ret = sf::Vector2f(c*startVelocity, s*startVelocity);
	}
	return ret;
	// TODO //
	// propper random
}

Ball::Ball(float radius, sf::Vector2f vel, sf::Vector2f pos) 
	: Presence(new sf::CircleShape(radius))
	, Velocity(vel)
	, XYPosition(pos)
{
	this->startPosition = pos;
	this->startVelocity = sqrt(vel.x*vel.x + vel.y*vel.y);
	srand(static_cast<unsigned int>(time(nullptr)));
}

Ball::~Ball()
{
}
