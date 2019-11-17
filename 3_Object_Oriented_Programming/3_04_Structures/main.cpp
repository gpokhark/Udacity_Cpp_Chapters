// Include iostream for output
#include <cassert>
#include <iostream>

// Define a simple structure
struct Date {
  int day;
  int month;
  int year;
};

// Define a main function to instantiate and test 
int main()
{
    Date date;
    
    // TODO: Initialize date to August 29, 1981
    date.day = 29;
    date.month = 8;
    date.year = 1981;   
    
    // TEST
    assert(date.day == 29);
    assert(date.month == 8);
    assert(date.year == 1981);

    // Print the data in the structure
    std::cout << date.day << "/" << date.month << "/" << date.year << "\n";
}