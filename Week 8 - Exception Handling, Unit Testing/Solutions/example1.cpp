#include <iostream>
#include <exception>

void sthThatThrows()
{
   throw std::exception(); 
}
int main()
{
    /*try
    {*/
        sthThatThrows();
    /*}
    catch(std::exception& e)
    {
        std::cout << "Catch block" << std::endl;
    }*/
    std::cout << "Normal flow" << std::endl;
}