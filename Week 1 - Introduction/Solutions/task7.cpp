#include <iostream>

template <typename T>
bool isInArray(T arr[], int size, T a)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == a)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[] = {8,6,3,7,2,9};
    std::cout << std::boolalpha << isInArray<int>(arr,6,3)  << std::endl
                                << isInArray<int>(arr,6,10) << std::endl;
}