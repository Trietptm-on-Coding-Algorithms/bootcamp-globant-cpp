#include "resolution.hpp"

Resolution::Resolution(unsigned int resX, unsigned int resY) : resX(DEF_RES_X), resY(DEF_RES_Y)
{
    this->resX = resX;
    this->resY = resY;
}

unsigned int Resolution::getX() { return this->resX; }
unsigned int Resolution::getY() { return this->resY; }
