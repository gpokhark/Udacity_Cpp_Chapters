#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> mySharedPtr(new int);
  std::cout << "Shared pointer count = " << mySharedPtr.use_count()
            << std::endl;

  std::weak_ptr<int> myWeakPtr1(mySharedPtr);
  std::weak_ptr<int> myWeakPtr2(myWeakPtr1);

  std::cout << "Shared pointer count = " << mySharedPtr.use_count()
            << std::endl;

  //   std::weak_ptr<int> myWeakPtr3(new int);  // COMPILE ERROR

  return 0;
}