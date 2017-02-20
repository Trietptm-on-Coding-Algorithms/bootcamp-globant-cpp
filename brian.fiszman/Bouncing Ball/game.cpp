#include "game.hpp"

Game::Game(Ball ball, RectangleShape rectangle, struct Screen* screen)
{
    this->ball = ball;
    this->rectangle = rectangle;
    this->screen = screen;
}

Game::~Game() { delete this->screen; }

void Game::initializeGame()
{
    WINDOW.setFramerateLimit(60);
    this->rectangle.setPosition(RES.getX() / 2, RES.getY() / 2);
    this->rectangle.setOrigin(this->rectangle.getSize().x / 2, this->rectangle.getSize().y / 2);
    this->ball.setFillColor(Color::Blue);
}

void Game::play()
{
    this->initializeGame();
    while (WINDOW.isOpen()) {
        Event event;
        while (WINDOW.pollEvent(event)) {
            if (event.type == Event::Closed)
                WINDOW.close();
        }

        this->ball.setSpeedY(this->ball.getSpeedY() + GRAVITY);
        this->ball.setSpeedY(
            this->ball.getSpeedY() - (this->ball.getSpeedY()) * SLOWDOWN);
        this->ball.setSpeedX(
            this->ball.getSpeedX() - (this->ball.getSpeedX()) * SLOWDOWN);

        if (Keyboard::isKeyPressed(UP))     this->ball.setSpeedY(this->ball.getSpeedY() - MOVEMENT_SPEED);
        if (Keyboard::isKeyPressed(DOWN))   this->ball.setSpeedY(this->ball.getSpeedY() + MOVEMENT_SPEED);
        if (Keyboard::isKeyPressed(RIGHT))  this->ball.setSpeedX(this->ball.getSpeedX() + MOVEMENT_SPEED);
        if (Keyboard::isKeyPressed(LEFT))   this->ball.setSpeedX(this->ball.getSpeedX() - MOVEMENT_SPEED);
        if (Keyboard::isKeyPressed(QUIT))   break;

        this->ball.setSpeedX((this->ball.hasCollidedOnX())
                ? -this->ball.getSpeedX()
                : this->ball.getSpeedX());
        this->ball.setSpeedY((this->ball.hasCollidedOnY(this->rectangle))
                ? -this->ball.getSpeedY()
                : this->ball.getSpeedY());

        this->ball.move(this->ball.getSpeedX() * IDLE_SPEED, this->ball.getSpeedY() * IDLE_SPEED);

        WINDOW.clear();
        WINDOW.draw(this->ball);
        WINDOW.draw(this->rectangle);
        WINDOW.display();
    }
}
