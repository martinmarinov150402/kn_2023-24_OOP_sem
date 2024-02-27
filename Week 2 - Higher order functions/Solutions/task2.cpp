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
bool biggerThanFive(int num)
{
    return num > 5;
}
int main()
{
    int arr[] = {29, 2, 7, -3, 6};
    int_array result = filter(arr,5,biggerThanFive);
    for(int i = 0; i < result.size; i++)
    {
        std::cout << result.arr[i] << " ";
    }
    std::cout << std::endl;

}