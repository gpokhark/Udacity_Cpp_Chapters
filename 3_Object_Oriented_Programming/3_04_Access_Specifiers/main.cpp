// This example demonstrates the privacy levels
// between parent and child classes
#include <iostream>
#include <string>
using std::string;

class Vehicle
{
public:
    int wheels = 0;
    string color = "blue";

    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
    }
};

class Car : public Vehicle
{
public:
    bool sunroof = false;
};

class Bicycle : protected Vehicle
{
public:
    bool kickstand = true;
};

class Scooter : private Vehicle
{
public:
    bool electric = false;
    void Wheels(int w)
    {
        wheels = w;
    }
};

class ElectricScooter : public Scooter
{
public:
    float charging = 90.0;

    // vehicle not accessible here hence wont work
    // void Wheels(int w)
    // {
    //     wheels = w;
    // }
};

int main()
{
    Car car;
    car.wheels = 4;

    // due to protected and private inheritence this wont work
    //Bicycle bicycle;
    //bicycle.wheels = 2;
    Scooter scooter;
    scooter.Wheels(1);

    ElectricScooter elez;
    elez.electric = true;
    // elez.Wheels(2);
};