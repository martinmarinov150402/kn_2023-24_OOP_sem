#include <iostream>

int* map(int* arr, size_t size, int (*fun)(int))
{
    int* arrCpy = new int[size];
    for(int i = 0; i < size; i++)
    {
        arrCpy[i] = fun(arr[i]);
    }
    return arrCpy;
}
int main()
{
    int arr[] = {1,2,3,4};
    int* arrMultBy2 = map(arr, 4, [](int el)->int{return el * 2;});
    for(int i = 0; i < 4; i++)
    {
        std::cout << arrMultBy2[i] << " ";
    }
}