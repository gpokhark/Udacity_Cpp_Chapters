int main()
{
    // Removing the const fixes the error
    const int i = 2; // "I promise not to change this."
    i++;             // "I just broke my promise."
}