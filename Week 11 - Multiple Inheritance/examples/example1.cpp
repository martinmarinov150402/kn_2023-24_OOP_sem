class Person
{
    public: 
        char name[31];
        int age;
}
class HasJob
{
    public:
        char company[51];
        char occupation[51]
}
class Worker: public Person, public HasJob
{
    void present()
    {
        std::cout << "Name: "     << name       << std::endl
                  << "Age: "      << age        << std::endl
                  << "Company: "  << company    << std::endl
                  << "Occupation" << occupation << std::endl;
    }
}