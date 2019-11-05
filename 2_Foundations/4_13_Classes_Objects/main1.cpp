#include <iostream>
#include <string>

class Car
{
public:
    // Method to print data
    void PrintCarData()
    {
        std::cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
    }

    // Method to increment the distance travelled
    void IncrementDistance()
    {
        distance++;
    }

    // Class/ Object attributes
    std::string color;
    int distance = 0;
    int number;
};

int main()
{
    // create class instances car_1, car_2, car_3
    Car car_1, car_2, car_3;

    // set each instance's color
    car_1.color = "green";
    car_2.color = "red";
    car_3.color = "blue";

    // Increments car_1's position by 1
    car_1.IncrementDistance();

    // Print out the poisition and color of each car.
    car_1.PrintCarData();
    car_2.PrintCarData();
    car_3.PrintCarData();

    return 0;
}