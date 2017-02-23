#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "ball.hpp"

using namespace sf;

#define IDLE_SPEED      0.1f
#define MOVEMENT_SPEED  2.f
#define ACCELERATION    IDLE_SPEED/1
#define GRAVITY         ACCELERATION*9.81
#define SLOWDOWN        0.005

#define UP              Keyboard::Up
#define DOWN            Keyboard::Down
#define RIGHT           Keyboard::Right
#define LEFT            Keyboard::Left
#define QUIT            Keyboard::Q

class Game
{
private:
    RenderWindow &window;
    Ball ball;
    RectangleShape rectangle;
    void initializeGame();

public:
    Game(RenderWindow &window, Ball &ball, RectangleShape &rectangle);
    ~Game();
    void play();
};

#endif
