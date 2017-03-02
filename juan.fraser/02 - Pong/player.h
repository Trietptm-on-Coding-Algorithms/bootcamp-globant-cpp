#pragma once
#include "tab.h"


using namespace std;

class player
{
private:
	static int idCounter;
	int id;
	tab* myTab;
	int score;
	sf::Keyboard::Key up;
	sf::Keyboard::Key down;

public:
	player();
	player(int x, int y, sf::Keyboard::Key up, sf::Keyboard::Key down);
	~player();
	
	bool movingUp;
	bool movingDown;

	void addScore();
	int getScore();
	void pressedUp(int dt);
	void pressedDown(int dt);
	tab* getTab();
	int getID();
	sf::Keyboard::Key getUp();
	sf::Keyboard::Key getDown();
	void pUpdate(int dt);

};
