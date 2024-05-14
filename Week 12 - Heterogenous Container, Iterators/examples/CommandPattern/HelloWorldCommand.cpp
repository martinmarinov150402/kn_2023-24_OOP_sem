#include "Command.cpp"

class HelloWorldCommand : public Command
{
    public:
        void execute() override
        {
            std::cout << "Hello world!" << std::endl;
        }
};