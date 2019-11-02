/*
Passing References
But what if we wanted to change the value of a itself? For example, it might be that the variable you are passing into a function maintains some state in the program, and you want to write the function to update that state.

It turns out, it is possible to modify a from within the function. To do this, you must pass a reference to the variable a, instead of the value of a. In C++, a reference is just an alternative name for the same variable.

To pass by reference, you simply need to add an ampersand & before the variable in the function declaration. Try the code below to see how this works:
*/

#include <iostream>

int MultiplyByTwo(int &i)
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
    std::cout << "The int a now = " << a << "\n";
    return 0;
}

/*
In the code above, a is passed by reference to the function MultiplyByTwo since the argument to MultiplyByTwo is a reference: &i. This means that i is becomes another name for whatever variable that is passed into the function. When the function changes the value of i, then the value of a is changed as well.
*/