/*
The istringstream object can also be used as a boolean to determine if the last extraction operation failed - this happens if there wasn't any more of the string to stream, for example. If the stream still has more characters, you are able to stream again. See the following code for an example of using the istringstream this way:
*/

#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string a("199 2 3");
    std::istringstream myStream(a);
    int n;

    // Testing to see if the stream was successful and printing results.
    // while (myStream)
    // {
    //     myStream >> n;
    //     if (myStream)
    //     {
    //         std::cout << "That stream was successful: " << n << "\n";
    //     }
    //     else
    //     {
    //         std::cout << "That stream was NOT successful"
    //                   << "\n";
    //     }
    // }

    /*
    GP - VIMP *****
    The extraction operator >> writes the stream to the variable on the right of the operator and returns the istringstream object, so the entire expression my_stream >> n is an istringstream object and can be used as a boolean! Because of this, a common way to use istringstream is to use the entire extraction expression in a while loop as follows:
    */

    while (myStream >> n)
    {
        std::cout << "That stream was successful: " << n << "\n";
    }

    std::cout << "The stram has failed."
              << "\n";

    return 0;
}