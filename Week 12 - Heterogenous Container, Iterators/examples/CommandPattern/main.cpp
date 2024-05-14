#include <iostream>
#include "HelloWorldCommand.cpp"
#include "PlusCommand.cpp"

int main()
{
    std::string input;
    getline(std::cin, input);
    std::string cmd;
    std::string args;
    bool inCommand = true;
    bool flag = true;
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == ' ')
        {
            inCommand = false;
        }
        if(inCommand)
        {
            cmd.push_back(input[i]);
        }
        else
        {
            if(flag)
            {
                flag = false;
            }
            else
            {
                args.push_back(input[i]);
            }
        }
    }
    Command* command;
    if(cmd == "hello")
    {
        command = new HelloWorldCommand();
    }
    else if(cmd == "plus")
    {
        command = new PlusCommand(args);
    }
    else
    {
        std::cout << cmd << std::endl;
    }
    command -> execute();
};