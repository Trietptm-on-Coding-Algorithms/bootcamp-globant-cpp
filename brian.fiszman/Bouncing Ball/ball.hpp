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
    bool shareXSpaceWith(const RectangleShape& shp);
    bool shareYSpaceWith(const RectangleShape& shp);
    bool hasCollided(const RenderWindow& window);
    bool hasCollided(const RectangleShape& shp); 
    bool hasCollidedOnX(const RenderWindow& window);
    bool hasCollidedOnX(const RectangleShape& shp);
    bool hasCollidedOnY(const RenderWindow& window);
    bool hasCollidedOnY(const RectangleShape& shp);
    void generateCollisions(const RectangleShape &shp);
    void generateCollisions(const RenderWindow &window);
};

#endif
