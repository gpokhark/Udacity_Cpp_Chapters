#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

enum class State
{
    kEmpty,
    kObstacle
};

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

std::vector<std::vector<int>> ReadBoardFile(std::string path)
{
    std::vector<std::vector<int>> board{};
    std::ifstream myfile(path);
    if (myfile)
    {
        std::string line;
        while (getline(myfile, line))
        {
            std::vector<int> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

// TODO: Create the CellString function here,
// using the following return strings:
// "⛰️   "
// "0   "

std::string CellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "⛰️  ";
    default:
        return "0  ";
    }
}

void PrintBoard(const std::vector<std::vector<int>> board)
{
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
    auto board = ReadBoardFile("../files/1.board");
    PrintBoard(board);
    return 0;
}