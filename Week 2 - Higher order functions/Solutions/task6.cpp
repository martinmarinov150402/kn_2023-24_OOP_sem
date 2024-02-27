#include <iostream>

int accumulate(int* arr, size_t size, int (*mod)(int), int start,int (*fun)(int, int), int (*next)(int))
{
    int result = start;
    for(int i = 0; i < size; i = next(i))
    {
        result = fun(result, mod(arr[i]));
    }
    return result;
}

int sum(int a, int b)
{
    return a+b;
}
int next(int a)
{
    return a+1;
}
int id(int a)
{
    return a;
}
int mod(int a)
{
    return a*a;
}
int mult(int a, int b)
{
    return a * b;
}
int modEven(int a)
{
    if(a % 2 == 0)
    {
        return a;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int sum1 = accumulate(arr, 5, id, 0, sum, next);
    int sum2 = accumulate(arr, 5, mod, 0, sum, next);
    int prod = accumulate(arr, 5, id, 1, mult, next);
    int sumOfEvens = accumulate(arr, 5, modEven,0, sum, next);
    std::cout << sum1 << " " << sum2 << " " << prod << " " << sumOfEvens << std::endl;

}