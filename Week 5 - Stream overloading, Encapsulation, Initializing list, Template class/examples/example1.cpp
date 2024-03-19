#include <iostream>

class Example
{
    private:
        int a,b;
    
    public:
        Example(int a, int b);

    friend int fun(Example ex);  
    friend class Example2;     
};
int fun(Example ex)
{
    return ex.a + ex.b;
}

class Example2
{
    private:
        int c;

    public:
        int sumWithExample(Example ex) 
        {
            return ex.a + ex.b + c;
        }
        Example2(int c);

};
Example::Example(int a, int b)
{
    this->a = a;
    this->b = b;
}
Example2::Example2(int c)
{
    this->c = c;
}
int main()
{
    Example a(5,6);
    Example2 b(7);
    std::cout << fun(a) << std::endl
              << b.sumWithExample(a) << std::endl;
    

}