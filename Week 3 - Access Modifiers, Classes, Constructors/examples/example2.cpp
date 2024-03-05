#include <iostream>

class Point 
{
    private: 
        double x;
        double y;
    
    public:
        int setX();
}

int Point::setX(double _x) {
    x = _x;
}