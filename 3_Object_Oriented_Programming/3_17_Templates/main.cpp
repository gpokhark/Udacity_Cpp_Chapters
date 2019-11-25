#include <assert.h>
#include <iostream>

// TODO: Create a generic function Product that multiplies two parameters

template <typename T>
T Product(T a, T b)
{
    return a * b;
}

template <typename T>
T Sum(T a, T b)
{
    return a + b;
}

int main()
{
    assert(Product<int>(10, 2) == 20);
    std::cout << Product<int>(10, 2) << "\n";
    std::cout << Sum<double>(10.0, 2.0) << "\n";
}