#include <iostream>

class A
{
    private:
        int a;
    
    public:
        A()
        {
            std::cout << "Creating A" << std::endl;
        }
        virtual A* clone()
        {
            return new A(*this);
        }
        virtual ~A()
        {
            std::cout << "Destroying A" << std::endl;
        }
};
class B: public A
{
    private:
        int b;
    
    public:
        B()
        {
            std::cout << "Creating B" << std::endl;
        }
        A* clone()
        {
            A* result = new B(*this);
            return result;
        }

        ~B()
        {
            std::cout << "Destroying B" << std::endl;
        }
};

int main()
{
    A *a1 = new A();
    A *a2 = new B();
    A *a3 = a2->clone();
    delete a1;
    delete a2;
    delete a3;
}