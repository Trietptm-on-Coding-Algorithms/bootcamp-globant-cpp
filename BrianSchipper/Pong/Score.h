#pragma once
#include <SFML\Graphics.hpp>

const int SCORE_ITEM = 3;

class Score
{
public:
	Score();
	~Score();
	void draw(sf::RenderWindow &window);
	void LoadScore(int i,int j);

private:
	sf::Font font;
	sf::Text score[SCORE_ITEM];
};

