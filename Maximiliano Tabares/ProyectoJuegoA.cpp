// ProyectoJuegoA.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include <SFML/Graphics.hpp>

int main()
{
	//variables de control
	float speed = 1.0;
	float speedupdown = speed;
	float speedrightleft = speed;
	//Creates the window
	sf::RenderWindow window(sf::VideoMode(300, 300), "Max Tabares");

	//Set the derired FPS to 60
	const unsigned int FPS = 60;
	window.setFramerateLimit(FPS);

	//Create a circle with radius 10
	sf::CircleShape circle(10.0f);
	circle.setPosition(145.0f, 145.0f);
	sf::Event event;

	//Main Game Loop
	while (window.isOpen())
	{
		//Handle events
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Draw stuff
		window.clear();

		//Handle Keyboard events
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& circle.getGlobalBounds().left > 0)
			circle.move(-1.0f, 0.0f);
		else (circle.move(1.0f, 0.0f));
*/

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			circle.move(-1.0f, 0.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			circle.move(1.0f, 0.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			circle.move(0.0f, -1.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			circle.move(0.0f, 1.0f);
		//movimiento de circle
		circle.move(speedrightleft, speedupdown);
		//limites de espacio
		if (circle.getGlobalBounds().top + circle.getGlobalBounds().height > 300)
			//circle.setFillColor(sf::Color::Blue); 
			speedupdown = -speedupdown;
			
			

		if (circle.getGlobalBounds().top < 0)
			//circle.setFillColor(sf::Color::Red);
			speedupdown = -speedupdown;
			

		if (circle.getGlobalBounds().left > 280)
			//circle.setFillColor(sf::Color::Green);
			speedrightleft = -speedrightleft;
			

		if (circle.getGlobalBounds().left < 0)
			//circle.setFillColor(sf::Color::Magenta);
			speedrightleft = -speedrightleft; 
			
			


		//Draw stuff
		window.draw(circle);

		//Call after everything is drawn
		window.display();
	}
}
