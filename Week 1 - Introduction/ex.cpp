#include <iostream>

template <typename T>
void print(T a)
{
    std::cout << a;
}

int main()
{

    int n = 1;
    double d = 1.5;
    char c = 'b';
    print<int>(n);
    print<double>(d);
    print<char>(c);
}