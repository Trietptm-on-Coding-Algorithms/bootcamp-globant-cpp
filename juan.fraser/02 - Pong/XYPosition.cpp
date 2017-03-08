#include "stdafx.h"
#include "XYPosition.h"

float XYPosition::posAdjustment = 1;

float XYPosition::getPosAdjustment() { return posAdjustment; }
void XYPosition::setPosAdjustment(float newPosA) { posAdjustment = newPosA; }

void XYPosition::setPos(sf::Vector2f newPos) { this->pos = newPos; }
void XYPosition::setOldPos(sf::Vector2f newOldPos) { this->oldPos = newOldPos; }
sf::Vector2f XYPosition::getPos() { return this->pos; }
sf::Vector2f XYPosition::getOldPos() { return this->oldPos; }

void XYPosition::updateXYPos(sf::Vector2f newPos)
{
	//if ( getPos() != getOldPos() ) {
		 setOldPos( getPos() );
	//}
	setPos(newPos);
}
void XYPosition::jumpPos(sf::Vector2f newPos)
{
	setPos(newPos);
	setOldPos(newPos);
}

XYPosition::XYPosition(sf::Vector2f pos)
{
	jumpPos(pos);
}
XYPosition::~XYPosition()
{
}
