#include <iostream>

class MyInt {
  int *_p;  // pointer to heap data

 public:
  MyInt(int *p = NULL) { _p = p; }

  ~MyInt() {
    std::cout << "resource " << *_p << " deallocated" << std::endl;
    delete _p;
  }

  // overloading dereferencing operator
  int &operator*() { return *_p; }
};

int main() {
  double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};

  for (size_t i = 0; i < 5; i++) {
    // allocate the resource on the stack
    MyInt en(new int(i));

    // use the resource
    std::cout << *en << "/" << den[i] << " = " << *en / den[i] << std::endl;
  }

  return 0;
}