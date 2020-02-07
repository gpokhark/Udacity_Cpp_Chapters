#include <iostream>
#include <memory>

class MyClass {
 public:
  std::shared_ptr<MyClass> _member;

  ~MyClass() { std::cout << "Destructor of MyClass called" << std::endl; }
};

int main() {
  std::shared_ptr<MyClass> myClass1(new MyClass);
  std::shared_ptr<MyClass> myClass2(new MyClass);

  // following two lines causes memory leaks due to circular reference
  // the destructor is never called
  //   myClass1->_member = myClass2;
  //   myClass2->_member = myClass1;

  // to check for memory leaks use the following command 
  // valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=/home/workspace/valgrind-out.txt /home/workspace/a.out

  return 0;
}