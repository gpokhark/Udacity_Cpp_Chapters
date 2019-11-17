#include <cassert>

class Date
{
public:
    Date(int day, int month, int year);
    int Day() const { return day_; }
    void Day(int day);
    int Month() const { return month_; }
    void Month(int month);
    int Year() const { return year_; }
    void Year(int year);

private:
    int day_{1};
    int month_{1};
    int year_{0};
    int DaysInMonth(int m, int y) const; // const means it is not going to change the state of the object of the class
    bool LeapYear(int y) const;
};

bool Date::LeapYear(int y) const
{
    if (y % 4 != 0)
        return false;
    else if (y % 100 != 0)
        return true;
    else if (y % 400 != 0)
        return false;
    else
        return true;
}

int Date::DaysInMonth(int m, int y) const
{
    if (m == 2)
        return LeapYear(y) ? 29 : 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    else
        return 31;
}

Date::Date(int day, int month, int year)
{
    Year(year);
    Month(month);
    Day(day);
}

void Date::Day(int day)
{
    if (day >= 1 && day <= DaysInMonth(Month(), Year()))
        day_ = day;
}

void Date::Month(int month)
{
    if (month >= 1 && month <= 12)
        month_ = month;
}

void Date::Year(int year) { year_ = year; }

// Test
int main()
{
    Date date(29, 8, 1981);
    assert(date.Day() == 29);
    assert(date.Month() == 8);
    assert(date.Year() == 1981);
}