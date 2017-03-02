// PongMT.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bola.h"
#include "Rectangulo.h"
#include <sstream>
#include <string>

/** CONSTANTES DE VENTANA **/
const int ANCHO_VENT = 800;
const int ALTO_VENT = 600;
const int BPP_VENT = 32;
const char *TITULO = "PONG MT";

/** CONSTANTES DE RECTANGULO **/
const int ANCHORECT = 10;
const int ALTORECT = 60;

sf::Color COLOR_JUGADOR_1 = sf::Color::Magenta;
sf::Color COLOR_JUGADOR_2 = sf::Color::Blue;

/** CONSTANTES DE BOLA **/
const float RADIO_BOLA = 5.0f;
sf::Color COLOR_BOLA = sf::Color::White;
sf::Vector2f POSICION_DEFAULT = sf::Vector2f(ANCHO_VENT / 2 - 7.5, ALTO_VENT / 2 - 5);

/** CONSTANTES DE LIMITES **/
const int SUP_RECT_ANCHO = 800;
const int SUP_RECT_ALTO = 30;
sf::Color SUP_RECT_COLOR = sf::Color::Red;

const int INF_RECT_ANCHO = 800;
const int INF_RECT_ALTO = 30;
sf::Color INF_RECT_COLOR = sf::Color::Red;

const int IZQ_RECT_ANCHO = 30;
const int IZQ_RECT_ALTO = 600;
sf::Color IZQ_RECT_COLOR = sf::Color::Red;

const int DER_RECT_ANCHO = 30;
const int DER_RECT_ALTO = 600;
sf::Color DER_RECT_COLOR = sf::Color::Red;







int main()
{
	sf::RenderWindow GameWindow;
	GameWindow.create(sf::VideoMode(ANCHO_VENT, ALTO_VENT, BPP_VENT),
		TITULO, sf::Style::Close);

	sf::Clock Reloj;
	float horaActual = 0.0f;
	float horaPasada = 0.0f;
	float horaAux = 0.0f;

	/** LIMITES **/

	sf::RectangleShape rectSup;
	sf::RectangleShape rectInf;
	sf::RectangleShape rectIzq;
	sf::RectangleShape rectDer;


	rectSup.setSize(sf::Vector2f(SUP_RECT_ANCHO, SUP_RECT_ALTO));
	rectInf.setSize(sf::Vector2f(INF_RECT_ANCHO, INF_RECT_ALTO));
	rectIzq.setSize(sf::Vector2f(IZQ_RECT_ANCHO, IZQ_RECT_ALTO));
	rectDer.setSize(sf::Vector2f(DER_RECT_ANCHO, DER_RECT_ALTO));

	rectSup.setFillColor(SUP_RECT_COLOR);
	rectInf.setFillColor(INF_RECT_COLOR);
	rectIzq.setFillColor(IZQ_RECT_COLOR);
	rectDer.setFillColor(DER_RECT_COLOR);


	rectSup.setPosition(sf::Vector2f(0, 0));
	rectInf.setPosition(sf::Vector2f(0, 570));
	rectIzq.setPosition(sf::Vector2f(0, 0));
	rectDer.setPosition(sf::Vector2f(770, 0));


	Rectangulo jugador1(ANCHORECT, ALTORECT, COLOR_JUGADOR_1);
	Rectangulo jugador2(ANCHORECT, ALTORECT, COLOR_JUGADOR_2);

	jugador1.SetPosicion(sf::Vector2f(40, 260));
	jugador2.SetPosicion(sf::Vector2f(750, 260));

	Bola bola(RADIO_BOLA, COLOR_BOLA);
	bola.ResetPosicion(POSICION_DEFAULT);

	while (GameWindow.isOpen())
	{
		horaActual = Reloj.getElapsedTime().asSeconds();
		horaAux = horaActual - horaPasada;
		horaPasada = horaActual;

		sf::Event Event;
		while (GameWindow.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				GameWindow.close();
				break;
			}
		}

		GameWindow.clear();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			jugador1.movArriba(horaAux);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			jugador1.movAbajo(horaAux);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			jugador2.movArriba(horaAux);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			jugador2.movAbajo(horaAux);

		//juego
		if (jugador1.detectarColision(rectSup))
			jugador1.SetPosicion(sf::Vector2f(jugador1.getPosicionRect().x, rectSup.getPosition().y + 30));

		if (jugador1.detectarColision(rectInf))
			jugador1.SetPosicion(sf::Vector2f(jugador1.getPosicionRect().x, rectInf.getPosition().y - 60));

		if (jugador2.detectarColision(rectSup))
			jugador2.SetPosicion(sf::Vector2f(jugador2.getPosicionRect().x, rectSup.getPosition().y + 30));

		if (jugador2.detectarColision(rectInf))
			jugador2.SetPosicion(sf::Vector2f(jugador2.getPosicionRect().x, rectInf.getPosition().y - 60));

		if (bola.detectarColision(jugador1.getRect()))
		{
			bola.reboteX();

		}

		if (bola.detectarColision((jugador2.getRect())))
		{
			bola.reboteX();

		}

		if (bola.detectarColision(rectInf))
			bola.reboteY();

		if (bola.detectarColision(rectSup))
			bola.reboteY();

		if (bola.detectarColision(rectIzq))
		{
			bola.ResetPosicion(sf::Vector2f(ANCHO_VENT / 2 - 5, ALTO_VENT / 2 - 5));
			jugador1.ResetPosicion(sf::Vector2f(jugador1.getPosicionRect().x, ALTO_VENT / 2 - 5));

		}

		if (bola.detectarColision(rectDer))
		{
			bola.ResetPosicion(sf::Vector2f(ANCHO_VENT / 2 - 5, ALTO_VENT / 2 - 5));
			jugador1.ResetPosicion(sf::Vector2f(jugador1.getPosicionRect().x, ALTO_VENT / 2 - 5));

		}

	}
		return 0;
	
}

