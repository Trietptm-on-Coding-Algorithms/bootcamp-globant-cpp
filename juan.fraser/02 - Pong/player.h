#pragma once
#include "SFML\Graphics.hpp"
#include "Presence.h"
#include "XYPosition.h"
#include "Points.h"
#include "ReceivesVInput.h"

using namespace std;

class Player : Presence, XYPosition, public Points, public ReceivesVInput
{
private:
	sf::Vector2f initPos;
public:
	string name;

	void updatePos(int ms);
	void collision(float yMin, float yMax);

	void reset();

	sf::Shape* getShape();
	Player(string name, sf::Vector2f size, sf::Vector2f pos, sf::Keyboard::Key up, sf::Keyboard::Key down);
	~Player();
};

