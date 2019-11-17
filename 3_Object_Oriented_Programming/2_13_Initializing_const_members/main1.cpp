#include <assert.h>
#include <string>

struct Person
{
public:
    // TODO: Add an initialization list
    Person(std::string name) : name(name) {}
    std::string const name;
};

// Test
int main()
{
    Person alice("Alice");
    Person bob("Bob");
    assert(alice.name != bob.name);
}