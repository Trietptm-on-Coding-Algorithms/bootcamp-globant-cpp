#pragma once
#include <SFML\Graphics.hpp>
#include "Jugador.h"


class Ball
{
	public:
		Ball(const sf::Texture &texture);
		~Ball();
		void draw(sf::RenderWindow &window);
		void moved(float speedX, float speedY);
		bool collisionLeft();
		bool collisionRight(int WallX);
		bool collisionY(int wallY);
		void position(float posX, float posY);
		sf::Vector2f getPosicion();
		bool intersectionSide1(Jugador &player);
		bool intersectionSide2(Jugador &player);
		bool intersectionExtreme1(Jugador &player);
		bool intersectionExtreme2(Jugador &player);
		
	private:
		sf::Sprite sprite;
		double speedX, speedY;

};

