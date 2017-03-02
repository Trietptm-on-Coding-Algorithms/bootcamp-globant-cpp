#include "stdafx.h"
#include "Game.h"
#include "Ball.h"
#include "Jugador.h"
#include "Score.h"
#include "Menu.h"
#include "ListaCircular.h"
#include <SFML\Graphics.hpp>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int  MaxSceenX = 800;
const int MaxSceenY = 600;

Game::Game(bool &play,bool &opcion)
{
	Menu menu(MaxSceenX, MaxSceenY);

	sf::Texture fondo;
	fondo.loadFromFile("fondo_menu.png");
	sf::Sprite sprite;
	sprite.setTexture(fondo);
	sprite.setPosition(0.0, 0.0);
	sprite.setScale(0.52f, 0.6f);

	sf::RenderWindow window(sf::VideoMode(MaxSceenX, MaxSceenY), "Proyecto_pong");

	//Set the derired FPS to 60

	const unsigned int FPS = 60;
	window.setFramerateLimit(FPS);

	sf::Event event;

	//Main Game Loop
	while (window.isOpen())

	{
		//Handle events
		while (window.pollEvent(event))

		{
			switch (event.type)
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
					{
						window.close();
						play = true;

					}
						break;
					case 1:
					{
						opcion = true;
						cout << "Desarrollar opcion opcion"  << endl;
					}
						break;
					case 2:
						window.close();
					break;
					}
				}
		}

		window.clear();
		window.draw(sprite);
		menu.draw(window);
		window.display();

	}

}
Game::~Game()
{

}
void Game::Op_Play()
{
	const int speedZero = 20;
	double speedBallX = speedZero, speedBallY = speedZero;
	double speedOneX = 0, speedOneY = 0;
	double speedTwoX = 0, speedTwoY = 0;
	double dx = 0.1, dy = 0.1;
	int i = 0;
	int j = 0;
	float a;
	bool restart  = true;

	sf::Clock clock;
	sf::Time time;

	sf::Texture fondo_play;
	fondo_play.loadFromFile("fondo_play.png");
	sf::Sprite sprite;
	sprite.setTexture(fondo_play);
	sprite.setPosition(0.0, 0.0);
	sprite.setScale(0.9f, 1.1f);
	
	sf::Texture image_player2;
	image_player2.loadFromFile("vegeta.png");
	sf::Texture image_player1;
	image_player1.loadFromFile("goku.png");
	
	Score score;
	ListaCircular lista_A;
	sf::Sprite sprite_esferas;
	sprite_esferas.setTexture(image_player1);
	lista_A.pushFront(sprite_esferas);

	sf::Texture image_ball;
	image_ball.loadFromFile("ball.png");
	

	Ball ball(image_ball);
	Jugador playerOne(image_player1);
	Jugador playerTwo(image_player2);
	playerOne.setPosition(0.0, 0.0);
	playerTwo.setPosition(740.0, 0.0);
	sf::Font font;
	sf::Text text;
	sf::Text text2;
	font.loadFromFile("STENCIL.ttf");

	sf::RenderWindow window(sf::VideoMode(MaxSceenX, MaxSceenY), "Proyecto_pong");
	const unsigned int FPS = 60;
	window.setFramerateLimit(FPS);

	sf::Event event;
	//Main Game Loop
	while (window.isOpen())

	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		time = clock.getElapsedTime();
		cout << time.asSeconds() << endl;
		window.clear();
		// Iniciar el juego con un conteo de 3 a 0
		if ( time.asSeconds() < 3.f && restart == true)
		{
			int i;
			text.setPosition(300.f, 0.f);
			text.setFont(font);
			i = -1*(time.asSeconds()-3);
			string s = to_string(i);
			text.setFillColor(sf::Color(255, 0, 0, 100));
			text.setString(s);
			text.setCharacterSize(450);
		}
		else
			text.setFillColor(sf::Color(0, 0, 0, 0));
		// Iniciar el juego con la bola en el centro y movimiento random
		if (time.asSeconds() > 3.f && restart == true)
		{
			speedBallX = speedZero;
			speedBallY = speedZero;
			ball.moved(speedBallX*dx, speedBallY*dy);
			if (rand() % 3 == 1)
				a = -1;
			else
				a = 1;

			speedBallX = a*speedBallX;

			if (rand() % 3 == 1)
				a = -1;
			else
				a = 1;
			speedBallY = a*speedBallY;
			restart = false;
		}
		if (restart == false)
			ball.moved(speedBallX*dx, speedBallY*dy);
		playerOne.moved(speedOneX*dx, speedOneY*dy);
		playerTwo.moved(speedTwoX*dx, speedTwoY*dy);

		// Colisiones de la bola con las paredes

		if (ball.collisionLeft())
		{
			int size = 22;
			text2.setPosition(ball.getPosicion());
			text2.setFont(font);
			text2.setFillColor(sf::Color::Cyan);
			text2.setString("100!");
			text2.setCharacterSize(size);
			score.LoadScore(i, j += 100);
			ball.position(MaxSceenX / 2, MaxSceenY / 2);
			speedBallX = 0;
			speedBallY = 0;
			clock.restart();
			restart = true;
		}

		if (ball.collisionRight(MaxSceenX))
		{
			int size = 22;
			text2.setPosition(ball.getPosicion() + sf::Vector2f(-40.0, -40.0));
			text2.setFont(font);
			text2.setFillColor(sf::Color::Cyan);
			text2.setString("100!");
			text2.setCharacterSize(size);
			score.LoadScore(i += 100, j);
			ball.position(MaxSceenX / 2, MaxSceenY / 2);
			speedBallX = 0;
			speedBallY = 0;
			clock.restart();
			restart = true;
		}

		// colisiones de los objetos y entre ellos

		if (ball.intersectionSide2(playerTwo))
			speedBallX = -1.2 * speedBallX;

		if (ball.intersectionSide1(playerOne))
			speedBallX = -1.2 * speedBallX;

		/*if (ball.intersectionExtreme2(playerTwo))
		{
			speedBallY = -1.2 * speedBallY;
		}
		*/
		if (ball.collisionY(MaxSceenY))
			speedBallY = -speedBallY;

		if (playerOne.collisionY(MaxSceenY))
			speedOneY = -speedOneY;

		if (playerTwo.collisionY(MaxSceenY))
			speedTwoY = -speedTwoY;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			speedOneY -= 1.0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			speedOneY += 1.0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			speedTwoY -= 1.0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) )
			speedTwoY += 1.0;


		window.draw(sprite);
		window.draw(text);
		window.draw(text2);
		lista_A.draw(window);
		score.draw(window);
		ball.draw(window);
		playerOne.draw(window);
		playerTwo.draw(window);
		window.display();
	}
}
void Game::Op_Opcion()
{
	
}
