#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "resolution.hpp"

using namespace sf;

#define IDLE_SPEED      0.1f
#define MOVEMENT_SPEED  2.f
#define ACCELERATION    IDLE_SPEED/1
#define GRAVITY         ACCELERATION*9.81
#define SLOWDOWN        0.005

#define B_POS           this->ball.getGlobalBounds()
#define R_POS           this->rectangle.getGlobalBounds()

#define UP              Keyboard::Up
#define DOWN            Keyboard::Down
#define RIGHT           Keyboard::Right
#define LEFT            Keyboard::Left
#define QUIT            Keyboard::Q

#define GAME_TITLE      "Bouncing Ball"


class Game
{
private:
    Resolution resolution;
    RenderWindow window;
    CircleShape ball;
    RectangleShape rectangle;

public:
    Game(CircleShape ball, RectangleShape rectangle, Resolution resolution);
    ~Game(){}
    void initializeGame();
    void play();
};

#endif
