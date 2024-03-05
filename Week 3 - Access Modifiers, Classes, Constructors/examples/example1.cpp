#include <iostream>

class Point 
{
    public: 
        double x;
        double y;
        int setX();
}

int Point::setX(double _x) {
    x = _x;
}