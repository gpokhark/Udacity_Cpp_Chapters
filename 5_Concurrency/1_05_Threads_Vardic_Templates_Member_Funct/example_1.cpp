#include <iostream>
#include <string>
#include <thread>

void printID(int id) {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "ID = " << id << std::endl;
}

void printIDAndName(int id, std::string name) {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "ID = " << id << ", name = " << name << std::endl;
}

int main() {
  int id = 0;  // Define an integer value

  // starting threads using variadic templates
  std::thread t1(printID, id);
  std::thread t2(printIDAndName, ++id, "My String");
  //   std::thread t3(printIDAndName, ++id);  // this procduces a compiler error

  // wait for threads before returning
  t1.join();
  t2.join();
  //   t3.join();

  return 0;
}