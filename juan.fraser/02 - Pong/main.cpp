// 02 - Pong.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>

//using namespace sf;



int main() {

	// INIT //
	int screenX = 640;
	int screenY = 400;
	sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Pong Beta 0.2");
	window.setFramerateLimit(60);

	sf::CircleShape ball(10.f);
	//ball.setPointCount(8);
	float vx=0, vy=0, ax=0, ay=9.8f;
	float dv=0.1f, da=0.1f;
	float sd = 0.001;

	sf::Event event;
	bool justLostFocus = true;
	while (window.isOpen())
	{
		//Window Management
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (window.hasFocus())
			justLostFocus = true;
		else {
			if (justLostFocus) {
				window.requestFocus();
				justLostFocus = false;
			}
		}
				
		//Handle Keyboard events
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			vx -= 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			vx += 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			vy -= 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			vy += 1.f;
		
		//Phisics Updates
		vx += ax*da;
		vy += ay*da;
		vx -= sd*vx;
		vy -= sd*vy;

		//Collisions
		if (ball.getGlobalBounds().left < 0 && vx < 0)
			vx = -vx;
		if (ball.getGlobalBounds().top < 0 && vy < 0)
			vy = -vy;
		if (ball.getGlobalBounds().left+ball.getGlobalBounds().width > screenX 
			&& vx > 0)
			vx = -vx;
		if (ball.getGlobalBounds().top+ball.getGlobalBounds().height > screenY
			&& vy > 0)
			vy = -vy;
		
		//Object Update
		ball.move(vx*dv, vy*dv);
		
		//Renders
		window.clear();
		window.draw(ball);
		window.display();
	}
	return 0;
}

