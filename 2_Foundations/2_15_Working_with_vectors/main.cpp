#include <iostream>
#include <vector>
// using std::vector;
// using std::cout;

int main()
{
    std::vector<int> a = {0, 1, 2, 3, 4};
    // Add some code here to access and print elements of a.
    std::cout << "a = \n";
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n\n";

    std::vector<std::vector<int>> b = {{1, 1, 2, 3},
                                       {2, 1, 2, 3},
                                       {3, 1, 2, 3}};

    std::cout << "b = \n";
    for (size_t i = 0; i < b.size(); i++)
    {
        for (size_t j = 0; j < b[0].size(); j++)
        {
            std::cout << b[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";

    // Range based for loop
    std::cout << "RANGE BASED FOR LOOP \n";
    std::cout << "b = \n";
    for (auto v : b)
    {
        for (int i : v)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }

    return 0;
}