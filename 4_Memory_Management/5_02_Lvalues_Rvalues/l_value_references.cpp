#include <iostream>

int main() {
  int i = 1;

  // reference j which can be used as an alias for the existing object.
  int &j = i;
  ++i;
  ++j;

  std::cout << "i = " << i << ", j = " << j << std::endl;
  std::cout << "Addr of i = " << &i << ",Addr of j = " << &j << std::endl;
  return 0;
}