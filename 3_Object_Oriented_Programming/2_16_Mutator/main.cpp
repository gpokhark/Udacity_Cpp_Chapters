#include <string>
#include <cstring>
#include <iostream>

class Car
{
    // TODO: Declare private attributes
private:
    int horse_power;
    int weight;
    char *brand;

    // TODO: Declare getter and setter for brand
public:
    void SetBrand(std::string brand_name);
    std::string GetBrand() const;
};

// Define setters
void Car::SetBrand(std::string brand_name)
{
    // Initialization of char array
    Car::brand = new char[brand_name.length() + 1];

    // Copying every character from string to char array
    strcpy(Car::brand, brand_name.c_str());
}

// Define getters
std::string Car::GetBrand() const
{
    std::string result = "Brand name: ";
    // specifying string for output of brand name
    result += Car::brand;
    return result;
};

// Test in main()
int main()
{
    Car car;
    car.SetBrand("Peugeot");
    std::cout << car.GetBrand() << "\n";
}