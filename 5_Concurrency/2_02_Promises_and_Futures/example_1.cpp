#include <iostream>
#include <thread>

void printMessage(std::string message) {
  std::this_thread::sleep_for(std::chrono::milliseconds(10));  // simulate work
  std::cout << "Thread 1: " << message << std::endl;
}

int main() {
  // define message
  std::string messge = "My message.";

  // start thread using variadic templates
  std::thread t1(printMessage, messge);

  // start thread using a lambda
  std::thread t2(
      [messge] { std::cout << "Thread 2: " << messge << std::endl; });

  // thread barrier
  t1.join();
  t2.join();
}