#include <iostream>

double deriv(double a, double (*fun)(double))
{
    const double eps = 0.0001;
    return (fun(a+eps) - fun(a))/eps;
}
double square(double a)
{
    return a*a;
}
int main()
{
    std::cout << deriv(5, square) << std::endl;
}