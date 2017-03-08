#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "Ball.h"

using namespace std;

enum State {
	START, PLAY_TIME, PREP_TIME, END
};

class Game
{
private:
	sf::RenderWindow* w;

	vector<Player*> players;
	vector<Ball*> balls;
	string message;

	int getScreenX();
	int getScreenY();

	void input();
	bool update(int ms);
	void render();

	void renderMessage();
public:
	int run();
	Game(sf::RenderWindow* rw);
	~Game();
};

