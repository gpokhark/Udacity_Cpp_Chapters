#include <iostream>

void myFunction(int &val) { std::cout << "val = " << val << std::endl; }

int main() {
  int j = 42;
  myFunction(j);

  myFunction(42);

  int k = 23;
  myFunction(j + k);

  return 0;
}