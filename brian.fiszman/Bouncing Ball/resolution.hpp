#define DEF_RES_X 800
#define DEF_RES_Y 600

class Resolution {
    private:
        unsigned int resX;
        unsigned int resY;
    public:
        Resolution(unsigned int resX, unsigned int resY);
        unsigned int getX();
        unsigned int getY();
};

