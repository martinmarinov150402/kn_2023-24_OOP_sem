#include <iostream>

void f(int&& num)
{
    std::cout << num;
}
int main()
{
    f(5);
}