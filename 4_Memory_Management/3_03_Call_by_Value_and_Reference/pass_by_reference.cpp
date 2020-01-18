#include <iostream>

void AddFour(int &val) { val += 4; }

int main() {
  int val = 0;
  AddFour(val);
  val += 2;

  std::cout << "val = " << val << std::endl;

  return 0;
}