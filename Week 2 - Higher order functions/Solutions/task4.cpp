#include <iostream>

void sortByGivenComp(int *arr, size_t size, bool (*compare)(int, int))
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(compare(arr[i], arr[j]))
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

bool comp(int a, int b)
{
    return a < b;
}

int main()
{
    int arr[] = {7, -5, 9, 0, 16, 25};
    sortByGivenComp(arr, 6, comp);
    for(int i = 0; i < 6; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

}