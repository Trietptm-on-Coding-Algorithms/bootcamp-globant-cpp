// 02 - Pong.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>

//using namespace sf;



int main() {

	// INIT //
	int screenX = 640;
	int screenY = 400;
	sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Pong Beta 0.3");
	window.setFramerateLimit(60);

	sf::CircleShape ball(10.f);
	float vx=20, vy=0, ax=0, ay=9.8f;
	float dv=0.01f, da=0.01f;
	float sd = 0.0001f;

	sf::RectangleShape rectangle(sf::Vector2f(16.f,64.f) );
	rectangle.setPosition(4, (screenY-rectangle.getGlobalBounds().height)/2);
	float dm = 0.5f;

	printf("WS to move rectangle. \nArrows to move ball.");

	sf::Clock clock;
	sf::Event event;
	bool lostFocus = false;
	while (window.isOpen())
	{
		//Window Management
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::LostFocus) {
				window.requestFocus();
				lostFocus = true;
			}
			else if (event.type == sf::Event::GainedFocus) {
				lostFocus = false;
				clock.restart();
			}
				
		}

		//Unfocus "Pause"
		if (lostFocus)
			continue;
		
		//Time Elapsed
		int dt = clock.restart().asMilliseconds();
		if (dt > 100)
			dt = 100;

		//Handle Keyboard events
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			vx -= 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			vx += 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			vy -= 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			vy += 1.f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			rectangle.move(0, -dm*dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			rectangle.move(0, dm*dt);

		//Phisics Updates
		vx += ax*da*dt;
		vy += ay*da*dt;
		vx -= sd*vx*dt;
		vy -= sd*vy*dt;

		//Collisions
		if (rectangle.getGlobalBounds().top < 0)
			rectangle.setPosition(4, 0);
		if (rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height > screenY)
			rectangle.setPosition(4, screenY - rectangle.getGlobalBounds().height);

		if (ball.getGlobalBounds().left < rectangle.getGlobalBounds().left + rectangle.getGlobalBounds().width 
			&& ball.getGlobalBounds().top < rectangle.getGlobalBounds().top + rectangle.getGlobalBounds().height
			&& ball.getGlobalBounds().top + ball.getGlobalBounds().height > rectangle.getGlobalBounds().top)
			vx = -vx;

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
		ball.move(vx*dv*dt, vy*dv*dt);
		
		//Renders
		window.clear();

		window.draw(ball);
		window.draw(rectangle);

		window.display();
	}
	return 0;
}

