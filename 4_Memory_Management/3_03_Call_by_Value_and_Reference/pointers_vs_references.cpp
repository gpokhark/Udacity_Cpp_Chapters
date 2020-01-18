#include <iostream>

void AddFour(int &val) { val += 4; }

void AddSix(int *val) { *val += 6; }

int main() {
  int val = 0;
  std::cout << "Initial Value" << std::endl;
  std::cout << "val = " << val << std::endl;

  std::cout << "Pass by reference AddFour" << std::endl;
  AddFour(val);
  std::cout << "val = " << val << std::endl;

  std::cout << "Pass by reference AddSix" << std::endl;
  AddSix(&val);
  std::cout << "val = " << val << std::endl;

  return 0;
}