#include <cassert>
#include <iostream>

// TODO: Define public accessors and mutators for the private member variables
struct Date
{
public:
  // Accessors //Getters
  int Day(){return day;}
  int Month(){return month;}
  int Year(){return year;}
  // Mutators // Setters
  void Day(int d) {day  = d;}
  void Month(int m) {month = m;}
  void Year(int y) {year = y;}


private:
  int day{1};
  int month{1};
  int year{0};
};

int main()
{
  Date date;
  date.Day(29);
  date.Month(8);
  date.Year(1981);
  assert(date.Day() == 29);
  assert(date.Month() == 8);
  assert(date.Year() == 1981);
  std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}