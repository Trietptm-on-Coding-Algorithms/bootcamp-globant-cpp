#pragma once
#include "SFML\Graphics.hpp"
#include "Presence.h"
#include "Velocity.h"
#include "XYPosition.h"

class Ball : Presence, Velocity, XYPosition
{
private:
	sf::Vector2f startPosition;
	float startVelocity;
	
public:
	void updatePos(int ms);
	void wallCollision(float yMin, float yMax);
	void objectCollision(sf::Shape* obj);
	int edgeCollision(float xMin, float xMax);

	void reset();
	sf::Vector2f randomVel();

	sf::Shape* Ball::getShape();
	Ball(float radius, sf::Vector2f vel, sf::Vector2f pos);
	~Ball();
};

