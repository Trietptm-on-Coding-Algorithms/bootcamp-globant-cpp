#include <SFML/Graphics.hpp>
#include "game.hpp"

int main()
{
    CircleShape ball(10.f);
    RectangleShape rectangle(Vector2f(120, 5));
    Resolution resolution(800, 600);
    Game game(ball, rectangle, resolution);
    game.play();
    return 0;
}
