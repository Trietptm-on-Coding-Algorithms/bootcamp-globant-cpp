#pragma once
#include "SFML/Graphics.hpp"

class XYPosition
{
private:
	static float posAdjustment;

	sf::Vector2f pos;
	sf::Vector2f oldPos;
	void setPos(sf::Vector2f newPos);
	void setOldPos(sf::Vector2f newOldPos);
public:
	static float getPosAdjustment();
	static void setPosAdjustment(float newPosA);

	sf::Vector2f getPos();
	sf::Vector2f getOldPos();
	void jumpPos(sf::Vector2f newPos);
	void updateXYPos(sf::Vector2f newPos);

	XYPosition(sf::Vector2f pos);
	~XYPosition();
};

