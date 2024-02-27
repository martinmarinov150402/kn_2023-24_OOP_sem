#include <iostream>

int* map(int *arr,size_t size, int (*fun)(int))
{
    int* result = new int[size];
    for(int i = 0; i < size; i++)
    {
        result[i] = fun(arr[i]);
    }
    return result;
}
int square(int arg)
{
    return arg*arg;
}
int plus5(int arg)
{
    return arg+5;
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int *res = map(arr,5, square);
    int *res2 = map(arr,5, plus5);
    for(int i = 0; i < 5; i++)
    {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < 5; i++)
    {
        std::cout << res2[i] << " ";
    }
    std::cout << std::endl;
}