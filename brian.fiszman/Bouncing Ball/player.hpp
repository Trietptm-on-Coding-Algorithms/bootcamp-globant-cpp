#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
public:
    Player(short number, RenderWindow& window);

    RectangleShape getPaddle();
    void setSpeedX(float);
    void setSpeedY(float);
    void setNumber(short);
    void move(float, float);
    void generateCollisions(const RenderWindow& window);
    bool hasCollidedOnX(const RenderWindow& window);
    bool hasCollidedOnY(const RenderWindow& window);
    float getSpeedX();
    float getSpeedY();
    short getNumber();
private:
    RectangleShape pad;
    float speedX, speedY;
    short number;
    RenderWindow& window;
};
