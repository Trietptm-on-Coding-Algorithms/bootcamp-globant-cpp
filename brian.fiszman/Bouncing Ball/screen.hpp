#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include "resolution.hpp"

#define GAME_TITLE      "Bouncing Ball"
#define RES             Screen::resolution
#define WINDOW          this->screen->window

using namespace sf;
struct Screen
{
    static Resolution resolution;
    RenderWindow window;

    Screen();
};

#endif /* SCREEN_H */
