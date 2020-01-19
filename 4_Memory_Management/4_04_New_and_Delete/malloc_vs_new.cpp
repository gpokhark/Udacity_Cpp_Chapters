#include <stdlib.h>
#include <iostream>

class MyClass {
 private:
  int *_number;

 public:
  MyClass() {
    std::cout << "Allocate memory\n";
    _number = (int *)malloc(sizeof(int));
  }
  ~MyClass() {
    std::cout << "Delete memory\n";
    free(_number);
  }
  void setNumber(int number) {
    *_number = number;
    std::cout << "Number: " << _number << "\n";
  }
};

int main() {
  //   // allocate memory using malloc
  //   // comment these lines out to run the example below
  //   MyClass *myClass = (MyClass *)malloc(sizeof(MyClass));
  //   myClass->setNumber(42);  // EXC_BAD_ACCESS
  //   free(myClass);

  //   // allocate memory using new
  //   MyClass *myClass = new MyClass();
  //   myClass->setNumber(42);  // works as expected
  //   delete myClass;

  // allocate memory using placement new
  void *memory = malloc(sizeof(MyClass));
  MyClass *myClass = new (memory) MyClass();
  myClass->setNumber(42);  // works as expected
  // call the desctructor on the object explicitly
  myClass->~MyClass();  // object->~MyClass();
  // free the memory explicitly
  free(memory);

  return 0;
}