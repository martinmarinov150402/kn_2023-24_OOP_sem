#include <iostream>

class Car
{
    public:
        virtual void drive()
        {
            std::cout << "You are driving a car!" << std::endl;
        }
};
class Audi: public Car
{
    public:
        void drive() override
        {
            std::cout << "You are not driving, because your car is in the service again!" << std::endl;
        }
};
class Mercedes: public Car
{
    public:
        void drive() override
        {
            std::cout << "You are driving Mercedes" << std::endl;
        }
};
int main()
{
    Audi audi;
    Car a = audi;
    a.drive();

    Car *ptr1 = new Audi();
    Car *ptr2 = new Mercedes();

    ptr1->drive();
    ptr2->drive();
}