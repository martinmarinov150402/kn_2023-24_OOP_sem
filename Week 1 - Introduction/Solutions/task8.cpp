#include <iostream>

template <typename T>
void change(T arr[], int size, T a, T b)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == a)
        {
            arr[i] = b;
        }
    }
}

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
    int arr[] = {2,2,2,4,5,6,5,4};
    change<int>(arr,8,2,3);
    printArray<int>(arr,8);
}   