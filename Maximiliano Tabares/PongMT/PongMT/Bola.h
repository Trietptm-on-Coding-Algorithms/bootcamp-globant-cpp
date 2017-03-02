#ifndef BOLA_H
#define BOLA_H

#include <SFML\Graphics.hpp>
#include"Rectangulo.h"


class Bola
{
public:
	Bola();//constructor por default
	Bola(float RADIO, sf::Color COLOR);//constructor parametrizado
	void ResetPosicion(sf::Vector2f POSICION);
	void reboteX();
	void reboteY();
	void movimiento();
	bool detectarColision(sf::RectangleShape RECTANGULO);
	bool detectarColision(sf::FloatRect RECT);
	sf::Vector2f getPosicionBola();
	float getRadioBola();
	void update(sf::RenderWindow &WINDOW);

	~Bola();//destructor

private:
	sf::CircleShape objetoBola; //objeto de tipo circleshape
	sf::Vector2<float> velocidadActual;

};



#endif // !BOLA_H

