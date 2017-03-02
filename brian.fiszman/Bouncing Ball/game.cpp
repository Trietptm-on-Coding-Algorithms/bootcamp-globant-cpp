#include "game.hpp"
Game::Game(RenderWindow &window, Ball &ball, RectangleShape &rectangle, Player p1, Player p2): window(window), ball(ball), rectangle(rectangle), p1(p1), p2(p2){}

Game::~Game() {}

void Game::initializeGame()
{
    window.setFramerateLimit(60);
    rectangle.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
    rectangle.setOutlineThickness(4);
    ball.setPosition(700, 100);
    ball.setOrigin(ball.getRadius(), ball.getRadius());
    ball.setFillColor(Color::Blue);
}

void Game::play()
{
    CircleShape shp(1.f);
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

        ball.generateCollisions(window);
        ball.generateCollisions(rectangle);

        ball.move(ball.getSpeedX() * IDLE_SPEED, ball.getSpeedY() * IDLE_SPEED);

        shp.setPosition(ball.getPosition().x, ball.getPosition().y);
        window.clear();
        window.draw(ball);
        if(ball.shareYSpaceWith(rectangle))
        {
            window.draw(shp);
        }
        window.draw(rectangle);
        window.display();
    }
}
