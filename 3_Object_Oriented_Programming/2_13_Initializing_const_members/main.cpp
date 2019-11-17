#include <cassert>
#include <iostream>

/*
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

// Constructor with Initializer list
// Never initialize the member with invariants in the initializer list
Date::Date(int day, int month, int y) : year(y)
{
    Day(day);
    Month(month);
}
*/

class Birthday
{
public:
    // constructor declared here
    Birthday(int day, int month, int year);
    // funciton declared here
    int Day() { return day; }
    int Month() { return month; }
    int Year() { return year; }

private:
    int day{1};
    int month{1};
    int year{0};
};

// Constructor with Initializer list
// Never initialize the member with invariants in the initializer list
Birthday::Birthday(int d, int m, int y) : day(d), month(m), year(y) {}

// Test in main
int main()
{
    Birthday date(29, 8, 1981);
    // date.Day(29);
    // date.Month(8);
    // date.Year(1981);
    assert(date.Day() == 29);
    assert(date.Month() == 8);
    assert(date.Year() == 1981);
    std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}