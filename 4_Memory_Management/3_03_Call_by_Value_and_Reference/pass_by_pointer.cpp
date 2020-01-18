#include <iostream>

void AddThree(int *val) { *val += 3; }

int main() {
  int val = 0;
  AddThree(&val);
  val += 2;

  std::cout << "val = " << val << std::endl;

  return 0;
}