#include <iostream>

template<typename T>
void printArray(T array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int int_arr[] = {1,5,6,8};
    char char_arr[] = {'6', 'd', 'v', 'a'};
    printArray<int>(int_arr, 4);
    printArray<char>(char_arr, 4);
}