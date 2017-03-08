#include "stdafx.h"
#include "Presence.h"


sf::Shape* Presence::getShape() {	return this->s;	}
sf::Shape* Presence::getUpdatedShape(XYPosition currentPos)
{
	getShape()->setPosition(currentPos.getPos());
	return getShape();
}

void Presence::killPresence() { delete this->s; }

Presence::Presence(sf::Shape* shape)
{
	this->s = shape;
}

Presence::~Presence()
{
}
