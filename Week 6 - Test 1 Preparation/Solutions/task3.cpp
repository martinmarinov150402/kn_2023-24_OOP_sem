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
        int getSize() const
        {
            return size;
        }
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

class Sequence
{
    private:
        double* arr;
        size_t capacity;
        size_t size;
        void copy(const Sequence& other);

    public:
        void addVector(Vector a);
        Sequence(const Sequence& other);
        Sequence();
        Sequence(size_t size, double* arr);
        Sequence& operator=(const Sequence& other);
        ~Sequence();
        friend std::ostream& operator<<(std::ostream& out, const Sequence& seq);

};

void Sequence::addVector(Vector a)
{
    if(capacity < size + a.getSize())
    {
        capacity = capacity + a.getSize();
        double* newArr = new double[capacity];
        for(int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    for(int i = size; i < size + a.getSize(); i++)
    {
        arr[i] = a[i - size];
    }
    size += a.getSize();
}

void Sequence::copy(const Sequence& other)
{
    size = other.size;
    capacity = other.capacity;
    arr = new double[capacity];
    for(int i = 0; i < size; i++)
    {
        arr[i] = other.arr[i];
    }
}

Sequence::Sequence(const Sequence& other)
{
    copy(other);
}
Sequence& Sequence::operator=(const Sequence& other)
{
    if(this != &other)
    {
        delete[] arr;
        copy(other);
    }
    return *this;
}
Sequence::~Sequence()
{
    delete[] arr;
}
Sequence::Sequence()
{
    size = 0;
    capacity = 10;
    arr = new double[capacity];
}
Sequence::Sequence(size_t size, double* arr)
{
    this->size = size;
    capacity = size + 10;
    this->arr = new double[capacity];
    for(int i = 0; i < size; i++)
    {
        this->arr[i] = arr[i];
    }
}

std::ostream& operator<<(std::ostream& out, const Sequence& seq)
{
    for(int i = 0; i < seq.size; i++)
    {
        out << seq.arr[i] << " ";
    }
    return out;
}

int main()
{
    Sequence seq1;
    Sequence seq2;
    Vector vec;
    vec+=5;
    vec+=8;
    vec+=16;
    vec+=88;
    seq1.addVector(vec);
    seq1.addVector(vec);
    seq1.addVector(vec);
    seq2 = seq1;
    seq2.addVector(vec);
    std::cout << seq1 << std::endl;
    std::cout << seq2 << std::endl;
}
