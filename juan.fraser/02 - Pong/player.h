#pragma once
#include "tab.h"

using namespace std;

class player
{
private:
	tab myTab;
	int score;
	sf::Keyboard::Key up;
	sf::Keyboard::Key down;
	bool isLeft;

public:
	player(sf::Keyboard::Key up, sf::Keyboard::Key down);
	~player();
	
	void reset();
	void addScore();
	int getScore();
	void pressedUp(float dt);
	void pressedDown(float dt);

};

