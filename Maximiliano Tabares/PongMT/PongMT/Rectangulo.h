#include <SFML\Graphics.hpp>
#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo
{
public:
	Rectangulo(int ANCHO, int ALTO, sf::Color COLOR);//constructor
	void ResetPosicion(sf::Vector2f POSICION); //resetea la posicion
	void SetPosicion(sf::Vector2f POSICION);//establece posicion
	sf::FloatRect getRect();
	void movArriba(float dt);//mueve el rectangulo hacia arriba
	void movAbajo(float dt);//mueve el rectangulo hacia abajo
	sf::Vector2f getPosicionRect();//devuelve posicion del rectangulo
	sf::Vector2f getTamanoRect();//devuelve tamano del rectangulo
	void update(sf::RenderWindow &WINDOW);
	bool detectarColision(sf::RectangleShape RECTANGULO);
	~Rectangulo();//destructor

private:


sf::RectangleShape objetoRectangulo;

};

#endif // !RECTANGULO_H

