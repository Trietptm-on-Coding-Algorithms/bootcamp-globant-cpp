#pragma once
#include <SFML\Graphics.hpp>


const int MENU_ITEMS = 3;

class Menu
{
	public:
		Menu(float widght,float height);
		~Menu();
		void draw(sf::RenderWindow &window);
		void MoveUp();
		void MoveDown();
		int GetPressedItem() { return opcion_posicion; };

	private:
		int opcion_posicion;
		sf::Font font;
		sf::Text menu[MENU_ITEMS];
};

