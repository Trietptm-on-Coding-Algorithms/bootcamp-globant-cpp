#include "ball.hpp"
#include "game.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#define GAME_NAME "Bouncing Ball"

int main()
{
    Player p1(1);
    Player p2(2);
    RenderWindow window(VideoMode(800, 600), GAME_NAME);
    Ball ball(10.f);
    RectangleShape rectangle(Vector2f(120, 5));
    Game game(window, ball, rectangle, p1, p2);
    game.play();
    return 0;
}
