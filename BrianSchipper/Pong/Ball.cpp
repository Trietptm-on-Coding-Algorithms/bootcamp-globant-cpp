#include "stdafx.h"
#include "Ball.h"
#include "Jugador.h"
#include <iostream>

using namespace std;

Ball::Ball(const sf::Texture &texture):sprite(texture)
{
	sprite.setPosition(400.0f, 300.0f);
	sprite.setScale(.05f,.05f);
}


Ball::~Ball()
{

}

void Ball::moved(float speedX, float speedY)
{
	sprite.move(static_cast<float>(speedX),static_cast<float>(speedY));
	
}

void Ball::draw(sf::RenderWindow &window) 
{
	window.draw(sprite);
}

bool Ball::collisionLeft()
{
	return (sprite.getGlobalBounds().left < 0);
}
bool Ball::collisionRight(int wallX) 
{
	return (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > wallX);
}
bool Ball::collisionY(int wallY)
{
	return ((sprite.getGlobalBounds().top + sprite.getGlobalBounds().height > wallY) || (sprite.getGlobalBounds().top < 0));
}
void Ball::position(float posX, float posY)
{
	sprite.setPosition(posX, posY);
}
sf::Vector2f Ball::getPosicion()
{
	return sprite.getPosition();
}

bool Ball::intersectionSide2(Jugador &player)
{
	return ( sprite.getPosition().x + sprite.getGlobalBounds().width > player.getGlobalLeft()
		&& sprite.getPosition().y + sprite.getGlobalBounds().height / 2 < player.getGlobalBottom()
		&& sprite.getPosition().y + sprite.getGlobalBounds().height / 2 > player.getGlobalTop() );
}
bool Ball::intersectionSide1(Jugador &player)
{
	return  (sprite.getPosition().x < player.getGlobalRight()
		&& sprite.getPosition().y+ sprite.getGlobalBounds().height/2 < player.getGlobalBottom()
		&& sprite.getPosition().y +sprite.getGlobalBounds().height/2 > player.getGlobalTop()  );
}
bool Ball::intersectionExtreme1(Jugador &player)
{
	return true;
}
bool Ball::intersectionExtreme2(Jugador &player)
{
	return (sprite.getPosition().y + sprite.getGlobalBounds().height > player.getGlobalTop() 
		&& sprite.getPosition().y < player.getGlobalTop()
		&& sprite.getPosition().x + sprite.getGlobalBounds().width > player.getGlobalLeft() );
}
