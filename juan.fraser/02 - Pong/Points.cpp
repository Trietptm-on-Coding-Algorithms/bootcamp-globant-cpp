#include "stdafx.h"
#include "Points.h"

int Points::maxPoints = 10;

void Points::setPoints(int newPoints)
{
	this->p = newPoints;
}
int Points::getPoints()
{
	return this->p;
}
void Points::setMaxPoints(int newMaxPoints)
{
	maxPoints = newMaxPoints;
}
bool Points::incrementPoints()
{
	setPoints(getPoints() + 1);
	return hasWon();
}
bool Points::hasWon()
{
	return (getPoints() >= maxPoints);
}
void Points::resetPoints()
{
	setPoints(0);
}


Points::Points()
{
}


Points::~Points()
{
}
