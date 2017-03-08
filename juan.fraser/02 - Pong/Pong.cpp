// Pong.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include "Game.h"

int main()
{
	static const int screenX = 640;
	static const int screenY = 400;
	sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Pong Beta 0.4");
	
	static const int FPSLimit = 60;
	window.setFramerateLimit(FPSLimit);
	
	Game g(&window);

	g.run();

	return 0;
}

