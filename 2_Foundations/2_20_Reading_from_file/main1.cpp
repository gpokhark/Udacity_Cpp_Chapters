/*
File Input Streams
Creating an Input Stream Object
In C++, you can use the std::ifstream object to handle input file streams. To do this, you will need to include the header file that provides the file streaming classes: <fstream>.

Once the <fstream> header is included, a new input stream object can be declared and initialized using a file path path:

std::ifstream my_file;
my_file.open(path);
Alternatively, the declaration and initialization can be done in a single line as follows:

std::ifstream my_file(path);
C++ ifstream objects can also be used as a boolean to check if the stream has been created successfully. If the stream were to initialize successfully, then the ifstream object would evaluate to true. If there were to be an error opening the file or some other error creating the stream, then the ifstream object would evaluate to false.

The following cell creates an input stream from the file "files/1.board":
*/
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream my_file;
    my_file.open("../files/1.board");
    if (my_file)
    {
        std::cout << "The file stream has been created!"
                  << "\n";
    }
}