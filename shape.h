#include <iostream>
#include <string>
enum type
{
    CIRCLE = 0,
    RECTANGLE
};

enum color
{
    RED = 0,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    CYAN,
    PURPLE
};
struct shape
{
    //common
    int type;
    int color;

    //circle
    int xCenter, yCenter, radius;

    //rectangle
    int xLeftUpCorner, yLeftUpCorner;
    int xRightDownCorner, yRightDownCorner;
};


