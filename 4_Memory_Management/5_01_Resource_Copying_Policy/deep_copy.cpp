#include <iostream>

class DeepCopy {
 private:
  int *_myInt;

 public:
  DeepCopy(int val) {
    _myInt = (int *)malloc(sizeof(int));
    *_myInt = val;
    std::cout << "resource allocated at address " << _myInt << std::endl;
  }
  ~DeepCopy() {
    free(_myInt);
    std::cout << "resource freed at address " << _myInt << std::endl;
  }
  DeepCopy(DeepCopy &source) {
    _myInt = (int *)malloc(sizeof(int));
    *_myInt = *source._myInt;
    std::cout << "resource allocated at address " << _myInt
              << " with _myInt = " << *_myInt << std::endl;
  }
  DeepCopy &operator=(DeepCopy &source) {
    _myInt = (int *)malloc(sizeof(int));
    std::cout << "resource allocated at address " << _myInt
              << " with _myInt=" << *_myInt << std::endl;
    *_myInt = *source._myInt;
    return *this;
  }
};

int main() {
  DeepCopy source(42);
  DeepCopy dest1(source);
  DeepCopy dest2 = dest1;

  return 0;
}
