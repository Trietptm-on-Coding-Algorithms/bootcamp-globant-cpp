#include "game.hpp"

Game::Game(RenderWindow &window, Ball &ball, RectangleShape &rectangle): window(window), ball(ball), rectangle(rectangle){}

Game::~Game() {}

void Game::initializeGame()
{
    window.setFramerateLimit(60);
    rectangle.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
    ball.setFillColor(Color::Blue);
}

void Game::play()
{
    initializeGame();
    while (window.isOpen()) 
    {
        Event event;
        while (window.pollEvent(event)) 
            if (event.type == Event::Closed)
                window.close();

        ball.setSpeedY(ball.getSpeedY() + GRAVITY);
        ball.setSpeedY(ball.getSpeedY() - (ball.getSpeedY()) * SLOWDOWN);
        ball.setSpeedX(ball.getSpeedX() - (ball.getSpeedX()) * SLOWDOWN);

        if (Keyboard::isKeyPressed(UP))     ball.setSpeedY(ball.getSpeedY() - MOVEMENT_SPEED);
        if (Keyboard::isKeyPressed(DOWN))   ball.setSpeedY(ball.getSpeedY() + MOVEMENT_SPEED);
        if (Keyboard::isKeyPressed(RIGHT))  ball.setSpeedX(ball.getSpeedX() + MOVEMENT_SPEED);
        if (Keyboard::isKeyPressed(LEFT))   ball.setSpeedX(ball.getSpeedX() - MOVEMENT_SPEED);
        if (Keyboard::isKeyPressed(QUIT))   break;

        ball.setSpeedX((ball.hasCollidedOnX(window)) ? -ball.getSpeedX() : ball.getSpeedX());
        ball.setSpeedY((ball.hasCollidedOnY(window, rectangle)) ? -ball.getSpeedY() : ball.getSpeedY());

        ball.move(ball.getSpeedX() * IDLE_SPEED, ball.getSpeedY() * IDLE_SPEED);

        window.clear();
        window.draw(ball);
        window.draw(rectangle);
        window.display();
    }
}
