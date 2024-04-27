#include <iostream>

class Executable
{
    public:
        virtual void execute() = 0;   
};

class SayHelloCommand : public Executable
{
    public: 
        void execute() override
        {
            std::cout << "Hello" << std::endl;
        }
};
int main()
{
    SayHelloCommand cmd1;
    cmd1.execute();
}