#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
public:
    Player(short number);

    RectangleShape getPaddle();
    void setSpeedX(float);
    void setSpeedY(float);
    void setNumber(short);
    float getSpeedX();
    float getSpeedY();
    short getNumber();
private:
    RectangleShape pad;
    float speedX, speedY;
    short number;
};
