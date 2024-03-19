#include <iostream>

class Triangle
{
    private:
        int a, b, c;
    
    friend std::istream& operator>>(std::istream& in, Triangle& triangle);
    friend std::ostream& operator<<(std::ostream& out, const Triangle& triangle);
};

std::istream& operator>>(std::istream& in, Triangle& triangle)
{
    in >> triangle.a >> triangle.b >> triangle.c;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Triangle& triangle)
{
    out << triangle.a << " " << triangle.b << " " << triangle.c;
    return out;
}
int main()
{
    Triangle a;
    std::cin >> a;
    std::cout << a << std::endl;
}