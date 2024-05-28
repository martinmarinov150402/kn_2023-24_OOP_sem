#include <iostream>
#include <time.h>
#include <algorithm>

const int DEFAULT_CAPACITY = 10;
class MagicalBox
{
    private:
        int* arr;
        size_t size, capacity;
        void copy(const MagicalBox& other)
        {
            size = other.size;
            capacity = other.capacity;
            arr = new int[capacity];
            for(int i = 0; i < size; i++)
            {
                arr[i] = other.arr[i];
            }
        }
        void free()
        {
            delete[] arr;
        }
        void move(MagicalBox&& other)
        {
            size = other.size;
            capacity = other.capacity;
            arr = other.arr;
        }
    
    public:
        MagicalBox()
        {
            capacity = DEFAULT_CAPACITY;
            size = 0;
            arr = new int[capacity];
        }
        MagicalBox(const MagicalBox& other)
        {
            copy(other);
        }
        MagicalBox& operator=(const MagicalBox& other)
        {
            if(this != &other)
            {
                free();
                copy(other);
            }
            return *this;
        }
        ~MagicalBox()
        {
            free();
        }
        MagicalBox(MagicalBox&& other)
        {
            move(std::move(other));
        }
        MagicalBox& operator=(MagicalBox&& other)
        {
            if(this != &other)
            {
                free();
                move(std::move(other));
            }
            return *this;
        }
        void insert(int element)
        {
            if(size == capacity)
            {
                capacity *= 2;
                int *tmp = new int[capacity];
                for(int i = 0; i < size; i++)
                {
                    tmp[i] = arr[i];
                }
                delete[] arr;
                arr = tmp;
            }
            arr[size++] = element;
        }
        int pop()
        {
            if(size == 0)
            {
                throw "The box is empty!";
            }
            int index = rand() % size;
            std::swap(arr[index], arr[size-1]);
            size--;
            return arr[size+1];

        }

};
int main()
{
    srand(time(nullptr));
    MagicalBox mb;
    for(int i = 1; i <= 15; i++)
    {
        mb.insert(i);
    }
    for(int i = 0; i<= 15; i++)
    {
        try
        {
            std::cout << mb.pop() << std::endl;
        }
        catch(const char* error)
        {
            std::cout << error << std::endl;
        }
    }


}