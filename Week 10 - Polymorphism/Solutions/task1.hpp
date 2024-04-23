#ifndef __CARINC
#define __CARINC

#include <iostream>
#include <cstring>

class Car
{
    private:
        char* name;
        size_t capacity;
        int hp;

    public:
        Car();
        Car(const Car& other);
        Car* clone();
        Car& operator=(const Car& other);
        virtual ~Car();
        virtual void identify();
        void setName(char* name)
        {
            if(strlen(name) > capacity)
            {
                delete[] name;
                capacity = strlen(name) + 1;
                name = new char[capacity];
            }
            strcpy(this->name, name);
        }
        void setHP(int hp)
        {
            this->hp = hp;
        }
};

class SportsCar: public Car
{
    private:
        int maxSpeed;

    public:
        void identify() override;
        SportsCar(char* name, int hp, int maxSpeed)
        {
            this->setName(name);
            this->setHP(hp);
            this->maxSpeed = maxSpeed;

        }
};

class NormalCar: public Car
{
    private:
        int comfortIndex;
    public:
        void identify() override;
        NormalCar(char *name, int hp, int comfortIndex)
        {
            this->setName(name);
            this->setHP(hp);
            this->comfortIndex = comfortIndex;
        }
};

Car::Car()
{
    capacity = 10;
    name = new char[capacity];
    hp = 100;
}
Car::Car(const Car& other)
{
    capacity = other.capacity;
    name = new char[capacity];
    hp = other.hp;
    strcpy(name, other.name);
}
Car* Car::clone()
{
    return new Car(*this);
}
Car& Car::operator=(const Car& other)
{
    if(this != &other)
    {
        delete[] name;
        capacity = other.capacity;
        name = new char[capacity];
        hp = other.hp;
        strcpy(name, other.name);
    }
    return *this;
}
Car:: ~Car()
{
    delete[] name;
}
void Car::identify()
{
    std::cout << "Name: " << name << std::endl
              << "HP: "   << hp   << std::endl;
}

void NormalCar::identify()
{
    Car::identify();
    std::cout << "Comfort index: " << comfortIndex << std::endl;
}

void SportsCar::identify()
{
    Car::identify();
    std::cout << "Max speed: " << maxSpeed << std::endl;
}

#endif

