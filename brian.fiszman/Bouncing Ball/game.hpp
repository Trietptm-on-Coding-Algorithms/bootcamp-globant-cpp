#ifndef GAME_H
#define GAME_H
#include "ball.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

#define IDLE_SPEED 0.1f
#define MOVEMENT_SPEED 2.f
#define ACCELERATION IDLE_SPEED / 1
#define GRAVITY ACCELERATION * 9.81
#define SLOWDOWN 0.005

#define RIGHT Keyboard::Right
#define LEFT Keyboard::Left
#define QUIT Keyboard::Q

class Game {
private:
    RenderWindow& window;
    Ball ball;
    Player p1;
    Player p2;

    void initializeGame();

public:
    Game(RenderWindow& window, Ball& ball, Player& p1, Player& p2);
    ~Game();
    void play();
};

#endif
