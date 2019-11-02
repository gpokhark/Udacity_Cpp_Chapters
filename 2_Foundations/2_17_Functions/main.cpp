#include <iostream>
#include <vector>
// using std::cout;
// using std::vector;

// TODO: Add PrintBoard function here.
void PrintBoard(const std::vector<std::vector<int>> board)
{
    std::cout << "\n";
    for (auto v : board)
    {
        for (int i : v)
        {
            std::cout << i;
        }
        std::cout << "\n";
    }
}

int main()
{
    std::vector<std::vector<int>> board{{0, 1, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 1, 0}};
    // TODO: Call PrintBoard function here.
    PrintBoard(board);
    return 0;
}