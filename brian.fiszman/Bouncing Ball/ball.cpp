#include "ball.hpp"

Ball::Ball(float size)
    : Super(size)
{
    setSpeedX(0);
    setSpeedY(0);
}

Ball::Ball()
{
    setSpeedX(0);
    setSpeedY(0);
}

bool Ball::hasCollidedOnX(const RenderWindow& window)
{
    return ((getGlobalBounds().left < 0 && getSpeedX() < 0)
        || (getGlobalBounds().left + getGlobalBounds().width
                   > window.getSize().x
               && getSpeedX() > 0));
}

bool Ball::hasCollidedOnY(const RenderWindow& window, const RectangleShape& shp)
{
    return ((getGlobalBounds().top < 0 && getSpeedY() < 0)
        || (getGlobalBounds().top + getGlobalBounds().height
                   > window.getSize().y
               && getSpeedY() > 0)
        || (getGlobalBounds().intersects(shp.getGlobalBounds())));
}

float Ball::getSpeedX() { return this->speedX; }
float Ball::getSpeedY() { return this->speedY; }
void Ball::setSpeedX(float speedX) { this->speedX = speedX; }
void Ball::setSpeedY(float speedY) { this->speedY = speedY; }
