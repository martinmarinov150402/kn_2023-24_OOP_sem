#include <iostream>

class Point
{
    private: 
        double x;
        double y;

    public: 
        void setX(double);
        void setY(double);
        Point();
};

void Point::setX(double _x)
{
    x = _x;
}
void Point::setY(double _y)
{
    y = _y;
}
Point::Point()
{
    std::cout << "Point was created" << std::endl;
}

int main()
{
    Point a, b;
}