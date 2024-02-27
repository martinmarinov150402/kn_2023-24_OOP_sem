#include <iostream>

void foreach(int *arr, size_t size, void (*fun)(int&))
{
    for(int i = 0; i < size; i++)
    {
        fun(arr[i]);
    }
}
void printInt(int& el)
{
    std::cout << el << " ";
}
void incByOne(int &el)
{
    el++;
} 
int main()
{
    int arr[] = {1,2,3,4,5};
    foreach(arr, 5, incByOne);
    foreach(arr, 5, printInt);
    

}