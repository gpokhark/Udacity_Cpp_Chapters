#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> ParseLine(std::string line)
{
    std::istringstream sline(line);
    int n;
    char c;
    std::vector<int> row;
    while (sline >> n >> c)
    {
        row.push_back(n);
    }
    return row;
}

void ReadBoardFile(std::string path)
{
    std::ifstream myfile(path);
    if (myfile)
    {
        std::string line;
        while (getline(myfile, line))
        {
            std::cout << line << "\n";
        }
    }
}

void PrintBoard(const std::vector<std::vector<int>> board)
{
    for (auto v : board)
    {
        for (int i : v)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
}

#include "test.cpp"

int main()
{
    ReadBoardFile("../files/1.board");
    TestParseLine(); // for testing.
    std::cout << "\n Printing from int main() \n";
    return 0;
}