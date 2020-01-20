#include <iostream>

class MyClass {
 private:
  int *_myInt;

 public:
  MyClass() { _myInt = (int *)malloc(sizeof(int)); };
  ~MyClass() { free(_myInt); };
  void printOwnAddress() {
    std::cout << "Own address on the stack is " << this << std::endl;
  }
  void printMemberAddress() {
    std::cout << "Managing memory block on the heap at " << _myInt << std::endl;
  }
};

int main() {
  // instantiate object 1
  MyClass myClass1;
  myClass1.printOwnAddress();
  myClass1.printMemberAddress();
  //   myClass1.~MyClass(); // Added by me

  // copy object 1 into object 2
  MyClass myClass2(myClass1);  // copy constructor
  myClass2.printOwnAddress();
  myClass2.printMemberAddress();
  //   myClass2.~MyClass(); // Added by me

  return 0;
}