#include <iostream>

class SharedCopy {
 private:
  int *_myInt;
  static int _cnt;

 public:
  SharedCopy(int val);
  ~SharedCopy();
  SharedCopy(SharedCopy &source);
};

int SharedCopy::_cnt = 0;

SharedCopy::SharedCopy(int val) {
  _myInt = (int *)malloc(sizeof(int));
  *_myInt = val;
  ++_cnt;
  std::cout << "resource allocated at address " << _myInt << std::endl;
}

SharedCopy::~SharedCopy() {
  --_cnt;
  if (_cnt == 0) {
    free(_myInt);
    std::cout << "resource freed at address " << _myInt << std::endl;
  } else {
    std::cout << "instance at address " << this
              << " goes out of scope with _cnt = " << _cnt << std::endl;
  }
}

SharedCopy::SharedCopy(SharedCopy &source) {
  _myInt = source._myInt;
  ++_cnt;
  std::cout << _cnt << " instances with handles to address " << _myInt
            << " with _myInt = " << *_myInt << std::endl;
}

int main() {
  SharedCopy source(42);
  SharedCopy destination1(source);
  SharedCopy destination2(source);
  SharedCopy destination3(source);

  return 0;
}