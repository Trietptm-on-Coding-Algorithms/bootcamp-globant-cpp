#include "screen.hpp"

Screen::Screen(): window(VideoMode(this->resolution.getX(), this->resolution.getY()), GAME_TITLE){}
Resolution Screen::resolution(DEF_RES_X, DEF_RES_Y);
