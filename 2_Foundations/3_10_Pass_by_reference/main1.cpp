/*
Passing Values
In the following example, the value of int i is passed to the function MultiplyByTwo. Look carefully at the code and try to guess what the output will be before you execute it. When you are finished executing, click the button for an explanation.
*/

#include <iostream>

int MultiplyByTwo(int i)
{
    i = 2 * i;
    return i;
}

int main()
{
    int a = 5;
    std::cout << "The int a = " << a << "\n";
    int b = MultiplyByTwo(a);
    std::cout << "The int b = " << b << "\n";
    std::cout << "The int a still = " << a << "\n";
    return 0;
}