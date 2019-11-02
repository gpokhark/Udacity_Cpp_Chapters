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

// TODO: Change the return type to use auto or
// explicitly indicate vector<State>
std::vector<State> ParseLine(std::string line)
{
    std::istringstream sline(line);
    int n;
    char c;
    // TODO: Change the variable type for row
    // to be a vector<State>
    std::vector<State> row;
    while (sline >> n >> c && c == ',')
    {
        // TODO: Modify the line below to push_back
        // a State::kEmpty if n is 0, and push_back
        // a State::kObstacle otherwise.
        row.push_back(n == 0 ? State::kEmpty : State::kObstacle);
        // if (n == 0)
        // {
        //     row.push_back(State::kEmpty);
        // }
        // else
        // {
        //     row.push_back(State::kObstacle);
        // }
    }
    return row;
}

// TODO: Modify the return type here as well. Just
// as above, the board will contain State objects
// instead of ints.
std::vector<std::vector<State>> ReadBoardFile(std::string path)
{
    std::vector<std::vector<State>> board{};
    std::ifstream myfile(path);
    // TODO: Modify the board declarationto store
    // State objects instead of ints.
    if (myfile)
    {
        std::string line;
        while (getline(myfile, line))
        {
            // TODO: Modify the row type to use State
            // objects instead of ints.
            std::vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

// TODO: Modify the function signature below to accept
// cells with State type instead of int type.
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

void PrintBoard(const std::vector<std::vector<State>> board)
{
    for (auto v : board)
    {
        for (auto i : v)
        {
            // TODO: Modify the line below to call CellString
            // on each element of the board before streaming to cout.
            std::cout << CellString(i);
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