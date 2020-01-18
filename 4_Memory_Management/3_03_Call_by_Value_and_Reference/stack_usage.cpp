#include <stdio.h>
#include <bitset>
#include <iostream>
#include <string>

void CallByValue(int i) {
  int j = 1;
  printf("call-by-value: %p\n", &j);
}

void CallByPointer(int *i) {
  int j = 1;
  printf("call-by-pointer: %p\n", &j);
}

void CallByReference(int &i) {
  int j = 1;
  printf("call-by-reference: %p\n", &j);
}

int main() {
  int i = 0;
  printf("stack bottom: %p\n", &i);

  CallByValue(i);

  CallByPointer(&i);

  CallByReference(i);

  char c = 0x4;
  std::bitset<8> char_bs(c);  // templated argument is the size in bits
  std::cout << char_bs.to_string() << std::endl;
  std::cout << char_bs.to_ulong() << std::endl;
  std::cout << char_bs.size() << std::endl;

  return 0;
}