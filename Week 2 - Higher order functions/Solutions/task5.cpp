#include <iostream>

struct int_array
{
    int *arr;
    size_t size;
};
int_array filter(int *arr, size_t size, bool (*pred)(int))
{
    size_t count = 0;
    for(int i = 0; i < size; i++)
    {
        if(pred(arr[i]))
        {
            count++;
        }
    }
    int* result = new int[count];
    size_t idx = 0;
    for(int i = 0; i < size; i++)
    {   
        if(pred(arr[i]))
        {
            result[idx++] = arr[i];
        }
    }
    return {result, count};
}

bool isEven(int num)
{
    return num % 2 == 0;
}

int_array fun(int *arr, size_t size)
{
    return filter(arr, size, isEven);
}

int main()
{
    int arr[] = {5, 8, 7, 6, 2, 1};
    int_array res = fun(arr, 6);
    for(int i = 0; i < res.size; i++)
    {
        std::cout << res.arr[i] << " ";
    }
    std::cout << std::endl;
}