#pragma once
#include <SFML\Graphics.hpp>

struct ListElement
{
	sf::Sprite val; 
	ListElement *next;
};

class ListaCircular
{
public:
	ListaCircular();
	~ListaCircular();
	ListElement*pushFront(sf::Sprite &elemval);
	void Clear();
	size_t getElementCount();
	void draw(sf::RenderWindow &window);

private:
	ListElement *last;
	ListElement *first;
	sf::Sprite sprite; 
};

