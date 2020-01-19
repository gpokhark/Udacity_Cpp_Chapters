#include <stdlib.h>
#include <iostream>

class MyClass {
  int _number;

 public:
  MyClass() { std::cout << "Constructor is called. \n"; }

  ~MyClass() { std::cout << "Destructor is called. \n"; }

  void* operator new(size_t size) {
    std::cout << "new: Allocating " << size << " bytes of memory. \n";
    void* p = malloc(size);  // you can use new operator here
    return p;
  }

  void operator delete(void* p) {
    std::cout << "delete: Memory is freed again. \n";
    free(p);
  }
};

int main() {
  MyClass* p = new MyClass();
  delete p;
  return 0;
}