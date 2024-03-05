#include <iostream>
#include <cmath>

class Triangle
{
    private: 
        double a,b,c;
    
    public:
        Triangle();
        Triangle(double _a, double _b, double _c);
        double perimeter() const;
        double area() const;

};

Triangle::Triangle()
{
    a = 3;
    b = 4;
    c = 5;
}

Triangle::Triangle(double _a, double _b, double _c)
{
    if(_a < _b + _c && _a > fabs(_b - _c) &&
       _b < _a + _c && _b > fabs(_a - _c) &&
       _c < _a + _b && _c > fabs(_a - _b)) {

        a = _a;
        b = _b;
        c = _c;
    }
    else 
    {
        a = 3;
        b = 4;
        c = 5;
    }
}
double Triangle::perimeter() const
{
    return a + b + c;
}
double Triangle::area() const
{
    double p = perimeter() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
int main()
{
    Triangle a, b(1, 8, 2), c (5, 12, 13);
    std::cout << a.perimeter() << " " << b.perimeter() << " " << c.perimeter() << std::endl;
    std::cout << a.area() << " " << b.area() << " " << c.area() << std::endl;
}