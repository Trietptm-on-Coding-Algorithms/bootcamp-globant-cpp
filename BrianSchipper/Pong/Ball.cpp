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
	float circle_right = sprite.getPosition().x + sprite.getGlobalBounds().width;
	float circle_bottom = sprite.getPosition().y + sprite.getGlobalBounds().height;

	return ( circle_right > player.getGlobalLeft()
		&& circle_bottom < player.getGlobalBottom()
		&& circle_bottom > player.getGlobalTop() );
}
bool Ball::intersectionSide1(Jugador &player)
{
	float circle_bottom = sprite.getPosition().y + sprite.getGlobalBounds().height;

	return  (sprite.getPosition().x < player.getGlobalRight()
		&& circle_bottom < player.getGlobalBottom()
		&& circle_bottom > player.getGlobalTop()  );
}
bool Ball::intersectionExtreme1(Jugador &player)
{
	float circle_bottom = sprite.getPosition().y + sprite.getGlobalBounds().height;

		return ((sprite.getPosition().x < player.getGlobalRight() && 
			sprite.getPosition().y < player.getGlobalTop() &&
			circle_bottom > player.getGlobalTop() ) 
			||
			(sprite.getPosition().x < player.getGlobalRight() &&
				sprite.getPosition().y < player.getGlobalBottom() &&
				circle_bottom > player.getGlobalBottom()));
}
bool Ball::intersectionExtreme2(Jugador &player)
{
	float circle_bottom = sprite.getPosition().y + sprite.getGlobalBounds().height;
	float circle_right = sprite.getPosition().x + sprite.getGlobalBounds().width;

	return ( (circle_bottom > player.getGlobalTop()
		&& sprite.getPosition().y < player.getGlobalTop()
		&& circle_right > player.getGlobalLeft()) 
		||
		(circle_bottom > player.getGlobalBottom()
			&& sprite.getPosition().y < player.getGlobalBottom()
			&& circle_right > player.getGlobalLeft()) );
}
