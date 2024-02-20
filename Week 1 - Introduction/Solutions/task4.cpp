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

struct Hotel
{
    char name[51];
    double avgPrice;
    int rangesCount;
    DateRange ranges[50];

    void init()
    {
        std::cin.getline(name, 50);
        std::cin >> avgPrice;
        std::cin >> rangesCount;
        for(int i = 0; i < rangesCount; i++)
        {
            ranges[i].init();
        }
        std::cin.ignore();
    }

    void out()
    {
        //std::cout <<"Ivan" << std::endl;
        std::cout << "Name: "          << name     << std::endl
                  << "Average Price: " << avgPrice << std::endl
                  << "Free in those ranges: "      << std::endl;
        for(int i = 0; i < rangesCount; i++)
        {
            ranges[i].out();
        }
    }
};

int countHotelsThatCanBeReserved(Hotel arr[], int n, Date date)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < arr[i].rangesCount; j++)
        {
            if(isDateInRange(arr[i].ranges[j], date))
            {
                count++;
                break;
            }
        }
    }
    return count;
}


int main()
{
    Hotel arr[4];
    for(int i = 0; i < 4; i++)
    {
        arr[i].init();
    }
    Date date;
    date.init();
    std::cout << countHotelsThatCanBeReserved(arr, 4, date);
}