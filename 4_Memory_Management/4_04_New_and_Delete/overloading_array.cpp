#include <stdlib.h>
#include <iostream>

class MyClass {
  int _mymember;

 public:
  MyClass() { std::cout << "Constructor is called\n"; }

  ~MyClass() { std::cout << "Destructor is called\n"; }

  void *operator new[](size_t size) {
    std::cout << "new: Allocating " << size << " bytes of memory" << std::endl;
    void *p = malloc(size);

    return p;
  }

  void operator delete[](void *p) {
    std::cout << "delete: Memory is freed again " << std::endl;
    free(p);
  }
};

int main() {
  MyClass *p = new MyClass[3]();
  delete[] p;
}