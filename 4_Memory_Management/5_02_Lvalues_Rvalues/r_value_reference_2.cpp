#include <iostream>

int main() {
  int i = 1;
  int j = 2;
  int k = i + j;
  int &&l = i + j;

  std::cout << "k = " << k << ", l = " << l << std::endl;

  return 0;
}