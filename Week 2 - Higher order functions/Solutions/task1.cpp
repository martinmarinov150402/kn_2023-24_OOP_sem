#include <iostream>

void maxValueOfTwo(unsigned int i, unsigned int (*f1)(unsigned int), unsigned int (*f2)(unsigned int))
{
    unsigned int a1 = f1(i), a2 = f2(i);
    if(a1 > a2)
    {
        std::cout << a1 << std::endl;
    }
    else
    {
        std::cout << a2 << std::endl;
    }
}
unsigned int multBy5(unsigned int arg)
{
    return arg*5;
}
unsigned int square(unsigned int arg)
{
    return arg*arg;
}
int main()
{
    maxValueOfTwo(4,multBy5,square);
}