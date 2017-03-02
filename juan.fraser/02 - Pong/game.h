#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.h"

class game {

private:

	static const int playersAmount = 2;
	static sf::RenderWindow* rw;
	int maxScore;
	player players[playersAmount];

public:
	game(const int maxScore, sf::RenderWindow* rw);
	~game();

	int run();
	void input();
	void update(int dt);
	void render();

};