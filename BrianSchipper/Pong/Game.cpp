tex#include "stdafx.h"
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

	sf::Texture texture_fondo;
	texture_fondo.loadFromFile("fondo_menu.png");
	sf::Sprite sprite_fondo;
	sprite_fondo.setTexture(texture_fondo);
	sprite_fondo.setPosition(0.0, 0.0);
	sprite_fondo.setScale(0.52f, 0.6f);

	sf::RenderWindow window(sf::VideoMode(MaxSceenX, MaxSceenY), "Proyecto_pong");

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
						window.close();
						opcion = true;						
					}
						break;
					case 2:
						window.close();
					break;
					}
				}
		}

		window.clear();
		window.draw(sprite_fondo);
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
	int scoreP1 = 0;
	int scoreP2 = 0;
	bool restart  = true;
	int lastTime = 0;
	bool touch_player1 = false;
	bool touch_player2 = false;

	sf::Clock clock_game;
	sf::Time time;

	sf::Texture texture_fondo;
	texture_fondo.loadFromFile("fondo_play.png");
	sf::Sprite sprite_fondo;
	sprite_fondo.setTexture(texture_fondo);
	sprite_fondo.setPosition(0.0, 0.0);
	sprite_fondo.setScale(0.9f, 1.1f);
	
	sf::Texture texture_player2;
	texture_player2.loadFromFile("vegeta.png");
	sf::Texture texture_player1;
	texture_player1.loadFromFile("goku.png");
	
	Score score;
	
	sf::Texture texture_ball;
	texture_ball.loadFromFile("ball.png");
	
	ListaCircular lista_A;
	sf::Sprite sprite_esferas;
	sprite_esferas.setTexture(image_player1);
	
	lista_A.pushFront(sprite_esferas);
	sf::Texture texture_esf1;
	sf::Texture texture_esf2;
	sf::Texture texture_esf3;
	sf::Texture texture_esf4;
	sf::Texture texture_esf5;
	sf::Texture texture_esf6;
	sf::Texture texture_esf7;
	
	texture_esf1.loadFromFile("Esfera1.png");
	lista_A.LoadList(texture_esf1, lista_A);

	texture_esf2.loadFromFile("Esfera2.png");
	lista_A.LoadList(texture_esf2, lista_A);
	
	texture_esf3.loadFromFile("Esfera3.png");
	lista_A.LoadList(texture_esf3, lista_A);
	
	texture_esf4.loadFromFile("Esfera4.png");
	lista_A.LoadList(texture_esf4, lista_A);
	
	texture_esf5.loadFromFile("Esfera5.png");
	lista_A.LoadList(texture_esf5, lista_A);
	
	texture_esf6.loadFromFile("Esfera6.png");
	lista_A.LoadList(texture_esf6, lista_A);

	texture_esf7.loadFromFile("Esfera7.png");
	lista_A.LoadList(texture_esf7, lista_A);
	
	ListElement*itr = lista_A.begin();
	
	Ball ball(texture_ball);
	Jugador playerOne(texture_player1);
	Jugador playerTwo(texture_player2);
	playerOne.setPosition(0.0, 300.0);
	playerTwo.setPosition(740.0, 300.0);
	sf::Font font;
	sf::Text text;
	sf::Text text_point;
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
			int size = 450;
			text.setPosition(300.f, 0.f);
			text.setFont(font);
			i = -1*(time.asSeconds()-3);
			string str = to_string(i);
			text.setFillColor(sf::Color(255, 0, 0, 100));
			text.setString(str);
			text.setCharacterSize(size);
			touch_player1 = false;
			touch_player2 = false;
		}
		else
			text.setFillColor(sf::Color(0, 0, 0, 0));
		
		// Iniciar el juego con la bola en el centro y movimiento random
		if (time.asSeconds() > 3.f && restart == true)
		{	
			float a;
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
		{	
			ball.moved(speedBallX*dx, speedBallY*dy);
		}	
		playerOne.moved(speedOneX*dx, speedOneY*dy);
		playerTwo.moved(speedTwoX*dx, speedTwoY*dy);
		
		
		// Colisiones de la bola con las paredes

		if (ball.collisionLeft())
		{
			int size = 22;
			text2.setPosition(ball.getPosicion());
			text2.setFont(font);
			text2.setFillColor(sf::Color::Green);
			text2.setString("100!");
			text2.setCharacterSize(size);
			score.LoadScore(scoreP1, scoreP2 += 100);
			ball.position(MaxSceenX / 2, MaxSceenY / 2);
			speedBallX = 0;
			speedBallY = 0;
			clock.restart();
			lastTime = time.asSeconds();
			restart = true;
		}

		if (ball.collisionRight(MaxSceenX))
		{
			int size = 22;
			text2.setPosition(ball.getPosicion() + sf::Vector2f(-40.0, -40.0));
			text2.setFont(font);
			text2.setFillColor(sf::Color::Green);
			text2.setString("100!");
			text2.setCharacterSize(size);
			score.LoadScore(scoreP1 += 100,scoreP2 );
			ball.position(MaxSceenX / 2, MaxSceenY / 2);
			speedBallX = 0;
			speedBallY = 0;
			clock.restart();
			lastTime = 0;
			restart = true;
		}

		// colisiones de los objetos y entre ellos

		if (ball.intersectionSide2(playerTwo) && touch_player2 == false)
		{
			touch_player2 = true;
			touch_player1 = false;
			speedBallX = -1.2 * speedBallX;
		}

		if (ball.intersectionSide1(playerOne) && touch_player1 == false)
		{
			touch_player1 = true;
			touch_player2 = false;
			speedBallX = -1.2 * speedBallX;
		}

		/*
		if (ball.intersectionExtreme2(playerTwo) && touch_player2 == false)
		{
			touch_player2 = true;
			touch_player1 = false;
			speedBallX = 1.2*speedBallX;
			speedBallY = -1.2 * speedBallY;
		}
		
		if (ball.intersectionExtreme1(playerOne) && touch_player1 == false) 
		{
			touch_player1 = true;
			touch_player2 = false;
			speedBallX = -1.2*speedBallX;
			speedBallY = 1.2*speedBallY;
		}
		*/
		if (ball.collisionY(MaxSceenY))
			speedBallY = -speedBallY;

		if (playerOne.collisionY(MaxSceenY))
			speedOneY = -speedOneY;

		if (playerTwo.collisionY(MaxSceenY))
			speedTwoY = -speedTwoY;
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		if (playerOne.getGlobalTop() > -2 && playerOne.getGlobalBottom() < 602)
		{
			// Para que no continue en los bordes
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					speedOneY -= 1.0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					speedOneY += 1.0;
		}
		if (playerTwo.getGlobalTop() > 1 && playerTwo.getGlobalBottom() < 602)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
				speedTwoY -= 1.0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
				speedTwoY += 1.0;
		}
	// control de velocidad 
		if (speedOneY*speedOneY > (45*45) )
		speedOneY = speedOneY / 1.2;
		if (speedTwoY*speedTwoY > (45*45) )
		speedTwoY = speedTwoY / 1.2;

		cout << lastTime << endl;

		int getTime = time.asSeconds();
		float a;
		float b;
		a = rand() % 700;
		b = rand() % 500;		
		//lastTime= ;

		window.draw(sprite_fondo);

		if (getTime > lastTime)
		{	
			itr = itr->next;
			itr->val.setPosition(a, b);
			itr->val.setScale(0.25f, 0.25f);
			lastTime = getTime + 1;
		}
		
		window.draw(itr->val);
		window.draw(text);
		window.draw(text_point);
		score.draw(window);
		ball.draw(window);
		playerOne.draw(window);		playerTwo.draw(window);
		window.display();
	}
}
void Game::Op_Opcion()
{
	float ancho = MaxSceenX;
	float alto = MaxSceenY;

	sf::Text text[5];
	sf::Font font;
	font.loadFromFile("STENCIL.ttf");

	text[0].setFont(font);
	text[0].setFillColor(sf::Color::White);
	text[0].setString("Controles");
	text[0].setCharacterSize(30);
	text[0].setPosition(sf::Vector2f(0.f, 0.f));

	text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setString("W/s -Player 1;  I/K -Player2; Esc = Exit");
	text[1].setCharacterSize(20);
	text[1].setPosition(sf::Vector2f(0.f, alto / 10));

	text[2].setFont(font);
	text[2].setFillColor(sf::Color::White);
	text[2].setString("Objetivo");
	text[2].setCharacterSize(30);
	text[2].setPosition(sf::Vector2f(0.f, alto / 4));

	text[3].setFont(font);
	text[3].setFillColor(sf::Color::White);
	text[3].setString("Juego a 10 puntos, en caso de empate punto de oro");
	text[3].setCharacterSize(20);
	text[3].setPosition(sf::Vector2f(0.f, alto / 2.8));

	text[4].setFont(font);
	text[4].setFillColor(sf::Color::Red);
	text[4].setString("Exit");
	text[4].setCharacterSize(45);
	text[4].setPosition(sf::Vector2f(0.f, alto / 2));

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			Op_Play();
	
		window.clear();
		
	for (int i = 0; i<5; i++)
	{
		window.draw(text[i]);
	}
	
	window.display();				
	
	}
	
}
