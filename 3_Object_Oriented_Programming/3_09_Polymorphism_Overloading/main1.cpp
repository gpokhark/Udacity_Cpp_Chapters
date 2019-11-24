#include <iostream>

class Human
{
};
class Dog
{
};
class Cat
{
};

// TODO: Write hello() function
void hello() { std::cout << "Hello, World!\n"; }

// TODO: Overload hello() three times
void hello(Human human) { std::cout << "Hello, Human!\n"; }
void hello(Dog dog) { std::cout << "Hello, Dog!\n"; }
void hello(Cat cat) { std::cout << "Hello, Cat!\n"; }

// TODO: Call hello() from main()
int main()
{
    hello();
    hello(Human());
    hello(Dog());
    hello(Cat());
}