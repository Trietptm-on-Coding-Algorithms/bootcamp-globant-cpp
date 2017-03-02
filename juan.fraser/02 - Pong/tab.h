#pragma once
#include <SFML/Graphics.hpp>

using namespace std;


class tab : public sf::RectangleShape
{
private:
	sf::Vector2f pos;
	sf::Vector2f oldPos;	// for advanced collision checking
	
	int minPos;
	int maxPos;

	float length = 32.0f;
	float speed = 0.2f;

public:
	tab(int x, int y);
	~tab();

	void setPosition(float y);
	void moveUp(int dt);
	void moveDown(int dt);


	

};

