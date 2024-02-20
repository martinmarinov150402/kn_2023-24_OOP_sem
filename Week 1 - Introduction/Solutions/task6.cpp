#include <iostream>

template <typename T>
int getMaxElementIndex(T arr[], int size)
{
    int maxEl = arr[0];
    int maxIndex = 0;
    for(int i = 1; i < size; i++)
    {
        if(maxEl < arr[i])
        {
            maxEl = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main()
{
    int arr[] = {5, 1, 8, 4};
    std::cout << getMaxElementIndex<int>(arr, 4) << std::endl;
}