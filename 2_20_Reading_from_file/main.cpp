#include <iostream>
#include <string>
#include <vector>
#include <fstream>
// using std::cout;
// using std::string;
// using std::vector;

// TODO: Add the ReadBoardFile function here.
void ReadBoardFile(std::string path)
{
    /*std::ifstream myFile;
    myFile.open(path);*/
    // or
    std::ifstream myFile(path);
    if (myFile)
    {
        std::string line;
        while (getline(myFile, line))
        {
            std::cout << line << "\n";
        }
    }
}

// PrintBoard not used in this exercise
void PrintBoard(const std::vector<std::vector<int>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            std::cout << board[i][j];
        }
        std::cout << "\n";
    }
}

int main()
{
    // TODO: Call the ReadBoardFile function here.
    std::string path = "../files/1.board";
    ReadBoardFile(path);
    // Leave the following line commented out.
    //PrintBoard(board);

    return 0;
}