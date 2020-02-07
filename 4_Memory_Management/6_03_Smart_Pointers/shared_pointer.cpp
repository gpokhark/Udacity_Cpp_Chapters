#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> shared1(new int);
  std::cout << "Shared pointer count = " << shared1.use_count() << std::endl;

  {
    std::shared_ptr<int> shared2 = shared1;
    std::cout << "Shared pointer count = " << shared1.use_count() << std::endl;
  }

  std::cout << "Shared pointer count = " << shared1.use_count() << std::endl;

  return 0;
}