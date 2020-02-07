#include <iostream>
#include <memory>

int main() {
  // construct a unique pointer
  std::unique_ptr<int> uniquePtr(new int);

  // (1) shared pointer from unique pointer
  std::shared_ptr<int> sharePtr1 = std::move(uniquePtr);

  // (2) shared pointer from weak pointer
  std::weak_ptr<int> weakPtr(sharePtr1);
  std::shared_ptr<int> sharePtr2 = weakPtr.lock();

  // (3) raw pointer from shared or unique pointer
  int *rawPtr = sharePtr2.get();
  delete rawPtr;

  return 0;
}