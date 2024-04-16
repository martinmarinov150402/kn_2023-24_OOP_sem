#include <iostream>

class Animal
{
    private: 
        int lifespan;
    
    public:
        void sound()
        {
            std::cout << "Animal sound";
        }
        int getLifespan() {return lifespan;};
        Animal(int lifespan): lifespan(lifespan) {}
};

class Cat: public Animal
{
    public:
    Cat() : Animal(9)
    {
        
    }
    void sound()
    {
        std::cout << "Meow" << std::endl;
    }
};

class Dog: public Animal
{
    private: 
        int playTime;
    public:
        Dog() : Animal(12)
        {
            playTime = 8;
        }
        void sound()
        {
            std::cout << "Bark" << std::endl;
        }
        int getPlayTime() const {return playTime;};
};
int main()
{
    Dog a;
    Cat b;
    std::cout << a.getLifespan() << " " << b.getLifespan() << std::endl;
    a.sound();
    b.sound();
    std::cout << a.getPlayTime() << std::endl;
}