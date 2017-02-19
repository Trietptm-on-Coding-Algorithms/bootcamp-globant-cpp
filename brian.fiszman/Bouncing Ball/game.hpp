#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "resolution.hpp"
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

#define GAME_TITLE      "Bouncing Ball"

class Game
{
private:
    Resolution resolution;
    RenderWindow window;
    Ball ball;
    RectangleShape rectangle;
    void initializeGame();

public:
    Game(Ball ball, RectangleShape rectangle, Resolution resolution);
    ~Game(){}
    void play();
};

#endif
