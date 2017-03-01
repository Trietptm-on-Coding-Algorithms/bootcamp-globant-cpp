#pragma once
#include<SFML\Graphics.hpp>

class Jugador
{
	public:
		Jugador(const sf::Texture &texture);
		~Jugador();
		void draw(sf::RenderWindow &window);
		void moved(float speedX, float speedY);
		void setPosition(float posX, float posY);
		float getGlobalLeft();
		float getGlobalRight();
		float getGlobalTop();
		float getGlobalBottom();
		bool collisionX(int X);
		bool collisionY(int Y);
	
	private:
		sf::Sprite sprite;
};

