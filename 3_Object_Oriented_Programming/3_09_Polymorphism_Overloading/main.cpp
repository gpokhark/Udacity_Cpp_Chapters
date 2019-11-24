#include <iostream>
#include <cassert>

// TODO: Write hello() function
void Hello()
{
    std::cout << "Hello \n";
}

// TODO: Overload hello() three times
class Human
{
public:
    void Hello(Human human) { std::cout << "Hello Human! \n"; }
};
// TODO: Call hello() from main()
int main()
{
    Human human;
    human.Hello(human);
    Hello();
    return 0;
}