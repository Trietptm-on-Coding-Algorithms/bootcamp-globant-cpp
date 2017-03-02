#ifndef PLAYER_H
#define PLAYER_H
#include "player.hpp"

Player::Player(short number)
    : speedX(0)
    , speedY(0)
    , number(number)
{
    this->getPaddle().setOutlineThickness(5);
}

RectangleShape Player::getPaddle() { return this->pad; }
void Player::setSpeedX(float speedX) { this->speedX = speedX; }
void Player::setSpeedY(float speedY) { this->speedY = speedY; }
void Player::setNumber(short number) { this->number = number; }
float Player::getSpeedX() { return this->speedX; }
float Player::getSpeedY() { return this->speedY; }
short Player::getNumber() { return this->number; }
#endif
