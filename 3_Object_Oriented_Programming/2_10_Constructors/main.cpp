#include <cassert>

class Date
{
public:
    // This is a constructor.
    Date(int d, int m, int y)
    {
        Day(d);
        Month(m);
        Year(y);
    }
    int Day() { return day; }
    void Day(int d)
    {
        if (d >= 1 && d <= 31)
            day = d;
    }
    int Month() { return month; }
    void Month(int m)
    {
        if (m >= 1 && m <= 12)
            month = m;
    }
    int Year() { return year; }
    void Year(int y) { year = y; }

private:
    int day{1};
    int month{1};
    int year{0};
};

// Test in main
int main()
{
    Date date(8, 12, 1981);
    assert(date.Day() == 8);
    assert(date.Month() == 12);
    assert(date.Year() == 1981);
}