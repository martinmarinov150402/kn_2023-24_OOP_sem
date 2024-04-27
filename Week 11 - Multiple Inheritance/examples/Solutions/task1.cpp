#include <iostream>

class Employee
{
    private:
        char name[51];
        int age;
        int number;
    
    public:
        virtual void present()
        {
            std::cout << "Name: "   << name   << std::endl
                      << "Age: "    << age    << std::endl
                      << "Number: " << number << std::endl;
        }
};
class Boss: virtual public Employee
{
    public:
        void getInfo(Employee* emp)
        {
            emp->present();
        }
        void present() override
        {
            std::cout << "Boss" << std::endl;
            Employee::present();
        }

};
class StorageEmployee: virtual public Employee
{
    private:
        char storage[51];
    
    public:
        void present() override
        {
            Employee::present();
            std::cout << "Storage: " << storage << std::endl;
        }    
};

class StroageBoss: public StorageEmployee, public Boss
{
    void present() override
    {
        std::cout << "Storage boss" << std::endl;
        StorageEmployee::present();
    }
};

int main()
{
    Employee* stBoss = new StroageBoss(), *asd = new StorageEmployee(), *empl = new Employee(), *boss = new Boss();
    stBoss->present();
    asd->present();
    empl->present();
    boss->present();

    Boss* boss2 = new Boss();

    std::cout << "Boss get info" << std::endl;
    boss2->getInfo(empl);
}