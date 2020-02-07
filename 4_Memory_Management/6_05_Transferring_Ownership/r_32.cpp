#include <iostream>
#include <memory>

class MyClass {
 private:
  int _member;

 public:
  MyClass(int val) : _member{val} {}

  void printVal() {
    std::cout << ", managed object on heap " << this
              << " with val = " << _member << std::endl;
  }
};

void f(std::unique_ptr<MyClass> ptr) {
  std::cout << "Unique pointer on stack " << &ptr;
  ptr->printVal();
}

int main() {
  std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>(23);
  std::cout << "Unique pointer on stack in main " << &uniquePtr;
  uniquePtr->printVal();

  f(std::move(uniquePtr));

  if (uniquePtr) {
    uniquePtr->printVal();
  }

  return 0;
}