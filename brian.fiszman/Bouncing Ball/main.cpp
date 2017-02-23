#include "ball.hpp"
#include "game.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#define GAME_NAME "Bouncing Ball"

int main()
{
    RenderWindow window(VideoMode(800, 600), GAME_NAME);
    Ball ball(10.f);
    RectangleShape rectangle(Vector2f(120, 5));
    Game game(window, ball, rectangle);
    game.play();
    return 0;
}
