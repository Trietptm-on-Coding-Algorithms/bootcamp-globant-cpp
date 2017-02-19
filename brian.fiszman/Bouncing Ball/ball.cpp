#include "ball.hpp"
Ball::Ball(float size): Super(size)
{
    this->setSpeedX(0);
    this->setSpeedY(0);
}

Ball::Ball()
{
    this->setSpeedX(0);
    this->setSpeedY(0);
}

bool Ball::hasCollidedOnX(Resolution resolution)
{
    return ((this->getGlobalBounds().left < 0 && this->getSpeedX() < 0) || (this->getGlobalBounds().left+this->getGlobalBounds().width > resolution.getX() && this->getSpeedX() > 0));
}

bool Ball::hasCollidedOnY(RectangleShape shp, Resolution resolution)
{
    return ((this->getGlobalBounds().top < 0 && this->getSpeedY() < 0) || (this->getGlobalBounds().top+this->getGlobalBounds().height > resolution.getY() && this->getSpeedY() > 0) || (this->getGlobalBounds().intersects(shp.getGlobalBounds())));
}

float Ball::getSpeedX(){ return this->speedX; }
float Ball::getSpeedY(){ return this->speedY; }
void Ball::setSpeedX(float speedX){ this->speedX = speedX; }
void Ball::setSpeedY(float speedY){ this->speedY = speedY; }
