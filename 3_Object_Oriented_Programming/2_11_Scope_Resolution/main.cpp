#include <cassert>
#include <iostream>

class Date
{
public:
    // constructor declared here
    Date(int day, int month, int year);
    // funciton declared here
    int Day() { return day; }
    void Day(int day);
    int Month() { return month; }
    void Month(int month);
    int Year() { return year; }
    void Year(int year);

private:
    int day{1};
    int month{1};
    int year{0};
};

// compare this with the previous code in 2_10 Constructors
// when function denined outside of the class we use  ClassName::FunctionName (:: -> scope resolution) operator

// Constructor
Date::Date(int day, int month, int year)
{
    Day(day);
    Month(month);
    Year(year);
}

// TODO: Define Date::Day(int day)
void Date::Day(int day)
{
    if (day >= 1 && day <= 31)
        Date::day = day;
}

// TODO: Define Date::Month(int month)
void Date::Month(int month)
{
    if (month >= 1 && month <= 12)
        Date::month = month;
}

// TODO: Define Date::Year(int year)
void Date::Year(int year) { Date::year = year; }

// Test in main
int main()
{
    Date date(29, 8, 1981);
    // date.Day(29);
    // date.Month(8);
    // date.Year(1981);
    assert(date.Day() == 29);
    assert(date.Month() == 8);
    assert(date.Year() == 1981);
    std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}