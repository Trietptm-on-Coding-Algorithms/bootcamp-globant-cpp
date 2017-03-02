#include "stdafx.h"
#include "Score.h"


Score::Score()
{
	font.loadFromFile("STENCIL.ttf");
	
	const int sizescore = 33;
	const int sizemenu = 30;
	const int posY = 40.0;
	int ValueRed = 255;
	int ValueGreen = 69;
	int ValueBlue=0;
	int ValueOpacity =255;

	score[0].setFont(font);
	score[0].setFillColor(sf::Color::Color(ValueRed,ValueGreen,ValueBlue,ValueOpacity));
	score[0].setString("0");
	score[0].setCharacterSize(sizescore);
	score[0].setPosition(sf::Vector2f(70.0, posY));

	score[1].setFont(font);
	score[1].setFillColor(sf::Color::Color(ValueRed, ValueGreen, ValueBlue, ValueOpacity));
	score[1].setString("Player1  SCORE  Player2  ");
	score[1].setCharacterSize(sizemenu);
	score[1].setPosition(sf::Vector2f(190.0, posY));

	score[2].setFont(font);
	score[2].setFillColor(sf::Color::Color(ValueRed, ValueGreen, ValueBlue, ValueOpacity));
	score[2].setString("0");
	score[2].setCharacterSize(sizescore);
	score[2].setPosition(sf::Vector2f(630.0, posY));
}


Score::~Score()
{

}
void Score::LoadScore(int i,int j)
{
	std::string str1 = std::to_string(i);
	std::string str2 = std::to_string(j);
	score[0].setString(str1);
	score[2].setString(str2);
}


void Score::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < SCORE_ITEM; i++)
	{
		window.draw(score[i]);
	}
}
