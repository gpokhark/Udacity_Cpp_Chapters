#include <iostream>

void AddTwo(int val) { val += 2; }

int main() {
  int val = 0;
  AddTwo(val);
  val += 2;

  std::cout << "val = " << val << std::endl;

  return 0;
}