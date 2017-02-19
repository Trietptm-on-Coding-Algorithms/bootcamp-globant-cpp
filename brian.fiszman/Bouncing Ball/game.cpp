#include "game.hpp"

Game::Game(Ball ball, RectangleShape rectangle, Resolution resolution) : resolution(DEF_RES_X, DEF_RES_Y), window(VideoMode(this->resolution.getX(), this->resolution.getY()), GAME_TITLE)
{
    this->ball       = ball;
    this->rectangle  = rectangle;
    this->resolution = resolution;
}

void Game::initializeGame()
{
    this->window.setFramerateLimit(60);
    this->rectangle.setPosition(this->resolution.getX()/2, this->resolution.getY()/2);
    this->rectangle.setOrigin(this->rectangle.getSize().x/2, this->rectangle.getSize().y/2);
    this->ball.setFillColor(Color::Blue);
}

void Game::play()
{
    this->initializeGame();
    while (this->window.isOpen())
    {
        Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                this->window.close();
        }
        
        this->ball.setSpeedY(this->ball.getSpeedY() + GRAVITY);
        this->ball.setSpeedY(this->ball.getSpeedY() - (this->ball.getSpeedY())*SLOWDOWN);
        this->ball.setSpeedX(this->ball.getSpeedX() - (this->ball.getSpeedX())*SLOWDOWN);

        if(Keyboard::isKeyPressed(UP))      this->ball.setSpeedY(this->ball.getSpeedY() - MOVEMENT_SPEED); 
        if(Keyboard::isKeyPressed(DOWN))    this->ball.setSpeedY(this->ball.getSpeedY() + MOVEMENT_SPEED); 
        if(Keyboard::isKeyPressed(RIGHT))   this->ball.setSpeedX(this->ball.getSpeedX() + MOVEMENT_SPEED); 
        if(Keyboard::isKeyPressed(LEFT))    this->ball.setSpeedX(this->ball.getSpeedX() - MOVEMENT_SPEED); 
        if(Keyboard::isKeyPressed(QUIT))    break;

        this->ball.setSpeedX((this->ball.hasCollidedOnX(this->resolution)) ? -this->ball.getSpeedX() : this->ball.getSpeedX());
        this->ball.setSpeedY((this->ball.hasCollidedOnY(this->rectangle, this->resolution)) ? -this->ball.getSpeedY() : this->ball.getSpeedY());

        this->ball.move(this->ball.getSpeedX()*IDLE_SPEED, this->ball.getSpeedY()*IDLE_SPEED);

        this->window.clear();
        this->window.draw(this->ball);
        this->window.draw(this->rectangle);
        this->window.display();
    }
}
