#include <iostream>

class Animal
{
    public:
        virtual void sound() = 0;
};

class Cat: public Animal
{
    public:
        void sound() override
        {
            std::cout << "Meow" << std::endl;
        }   
};
class Dog: public Animal
{
    public:
        void sound() override
        {
            std::cout << "Bark" << std::endl;
        }   
};
class Cow: public Animal
{
    public:
        void sound() override
        {
            std::cout << "Mooo" << std::endl;
        }   
};

class Zoo
{
    private:
        Animal** arr;
        size_t size;
        size_t capacity;

    public:
        size_t getSize() const
        {
            return size;
        }
        Animal* operator[](size_t idx)
        {
            return arr[idx];
        }
        Zoo()
        {
            capacity = 10;
            size = 0;
            arr = new Animal*[capacity];
        }
        void add(Animal* animal)
        {
            if(size >= capacity)
            {
                capacity = capacity * 2;
                Animal** tmp = new Animal*[capacity];
                for(int i = 0; i < size; i++)
                {
                    tmp[i] = arr[i];
                }
                delete[] arr;
                arr = tmp;
            }
            arr[size++] = animal; 
        }
        ~Zoo()
        {
            for(int i = 0; i < size; i++)
            {
                delete arr[i];
            }
            delete[] arr;
        }

};

int main()
{
    Animal* ptr = new Cow();
    Zoo zoo;
    zoo.add(ptr);
    ptr = new Cat();
    zoo.add(ptr);
    ptr = new Dog();
    zoo.add(ptr);
    for(int i = 0; i < zoo.getSize(); i++)
    {
        zoo[i]->sound();
    }
}