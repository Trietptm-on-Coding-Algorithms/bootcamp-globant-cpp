#include "stdafx.h"
#include <SFML/Graphics.hpp>

// Declaracion e inicializacion de variables
int MaxScreenX = 400;
int MaxScreenY = 400;
int i = 3;
int colorA = 0;
int colorB = 0;
int colorC = 255;
int colorD = 255;
float radio = 30.0;
double speedX = 0, speedY = 0;
double dx = 0.1, dy=0.1;

int main()
{

	//Creates the window
	sf::RenderWindow window(sf::VideoMode(MaxScreenX,MaxScreenY), "Jueguito para Miri");

	//Set the derired FPS to 60
	const unsigned int FPS = 60;
	window.setFramerateLimit(FPS);

	//Create a circle with radius 10
	sf::CircleShape circle(radio,i);
	sf::RectangleShape rectangle(sf::Vector2f(15.0f, 50.0f));

	circle.setPosition(200.0f, 200.0f);
	rectangle.setPosition(145.0f, 145.0f);
	rectangle.setFillColor(sf::Color(255,0,0,255));
	circle.setFillColor(sf::Color(colorA, colorB, colorC, colorD));
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

		// Draw Stuff 
		window.clear(); 

		//Handle Keyboard events;

		circle.move((float)speedX*dx, (float)speedY*dy);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			speedX -= 1.f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			speedX += 1.f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			speedY -= 1.f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			speedY += 1.f;
		
		// Screen Limits

		if (circle.getGlobalBounds().left < 0 && speedX < 0)
		{
			speedX = -speedX;
			circle.setPointCount(5);
			circle.setFillColor(sf::Color(colorA = colorA + 150, colorB, colorC, colorD));
		};
		if (circle.getGlobalBounds().top < 0 && speedY < 0)
		{
			circle.setPointCount(3);
			speedY = -speedY;
		}
		if (circle.getGlobalBounds().left + circle.getGlobalBounds().width > MaxScreenX && speedX > 0)
		{
			speedX = -speedX;
			circle.setFillColor(sf::Color(colorA, colorB= 150 + colorB, colorC, colorD));
			circle.setPointCount(4);

		}
		if (circle.getGlobalBounds().top + circle.getGlobalBounds().height > MaxScreenY && speedY > 0)
		{
			speedY = -speedY;
			circle.setPointCount(5);
			circle.setFillColor(sf::Color(colorA, colorB, colorC = colorC + 150, colorD));
		}


		//Draw stuff
		window.draw(circle);
		window.draw(rectangle);

		//Call after everything is drawn
		window.display();
	}
}
