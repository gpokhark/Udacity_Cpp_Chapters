#include <stdlib.h>
#include <iostream>

class MyMovableClass {
 private:
  int _size;
  int* _data;

 public:
  // constructor
  MyMovableClass(size_t size) {
    _size = size;
    _data = new int[_size];
    std::cout << "CREATING instance of MyMovableClass at " << this
              << " allocated with size = " << _size * sizeof(int)
              << " bytes. \n";
  }

  ~MyMovableClass() {
    std::cout << "DELETING instance of MyMovableClass ar " << this << std::endl;
    delete[] _data;
  }

  // copy constructor
  MyMovableClass(const MyMovableClass& source) {
    _size = source._size;
    _data = new int[_size];
    *_data = *source._data;
    std::cout << "COPYING content of instance " << &source << " to instance "
              << this << std::endl;
  }

  // copy assignment constructor
  MyMovableClass& operator=(const MyMovableClass& source) {
    std::cout << "ASSIGNING content of instance " << &source << " to instance "
              << this << std::endl;

    // standard boiler plate if statement to protect against self assignment
    if (this == &source) return *this;

    delete[] _data;
    _data = new int[source._size];
    *_data = *source._data;
    _size = source._size;
    return *this;
  }
};

int main() {
  MyMovableClass obj1(10);    // regular constructor
  MyMovableClass obj2(obj1);  // copy constructor
  obj2 = obj1;                // copy assignment constructor

  return 0;
}