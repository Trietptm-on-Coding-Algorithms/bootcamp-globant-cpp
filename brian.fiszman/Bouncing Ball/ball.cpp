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

void Ball::generateCollisions(const RenderWindow &window)
{
    this->setSpeedX((this->hasCollidedOnX(window)) ? -this->getSpeedX() : this->getSpeedX());
    this->setSpeedY((this->hasCollidedOnY(window)) ? -this->getSpeedY() : this->getSpeedY());
}

void Ball::generateCollisions(const RectangleShape &shp)
{
    this->setSpeedX((this->hasCollidedOnX(shp)) ? -this->getSpeedX() : this->getSpeedX());
    this->setSpeedY((this->hasCollidedOnY(shp)) ? -this->getSpeedY() : this->getSpeedY());
}

bool Ball::hasCollidedOnX(const RenderWindow& window)
{
    return ((getGlobalBounds().left < 0 && getSpeedX() < 0)
        || (getGlobalBounds().left + getGlobalBounds().width
                   > window.getSize().x
               && getSpeedX() > 0));
}

bool Ball::hasCollidedOnX(const RectangleShape& shp)
{
    if (getPosition().x < shp.getPosition().x)
        return ((getPosition().x + getRadius()
                    >= shp.getPosition().x - shp.getSize().x / 2)
            && this->shareYSpaceWith(shp));
    else if (getPosition().x > shp.getPosition().x)
        return ((getPosition().x - getRadius()
                    <= shp.getPosition().x + shp.getSize().x / 2)
            && this->shareYSpaceWith(shp));
}

bool Ball::hasCollidedOnY(const RenderWindow& window)
{
    return ((getGlobalBounds().top < 0 && getSpeedY() < 0)
        || (getGlobalBounds().top + getGlobalBounds().height
                   > window.getSize().y
               && getSpeedY() > 0));
}

bool Ball::hasCollidedOnY(const RectangleShape& shp)
{
    if (getPosition().y < shp.getPosition().y)
        return ((getPosition().y + getRadius()
                    > shp.getPosition().y - shp.getSize().y)
            && this->shareXSpaceWith(shp));
    else if (getPosition().y > shp.getPosition().y)
        return ((getPosition().y - getRadius() 
                    <= shp.getPosition().y + shp.getSize().y)
            && this->shareXSpaceWith(shp));
}

bool Ball::shareXSpaceWith(const RectangleShape& shp)
{
    return (getPosition().x + getRadius() * 2
            > shp.getPosition().x - shp.getSize().x / 2
        && getPosition().x - getRadius() * 2
            < shp.getPosition().x + shp.getSize().x / 2);
}

bool Ball::shareYSpaceWith(const RectangleShape& shp)
{
    return (getPosition().y + getRadius() * 2
            > shp.getPosition().y - shp.getSize().y / 2
        && getPosition().y - getRadius() * 2
            < shp.getPosition().y + shp.getSize().y / 2);
}

float Ball::getSpeedX() { return this->speedX; }
float Ball::getSpeedY() { return this->speedY; }
void Ball::setSpeedX(float speedX) { this->speedX = speedX; }
void Ball::setSpeedY(float speedY) { this->speedY = speedY; }
