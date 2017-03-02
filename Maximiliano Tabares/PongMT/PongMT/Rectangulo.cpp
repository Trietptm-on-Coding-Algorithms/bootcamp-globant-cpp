#include "Rectangulo.h"


const int VelocidadRect = 400.0f;

Rectangulo::Rectangulo(int ANCHO, int ALTO, sf::Color COLOR) {
	objetoRectangulo.setSize(sf::Vector2f(ANCHO, ALTO));
	objetoRectangulo.setFillColor(COLOR);
}
void Rectangulo::ResetPosicion(sf::Vector2f POSICION) {
	objetoRectangulo.setPosition(POSICION);
}
void Rectangulo::SetPosicion(sf::Vector2f POSICION) {
	objetoRectangulo.setPosition(POSICION);
}
sf::FloatRect Rectangulo::getRect() {
	return objetoRectangulo.getGlobalBounds();
}
void Rectangulo::movArriba(float dt) {
	objetoRectangulo.move(0, -VelocidadRect *dt);
}
void Rectangulo::movAbajo(float dt) {
	objetoRectangulo.move(sf::Vector2f(0, VelocidadRect *dt));
}
sf::Vector2f Rectangulo::getPosicionRect() {
	return objetoRectangulo.getPosition();
}
sf::Vector2f Rectangulo::getTamanoRect() {
	return objetoRectangulo.getSize();
}
void Rectangulo::update(sf::RenderWindow &WINDOW) {
	WINDOW.draw(objetoRectangulo);
}
bool Rectangulo::detectarColision(sf::RectangleShape RECTANGULO) {
	if (objetoRectangulo.getGlobalBounds().intersects(RECTANGULO.getGlobalBounds()))
		return true;
	else
	{
		return false;
	}
}
Rectangulo::~Rectangulo() {

}
