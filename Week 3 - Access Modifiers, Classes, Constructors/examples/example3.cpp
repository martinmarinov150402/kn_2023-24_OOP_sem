#include <iostream>

class Point
{
    private: 
        double x;
        double y;

    public: 
        Point();
        Point(double _x, double _y);
        double getX() const;
        double getY() const;
};

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double _x, double _y)
{
    x = _x;
    y = _y;
}

double Point::getX() const
{
    return x;
}
double Point::getY() const
{
    return y;
}
int main()
{
    Point a(5,8), b;
    std::cout << "Point A is ("<<a.getX() << ", " << a.getY() << ") " << std::endl
              << "Point B is ("<<b.getX() << ", " << b.getY() << ") " << std::endl;
}