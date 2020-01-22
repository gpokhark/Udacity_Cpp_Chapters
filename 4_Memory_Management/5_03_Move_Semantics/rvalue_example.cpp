#include <iostream>

void myFunction(int &&val) { std::cout << "val = " << val << std::endl; }

int main() {
  myFunction(42);

  int i = 23;
  myFunction(std::move(i));

  return 0;
}