#include <SFML/Graphics.hpp>
#ifndef BALL_H
#define BALL_H

using namespace sf;

class Ball : public CircleShape {
    typedef CircleShape Super;

private:
    float speedX;
    float speedY;

public:
    Ball();
    Ball(float size);
    float getSpeedX();
    float getSpeedY();
    void setSpeedX(float speedX);
    void setSpeedY(float speedY);
    bool hasCollidedOnX(const RenderWindow& window);
    bool hasCollidedOnY(const RenderWindow& window, const RectangleShape& shp);
};

#endif
