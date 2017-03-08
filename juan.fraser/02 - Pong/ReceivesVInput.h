#pragma once
#include "SFML/Graphics.hpp"

class ReceivesVInput
{
private:
	sf::Keyboard::Key up;
	sf::Keyboard::Key down;
	bool upPressed;
	bool downPressed;
	
	void setUp(sf::Keyboard::Key up);
	void setDown(sf::Keyboard::Key down);
	sf::Keyboard::Key getUp();
	sf::Keyboard::Key getDown();
public:
	bool isUpPressed();
	bool isDownPressed();
	void updateInput();

	ReceivesVInput(sf::Keyboard::Key up, sf::Keyboard::Key down);
	~ReceivesVInput();
};

