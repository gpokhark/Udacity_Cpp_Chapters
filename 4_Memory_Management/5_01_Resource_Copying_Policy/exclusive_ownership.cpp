#include <iostream>

class ExclusiveCopy {
 private:
  int *_myInt;

 public:
  ExclusiveCopy() {
    _myInt = (int *)malloc(sizeof(int));
    std::cout << "resource allocated" << std::endl;
  }
  ~ExclusiveCopy() {
    if (_myInt != nullptr) {
      free(_myInt);
      std::cout << "resource freed" << std::endl;
    }
  }
  ExclusiveCopy(ExclusiveCopy &source) {
    _myInt = source._myInt;
    source._myInt = nullptr;
  }
  ExclusiveCopy &operator=(ExclusiveCopy &source) {
    _myInt = source._myInt;
    source._myInt = nullptr;
    return *this;
  }
};

int main() {
  ExclusiveCopy source;
  ExclusiveCopy destination(source);

  return 0;
}