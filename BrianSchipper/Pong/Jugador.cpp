#include "stdafx.h"
#include "Jugador.h"


Jugador::Jugador(const sf::Texture &texture) :sprite(texture)
{
	sprite.setScale(.3f, .42f);
}


Jugador::~Jugador()
{
}

void Jugador::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Jugador::moved(float speedX, float speedY)
{
	sprite.move(static_cast<float>(speedX), static_cast<float>(speedY));
}
void Jugador::setPosition(float posX, float  posY) 
{
	sprite.setPosition(posX,posY);
}

bool Jugador::collisionX(int X)
{
	return ((sprite.getGlobalBounds().left < 0) || (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > X));
}

bool Jugador::collisionY(int Y)
{
	return ((sprite.getGlobalBounds().top + sprite.getGlobalBounds().height > Y) || (sprite.getGlobalBounds().top < 0));
}

float Jugador::getGlobalLeft()
{
	return  sprite.getGlobalBounds().left;
}

float Jugador::getGlobalRight()
{
	return  sprite.getGlobalBounds().left + sprite.getGlobalBounds().width;
}
float Jugador::getGlobalTop()
{
	return sprite.getGlobalBounds().top;
}
float Jugador::getGlobalBottom()
{
	return sprite.getGlobalBounds().top + sprite.getGlobalBounds().height;
}