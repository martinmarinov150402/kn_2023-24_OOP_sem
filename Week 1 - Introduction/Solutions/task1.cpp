#include <iostream>

struct Date
{
    short day, month, year;
    void init()
    {
        std::cout << "Enter the day: " << std::endl;
        std::cin >> day;
        std::cout << "Enter the month: " << std::endl;
        std::cin >> month;
        std::cout << "Enter the year: " << std::endl;
        std::cin >> year;
    }
    void out()
    {
        std::cout << day << "." << month << "." << year << std::endl;
    }
};

struct DateRange
{
    Date start, end;
    void init()
    {
        start.init();
        end.init();
    }
    void out()
    {
        std::cout << "Start date: ";
        start.out();
        std::cout << "End date: ";
        end.out();
    }
};

int main()
{
    Date a;
    a.init();
    a.out();
    DateRange range;
    range.init();
    range.out();
}