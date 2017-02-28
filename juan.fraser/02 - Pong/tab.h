#pragma once
#include <SFML/Graphics.hpp>

using namespace std;


class tab : public sf::RectangleShape
{
private:
	sf::Vector2f pos;
	sf::Vector2f oldPos;	// for advanced collision checking
	
	static const float minPos;
	static const float maxPos;

	static const float length;
	static const float speed;

public:
	tab();
	~tab();

	void setPosition();
	void moveUp(float dt);
	void moveDown(float dt);


	

};

