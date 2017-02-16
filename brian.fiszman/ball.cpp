#include <SFML/Graphics.hpp>


using namespace sf;

#define NORMAL_SPEED    0.1f
#define FAST_SPEED      0.25f

#define UP      Keyboard::Up
#define DOWN    Keyboard::Down
#define RIGHT   Keyboard::Right
#define LEFT    Keyboard::Left

int main()
{
    RenderWindow window(VideoMode(500, 500), "SFML works!");
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
        
        if(Keyboard::isKeyPressed(UP))      shape.move(0, -NORMAL_SPEED);
        if(Keyboard::isKeyPressed(DOWN))    shape.move(0, NORMAL_SPEED);
        if(Keyboard::isKeyPressed(RIGHT))   shape.move(NORMAL_SPEED, 0);
        if(Keyboard::isKeyPressed(LEFT))    shape.move(-NORMAL_SPEED, 0);       

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
