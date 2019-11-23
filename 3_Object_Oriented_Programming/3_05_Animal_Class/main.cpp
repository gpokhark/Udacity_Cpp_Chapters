// Define base class Animal

// Declare derived class Snake

// Declare derived class Cat

// Test in main()

#include <iostream>
#include <cassert>
#include <string>
class Animal
{
public:
    std::string color, name;
    int age;
};

class Snake : public Animal
{
public:
    float length;

    void Sound() { std::cout << "Snake hiss. \n"; }
};

class Cat : public Animal
{
public:
    float height;

    void Sound() { std::cout << "Cat purrs. \n"; }
};

int main()
{
    Snake python;
    Cat italina;

    python.age = 2;
    python.name = "sp";
    python.Sound();

    italina.age = 12;
    italina.name = "sg";
    italina.Sound();

    return 0;
}