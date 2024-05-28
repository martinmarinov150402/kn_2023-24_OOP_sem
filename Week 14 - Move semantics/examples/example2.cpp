#include <iostream>

void f(int &&n)
{
    std::cout << n << '\n';
}

int main()
{
    int number = 10;
    f(std::move(number));
    return 0;
}