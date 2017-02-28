#pragma once
#include <SFML/Graphics.hpp>


class game {

private:
	static const sf::RenderWindow *rw;
	int maxScore;

public:
	game(int maxScore, const sf::RenderWindow& rw);
	~game();

	void run();

};

