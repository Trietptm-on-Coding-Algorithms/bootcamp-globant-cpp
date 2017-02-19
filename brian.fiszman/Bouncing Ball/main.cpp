#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "ball.hpp"

int main()
{
    struct Screen *screen = new Screen();
    Ball ball(10.f);
    RectangleShape rectangle(Vector2f(120, 5));
    Game game(ball, rectangle, screen);
    game.play();
    return 0;
}
