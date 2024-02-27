#include <iostream>

int multBy5(int a)
{
    return a * 5;
}
void printResult(int x, int (*fun)(int))
{
    std::cout << "Result is: " << fun(x) << std::endl;
}
int main()
{
    printResult(5, multBy5);
}