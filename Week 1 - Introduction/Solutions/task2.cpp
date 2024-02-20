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

bool isBefore(Date date1, Date date2)
{
    if(date1.year < date2.year)
    {
        return true;
    }
    else if(date1.year == date2.year)
    {
        if(date1.month < date2.month)
        {
            return true;
        }
        else if(date1.month == date2.month)
        {
            if(date1.day < date2.day)
            {
                return true;
            }
            else if(date1.day == date2.day)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
        else 
        {
            return false;
        }   
    }
    else 
    {
        return false;
    }
}

bool isDateInRange(DateRange range, Date date)
{
    return isBefore(range.start, date) && isBefore(date,range.end);
}

int main()
{
    DateRange range;
    Date date;
    range.init();
    date.init();
    std::cout << std::boolalpha << isDateInRange(range,date) << std::endl;    
}