#include <iostream>

class Vector
{
    private:
        double arr[20];
        size_t size;
    
    public:
        double operator[](size_t idx);
        Vector operator+(double el);
        Vector& operator+=(double el);
        bool operator<(const Vector& other);
        bool operator==(const Vector& other);
        Vector();
        Vector(size_t size, double* arr);
};

double Vector::operator[](size_t idx)
{
    if(idx < 0 || idx >= size)
    {
        return 0;
    }
    return arr[idx];
}

Vector Vector::operator+(double el)
{

    if(size == 20)
    {
        return *this;
    }
    Vector result = *this;
    result.arr[result.size++] = el;
    return result;
}
Vector& Vector::operator+=(double el)
{
    if(size == 20)
    {
        return *this;
    }

    arr[size++] = el;
    return *this;
}

bool Vector::operator<(const Vector& other)
{
    return size < other.size;
}

bool Vector::operator==(const Vector& other)
{
    return size == other.size;
}

Vector::Vector()
{
    size = 0;
}
Vector::Vector(size_t size, double arr[])
{
    if(size > 20 || size <= 0)
    {
        this->size = 0;
    }
    else 
    {
        this->size = size;
        for(int i = 0; i < size; i++)
        {
            this->arr[i] = arr[i];
        }
    }
}

int main()
{
    Vector a,b;
    a+=5;
    b = b + 6;
    std::cout << a[0] << " " << b[0] << std::endl;
    std::cout << std::boolalpha << (a == b) << std::endl;
}
