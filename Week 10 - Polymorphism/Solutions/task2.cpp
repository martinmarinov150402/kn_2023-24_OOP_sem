#include "task1.hpp"

class CarArray
{
    private:
        Car** arr;
        size_t size;
        size_t capacity;

    public:
        CarArray();
        CarArray(const CarArray&);
        CarArray& operator=(const CarArray&);
        ~CarArray();
        void push(Car* ptr);
        void foreach(void (*foo)(Car*));
};

void CarArray::foreach(void (*foo)(Car*))
{
    for(int i = 0; i < size; i++)
    {
        foo(arr[i]);
    }
}

CarArray::CarArray()
{
    capacity = 10;
    size = 0;
    arr = new Car*[capacity];
}
CarArray::CarArray(const CarArray& other)
{
    size = other.size;
    capacity = other.capacity;
    arr = new Car*[capacity];
    for(int i = 0; i < size; i++)
    {
        arr[i] = other.arr[i]->clone();
    }
}
CarArray& CarArray::operator=(const CarArray& other)
{
    if(this != &other)
    {
        delete[] arr;
        size = other.size;
        capacity = other.capacity;
        arr = new Car*[capacity];
        for(int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i]->clone();
        }
    }
    return *this;
}
CarArray::~CarArray()
{
    for(int i = 0; i < size; i++)
    {
        delete arr[i];
    }
    delete[] arr;
}
void CarArray::push(Car* ptr)
{
    if(size >= capacity)
    {
        capacity *= 2;
        Car** tmp = new Car*[capacity];
        for(int i = 0; i < size; i++)
        {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
    }
    arr[size++] = ptr;
}
int main()
{
    CarArray arrayOfCars;
    Car *a = new NormalCar("Renault", 100, 50);
    Car *b = new SportsCar("Ferrary", 400, 260);
    Car *c = new NormalCar("Audi", 150, 40);
    Car *d = new NormalCar("BMW", 150, 10);
    Car *e = new SportsCar("Brabus", 260, 200);
    arrayOfCars.push(a);
    arrayOfCars.push(b);
    arrayOfCars.push(c);
    arrayOfCars.push(d);
    arrayOfCars.push(e);
    arrayOfCars.foreach([](Car* el)->void {el->identify();});
}