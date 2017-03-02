#include "Bola.h"



sf::Vector2<float> VelocidadBola(0.4, 0.4);

Bola::Bola(){
}
Bola::Bola(float RADIO, sf::Color COLOR) {
	objetoBola.setRadius(RADIO);
	objetoBola.setFillColor(COLOR);

}
void Bola::ResetPosicion(sf::Vector2f POSICION) {
	objetoBola.setPosition(POSICION);
	velocidadActual = VelocidadBola;
}
void Bola::reboteX() {
	velocidadActual.x = -velocidadActual.x;
}
void Bola::reboteY() {
	velocidadActual.y = -velocidadActual.y;
}
void Bola::movimiento() {
	objetoBola.move(velocidadActual.x, velocidadActual.y);
}
bool Bola::detectarColision(sf::RectangleShape RECTANGULO) {
	if (objetoBola.getGlobalBounds().intersects(RECTANGULO.getGlobalBounds()))
		return true;
	else
	{
		return false;
	}
}
bool Bola::detectarColision(sf::FloatRect RECT){
	if (objetoBola.getGlobalBounds().intersects(RECT))
		return true;
	else
	{
		return false;
	}

}
sf::Vector2f Bola::getPosicionBola() {
	return objetoBola.getPosition();
}
float Bola::getRadioBola() {
	return objetoBola.getRadius();
}
void Bola::update(sf::RenderWindow &WINDOW){
	WINDOW.draw(objetoBola);
}
Bola::~Bola() {
}