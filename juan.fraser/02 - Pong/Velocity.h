#pragma once
#include "SFML\Graphics.hpp"
#include "XYPosition.h"

class Velocity
{
private:
	sf::Vector2f vel;
	static float velAdjustment;
public:
	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f newVel);
	static float getVelAdjustment();
	static void setVelAdjustment(float newVelA);

	void move(XYPosition* pos, int ms);

	Velocity(sf::Vector2f vel);
	~Velocity();
};

