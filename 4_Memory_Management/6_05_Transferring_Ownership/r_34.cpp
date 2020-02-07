#include <iostream>
#include <memory>

class MyClass {
 private:
  int _member;

 public:
  MyClass(int val) : _member{val} {}

  void printVal() {
    std::cout << ", managed object on heap = " << this
              << " with val = " << _member << std::endl;
  }
};

void f(std::shared_ptr<MyClass> ptr) {
  std::cout << "Shared ptr (ref_cnt = " << ptr.use_count() << ") on stack "
            << &ptr;
  ptr->printVal();
}

int main() {
  std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>(23);
  std::cout << "Shared ptr (ref_cnt = " << sharedPtr.use_count()
            << ") on stack " << &sharedPtr;
  sharedPtr->printVal();

  f(sharedPtr);

  std::cout << "Shared ptr (ref_cnt = " << sharedPtr.use_count()
            << ") on stack " << &sharedPtr;
  sharedPtr->printVal();

  return 0;
}