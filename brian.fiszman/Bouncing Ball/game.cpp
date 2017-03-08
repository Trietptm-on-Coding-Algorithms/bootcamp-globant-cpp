#include "game.hpp"
Game::Game(RenderWindow& window, Ball& ball, Player& p1, Player& p2)
    : window(window)
    , ball(ball)
    , p1(p1)
    , p2(p2)
{
}

Game::~Game() {}

void Game::initializeGame()
{
    window.setFramerateLimit(60);
    p1.getPaddle().setPosition(window.getSize().x / 2, window.getSize().y / 2);
    ball.setPosition(700, 100);
    ball.setOrigin(ball.getRadius(), ball.getRadius());
    ball.setFillColor(Color::Blue);
    ball.setSpeedX(50);
    ball.setSpeedY(50);
}

void Game::play()
{
    initializeGame();
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        if (Keyboard::isKeyPressed(RIGHT))
            p1.setSpeedX(p1.getSpeedX() + MOVEMENT_SPEED);
        if (Keyboard::isKeyPressed(LEFT))
            p1.setSpeedX(p1.getSpeedX() - MOVEMENT_SPEED);
        if (Keyboard::isKeyPressed(Keyboard::D))
            p2.setSpeedX(p2.getSpeedX() + MOVEMENT_SPEED);
        if (Keyboard::isKeyPressed(Keyboard::A))
            p2.setSpeedX(p2.getSpeedX() - MOVEMENT_SPEED);
        if (Keyboard::isKeyPressed(QUIT))
            break;


        ball.generateCollisions(window);
        ball.generateCollisions(p1.getPaddle());
        ball.generateCollisions(p2.getPaddle());
        p1.generateCollisions(window);
        p1.move(p1.getSpeedX() * IDLE_SPEED, p1.getSpeedY() * IDLE_SPEED);
        p2.generateCollisions(window);
        p2.move(p2.getSpeedX() * IDLE_SPEED, p2.getSpeedY() * IDLE_SPEED);
        ball.move(ball.getSpeedX() * IDLE_SPEED, ball.getSpeedY() * IDLE_SPEED);

        window.clear();
        window.draw(ball);
        window.draw(p1.getPaddle());
        window.draw(p2.getPaddle());
        window.display();
    }
}
