#include <assert.h>
#include <string>
#include <iostream>

// TODO: Define class Person
// TODO: Define a public constructor with an initialization list
// TODO: Define a public member variable: name

class Person
{
public:
    Person(std::string n);
    std::string name;
};

Person::Person(std::string n) : name(n) {}

// Test
int main()
{
    Person alice("Alice");
    Person bob("Bob");
    assert(alice.name != bob.name);
}