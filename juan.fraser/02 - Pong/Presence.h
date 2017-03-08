#pragma once
#include "SFML\Graphics.hpp"
#include "XYPosition.h"

class Presence
{
private:
	sf::Shape* s;
	sf::Shape* getShape();
public:
	sf::Shape* getUpdatedShape(XYPosition currentPos);
	
	void killPresence();
	Presence(sf::Shape *s);
	~Presence();
};

