#include <iostream>

class Animal
{
    public: 
        int age;
        Animal()
        {
            std::cout << "Animal constructor" << std::endl;
        }
        void makeSound()
        {
            std::cout << "Animal makes sound";
        }
};
class Mammal: public Animal
{
    public:
        Mammal()
        {
            std::cout << "Mammal constructor" << std::endl;
        }
        void breathe()
        {
            std::cout << "Mammal breathes";
        }
};
class AnimalWithWings: public Animal
{
    public:
        AnimalWithWings()
        {
            std::cout << "Animal with wings constructor" << std::endl;
        }
        void fly()
        {
            std::cout << "Animal flies" << std::endl;
        }    

};
class Bat: public Mammal, public AnimalWithWings
{
    public:
        Bat()
        {
            std::cout << "Bat constructor" << std::endl;
        }
};
int main()
{
    Bat bat;
    bat.Mammal::age = 10;
    bat.AnimalWithWings::age = 20;
    std::cout << bat.Mammal::age << " " << bat.AnimalWithWings::age << std::endl;
}