#include <cstring>
#include <iostream>

class StaticString
{
    private:
        char str[256];

    public:
        StaticString();
        StaticString(char*);
        void printString() const;
        void concat(StaticString);
};

StaticString::StaticString()
{
    strcpy(str,"");
}
StaticString::StaticString(char* _str)
{
    if(strlen(_str) > 255)
    {
        StaticString();
    }
    else
    {
        strcpy(str, _str);
    }
}
void StaticString::printString() const
{
    std::cout << str << std::endl;
}
void StaticString::concat(StaticString a)
{
    strcpy(str,strcat(str, a.str));
}
int main()
{
    StaticString a, b("Ivan"), c(" e dobur student");
    b.concat(c);
    b.printString();
    std::cout << std::endl;
    std::cout << "A is: ";
    a.printString();
}
