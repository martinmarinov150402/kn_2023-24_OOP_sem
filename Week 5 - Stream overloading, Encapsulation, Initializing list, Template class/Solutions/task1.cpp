#include <iostream>

template<typename T>
class Vector
{
    private: 
        size_t size;
        size_t capacity;
        T* arr;
        void copy(const Vector& other);
        void free();

    public:
        Vector();
        ~Vector();
        Vector(const Vector& other);
        Vector& operator=(const Vector& other);
        void push(T el);
        T pop();
        T& operator[](size_t idx);
        size_t getSize();

};

template<typename T>
size_t Vector<T>::getSize()
{
    return size;
}
template<typename T>
Vector<T>::Vector()
{
    size = 0;
    capacity = 10;
    arr = new T[capacity];   
}

template<typename T>
void Vector<T>::copy(const Vector<T>& other)
{
    size = other.size;
    capacity = other.capacity;
    arr = new T[capacity];
    for(int i = 0; i < size; i++)
    {
        arr[i] = other.arr[i];
    }
}

template<typename T>
void Vector<T>::free()
{
    delete[] arr;
}


template<typename T>
Vector<T>::~Vector()
{
    free();
}

template<typename T>
Vector<T>::Vector(const Vector& other)
{
    copy(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if(this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

template<typename T>
void Vector<T>::push(T el)
{
    if(size == capacity)
    {
        T* arr2 = new T[capacity * 2];
        capacity *= 2;
        for(int i = 0; i < size; i++)
        {
            arr2[i] = arr[i];
        }
        delete[] arr;
        arr = arr2;
    }

    arr[size++] = el;
}

template<typename T>
T Vector<T>::pop()
{
    size--;
    return arr[size];
}

template<typename T>
T& Vector<T>::operator[](size_t idx)
{
    return arr[idx];
}

int main()
{
    Vector<int> a;
    for(int i = 0; i < 6; i++)
    {
        a.push(i);
    }
    a.pop();

    for(int i = 0; i < a.getSize(); i++)
    {

        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}


