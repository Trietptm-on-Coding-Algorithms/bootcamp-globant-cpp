#pragma once
#include <SFML/Graphics.hpp>
#include "tab.h"

using namespace std;

class ball : public sf::CircleShape
{
private:
	sf::Vector2f vel;
	sf::Vector2f pos;
	sf::Vector2f oldPos;	// for advanced collision checking

public:
	ball();
	~ball();

	sf::Vector2f getSpeed();
	void setSpeedX(float x);
	void setSpeedY(float y);
	void setSpeed(float x, float y);

	bool isColliding(const tab& tab);
	bool isColliding(const ball& ball);

	void setPosition(const sf::Vector2f& pos);
	void setPosition(float x, float y);
	void move(const sf::Vector2f& by);
	void move(float x, float y);
};

