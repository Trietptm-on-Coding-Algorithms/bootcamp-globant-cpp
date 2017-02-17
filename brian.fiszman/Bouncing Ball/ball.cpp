#include <SFML/Graphics.hpp>

using namespace sf;

#define IDLE_SPEED      0.1f
#define MOVEMENT_SPEED  2.f
#define ACCELERATION    IDLE_SPEED/1
#define GRAVITY         ACCELERATION*9.81
#define SLOWDOWN        0.005

#define B_POS            ball.getGlobalBounds()
#define R_POS            rectangle.getGlobalBounds()

#define UP              Keyboard::Up
#define DOWN            Keyboard::Down
#define RIGHT           Keyboard::Right
#define LEFT            Keyboard::Left

int main()
{
    int resX = 800;
    int resY = 600;
    float speedX = 0, speedY = 0;
   
    RenderWindow window(VideoMode(resX, resY), "Bouncing Ball!");
    window.setFramerateLimit(60);
    CircleShape ball(10.f);
    RectangleShape rectangle(Vector2f(120, 5)); 
    rectangle.setPosition(resX/2, resY/2);
    rectangle.setOrigin(rectangle.getSize().x/2, rectangle.getSize().y/2);
    ball.setFillColor(Color::Blue);
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
        
        speedX = ((B_POS.left < 0 && speedX < 0) || (B_POS.left+B_POS.width > resX && speedX > 0)) ?
            -speedX : speedX;
        speedY = ((B_POS.top < 0 && speedY < 0) || (B_POS.top+B_POS.height > resY && speedY > 0) ||
                (B_POS.intersects(R_POS))) ?
            -speedY : speedY;
        
        ball.move(speedX*IDLE_SPEED, speedY*IDLE_SPEED);

        window.clear();
        window.draw(ball);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
