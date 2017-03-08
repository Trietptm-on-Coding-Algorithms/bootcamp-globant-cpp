#include "stdafx.h"
#include "ReceivesVInput.h"

bool ReceivesVInput::isUpPressed()
{
	return this->upPressed;
}
bool ReceivesVInput::isDownPressed()
{
	return this->downPressed;
}
void ReceivesVInput::updateInput()
{
	this->upPressed = sf::Keyboard::isKeyPressed(getUp());
	this->downPressed = sf::Keyboard::isKeyPressed(getDown());
}


void ReceivesVInput::setUp(sf::Keyboard::Key up) 
{
	this->up = up;
}
void ReceivesVInput::setDown(sf::Keyboard::Key down)
{
	this->down = down;
}
sf::Keyboard::Key ReceivesVInput::getUp()
{
	return this->up;
}
sf::Keyboard::Key ReceivesVInput::getDown()
{
	return this->down;
}


ReceivesVInput::ReceivesVInput(sf::Keyboard::Key up, sf::Keyboard::Key down)
{
	setUp(up);
	setDown(down);
}


ReceivesVInput::~ReceivesVInput()
{
}
