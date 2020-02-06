#include <memory>

void RawPointer() {
  int *raw = new int;  // create a raw pointer on the heap
  *raw = 1;            // assign a value
  delte raw;           // delete the resouce again
}

void UniquePointer() {
  std::unique_ptr<int> unique(new int);  // create a unique pointed on the stack
  *unique = 2;                           // assign a value
                                         // delete is not necessary
}