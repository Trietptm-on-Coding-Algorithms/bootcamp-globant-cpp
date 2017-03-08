#include "ball.hpp"
#include "game.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#define GAME_NAME "Bouncing Ball"

int main()
{
    RenderWindow window(VideoMode(800, 600), GAME_NAME);
    Player p1(1, window);
    Player p2(2, window);
    Ball ball(10.f);
    Game game(window, ball, p1, p2);
    game.play();
    return 0;
}
