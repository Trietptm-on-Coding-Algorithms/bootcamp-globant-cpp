#include "stdafx.h"
#include "Game.h"
#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Ball.h"
#include "Jugador.h"
#include <iostream>


Menu::Menu(float widght, float height)
{
	const int size = 42;

	font.loadFromFile("STENCIL.ttf");

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setCharacterSize(size);
	menu[0].setPosition(sf::Vector2f(widght/2.5 , height/2 ));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Yellow);
	menu[1].setString("Opcion");
	menu[1].setCharacterSize(size);
	menu[1].setPosition(sf::Vector2f(widght /2.5, height / 2  * 1.25));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Yellow);
	menu[2].setString("Exit");
	menu[2].setCharacterSize(size);
	menu[2].setPosition(sf::Vector2f(widght /2.5, height / 2 * 1.5));

	opcion_posicion = 0 ;

}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MENU_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::MoveUp()
{
	if (opcion_posicion - 1 >= 0)
	{
		menu[opcion_posicion].setFillColor(sf::Color::Yellow);
		opcion_posicion--;
		menu[opcion_posicion].setFillColor(sf::Color::Red);
	}

}
void Menu::MoveDown()
{
	if (opcion_posicion + 1 < MENU_ITEMS)
	{
		menu[opcion_posicion].setFillColor(sf::Color::Yellow);
		opcion_posicion++;
		menu[opcion_posicion].setFillColor(sf::Color::Red);
	}

}