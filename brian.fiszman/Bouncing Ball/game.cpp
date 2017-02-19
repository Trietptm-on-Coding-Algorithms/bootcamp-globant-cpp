#include "game.hpp"

Game::Game(CircleShape ball, RectangleShape rectangle, Resolution resolution) : resolution(DEF_RES_X, DEF_RES_Y) 
{
    this->resolution = resolution;
    this->ball       = ball;
    this->rectangle  = rectangle;
}

void Game::play()
{
    float speedX = 0, speedY = 0;
    RenderWindow window(VideoMode(this->resolution.getX(), this->resolution.getY()), "Bouncing Ball!");
    window.setFramerateLimit(60);
    this->rectangle.setPosition(this->resolution.getX()/2, this->resolution.getY()/2);
    this->rectangle.setOrigin(this->rectangle.getSize().x/2, this->rectangle.getSize().y/2);
    this->ball.setFillColor(Color::Blue);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        speedY += GRAVITY;
        speedY -= SLOWDOWN*speedY;
        speedX -= SLOWDOWN*speedX;

        if(Keyboard::isKeyPressed(UP))      speedY -= MOVEMENT_SPEED; 
        if(Keyboard::isKeyPressed(DOWN))    speedY += MOVEMENT_SPEED; 
        if(Keyboard::isKeyPressed(RIGHT))   speedX += MOVEMENT_SPEED; 
        if(Keyboard::isKeyPressed(LEFT))    speedX -= MOVEMENT_SPEED; 
        
        speedX = ((B_POS.left < 0 && speedX < 0) || (B_POS.left+B_POS.width > resolution.getX() && speedX > 0)) ?
            -speedX : speedX;
        speedY = ((B_POS.top < 0 && speedY < 0) || (B_POS.top+B_POS.height > resolution.getY() && speedY > 0) ||
                (B_POS.intersects(R_POS))) ?
            -speedY : speedY;
        
        this->ball.move(speedX*IDLE_SPEED, speedY*IDLE_SPEED);

        window.clear();
        window.draw(this->ball);
        window.draw(this->rectangle);
        window.display();
    }
}
