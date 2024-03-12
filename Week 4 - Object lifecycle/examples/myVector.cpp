#include <iostream>

const size_t DEFAULT_CAPACITY = 10;

class MyVector
{
    private: 
        int *arr;
        size_t size;
        size_t capacity;
        void copy(const MyVector& a)
        void free();

    public:
        MyVector();
        MyVector(const MyVector& a);
        MyVector& operator=(const MyVector& a);
        ~MyVector();
        void push(int el);
        void print();
};

void MyVector::free()
{
    delete[] arr;
}

void MyVector::copy(const MyVector& a)
{

    size = a.size;
    capacity = a.capacity;
    arr = new int[capacity];
    for(int i = 0; i < size; i++)
    {
        arr[i] = a.arr[i];
    }
}

MyVector::MyVector()
{
    size = 0;
    capacity = DEFAULT_CAPACITY;
    arr = new int[capacity];
}

MyVector::MyVector(const MyVector& a)
{
    copy(a);
}

MyVector& MyVector::operator=(const MyVector& a)
{
    if(this != &a)
    {
        free();
        copy(a);
    }
    return *this;
}
MyVector::~MyVector()
{
    free();
}
void MyVector::push(int el)
{
    if(size == capacity)
    {
        capacity *= 2;
        int* newArr = new int[capacity];
        for(int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    arr[size++] = el;
}
void MyVector::print()
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    MyVector a;
    a.push(5);
    a.push(6);
    MyVector b = a;
    MyVector c;
    c = a;
    a.print();
    b.print();
    c.print();

}
