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
	ListElement*begin() { return first; };
	void LoadList(sf::Texture &texture, ListaCircular &lista);

private:
	ListElement *last;
	ListElement *first;
};

