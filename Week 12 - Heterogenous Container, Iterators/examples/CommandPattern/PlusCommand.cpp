#include "Command.cpp"
#include <string>

class PlusCommand : public Command
{
    private:
        int a,b;
        bool inA;
    public:
        PlusCommand(std::string args)
        {
            inA = true;
            std::string buff = "";
            std::cout << args << std::endl;
            for(int i = 0; i < args.size(); i++)
            {
                if(args[i] != ' ')
                {
                    buff.push_back(args[i]);
                }
                else
                {
                    if(inA)
                    {
                        a = stoi(buff);
                        inA = false;
                        buff = "";
                    }
                    else
                    {
                        b = stoi(buff);
                    }
                }
            }
            b = stoi(buff);
        }
        void execute() override
        {
            std::cout << a + b << std::endl;
        }
};