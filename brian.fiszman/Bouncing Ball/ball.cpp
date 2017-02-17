#include <SFML/Graphics.hpp>

using namespace sf;

#define NORMAL_SPEED    0.1f
#define MOVEMENT_SPEED  2.f
#define ACCELERATION    NORMAL_SPEED/1
#define GRAVITY         ACCELERATION*9.81
#define SLOWDOWN        0.005

#define UP      Keyboard::Up
#define DOWN    Keyboard::Down
#define RIGHT   Keyboard::Right
#define LEFT    Keyboard::Left

int main()
{
    int resolutionX = 800;
    int resolutionY = 600;
    float speedX = 0, speedY = 0;
    
    RenderWindow window(VideoMode(resolutionX, resolutionY), "Bouncing Ball!");
    window.setFramerateLimit(60);
    CircleShape shape(10.f);
    shape.setFillColor(Color::Blue);
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
        
        speedX = ((shape.getGlobalBounds().left < 0 && speedX < 0) ||
                (shape.getGlobalBounds().left+shape.getGlobalBounds().width > resolutionX && speedX > 0)) ?
            -speedX : speedX;
        speedY = ((shape.getGlobalBounds().top < 0 && speedY < 0) ||
                (shape.getGlobalBounds().top+shape.getGlobalBounds().width > resolutionY && speedY > 0)) ?
            -speedY : speedY;
        
        shape.move(speedX*NORMAL_SPEED, speedY*NORMAL_SPEED);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
