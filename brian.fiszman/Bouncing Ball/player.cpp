#ifndef PLAYER_H
#define PLAYER_H
#include "player.hpp"

Player::Player(short number, RenderWindow& window)
    : speedX(0)
    , speedY(0)
    , number(number)
    , window(window)
{
    this->pad.setSize(Vector2f(120, 5));
    this->pad.setOutlineThickness(5);
    this->pad.setOrigin(
        this->getPaddle().getSize().x / 2, this->getPaddle().getSize().y / 2);
    if (this->number == 1)
        this->pad.setPosition(window.getSize().x / 2, 20);
    else if (this->number == 2)
        this->pad.setPosition(window.getSize().x / 2, window.getSize().y - 20);
}

RectangleShape Player::getPaddle() { return this->pad; }
void Player::setSpeedX(float speedX) { this->speedX = speedX; }
void Player::setSpeedY(float speedY) { this->speedY = speedY; }
void Player::setNumber(short number) { this->number = number; }
void Player::move(float x, float y) { this->pad.move(x, y); }
void Player::generateCollisions(const RenderWindow& window)
{
    this->setSpeedX((this->hasCollidedOnX(window)) ? -this->getSpeedX()
                                                   : this->getSpeedX());
    this->setSpeedY((this->hasCollidedOnY(window)) ? -this->getSpeedY()
                                                   : this->getSpeedY());
}
bool Player::hasCollidedOnX(const RenderWindow& window)
{
    return ((this->pad.getGlobalBounds().left < 0 && getSpeedX() < 0)
        || (this->pad.getGlobalBounds().left + this->pad.getGlobalBounds().width
                   > window.getSize().x
               && getSpeedX() > 0));
}
bool Player::hasCollidedOnY(const RenderWindow& window)
{
    return ((this->pad.getGlobalBounds().top < 0 && getSpeedY() < 0)
        || (this->pad.getGlobalBounds().top + this->pad.getGlobalBounds().height
                   > window.getSize().y
               && getSpeedY() > 0));
}

float Player::getSpeedX() { return this->speedX; }
float Player::getSpeedY() { return this->speedY; }
short Player::getNumber() { return this->number; }
#endif
