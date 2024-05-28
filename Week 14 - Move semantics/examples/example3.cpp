#include<iostream>

class Person
{
    private:
        char* name;
        int age;
    public:
        Person(std::string name, int age) : name(name), age(age) {};
};

Person::Person(Person&& rhs)
{
	age = rhs.age;
	name = rhs.name;
	rhs.name = nullptr;
}

Person& Person::operator=(Person&& rhs)
{
	if (this != &rhs)
	{
		delete[] name;
		age = rhs.age;
		name = rhs.name;
		rhs.name = nullptr;
	}
	return *this;
}

Person createPerson(const char* name, int age)
{
	Person p(name, age);
	return p;
}

int main()
{
	Person p2("Petur", 18);
	p2 = createPerson("Ivan", 23);
}