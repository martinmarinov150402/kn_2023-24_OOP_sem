#include <iostream>

template <typename T>
class Vector
{
    private:
        size_t size;
        size_t capacity;
        T* arr;

    public:
        T output(T el)
        {
            std::cout << el;
            return el;
        }
};
int main()
{

}