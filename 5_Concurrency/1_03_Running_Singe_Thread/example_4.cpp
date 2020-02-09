#include <iostream>
#include <thread>

void threadFunction() {
  std::this_thread::sleep_for(
      std::chrono::milliseconds(50));  // simulate some work
  std::cout << "Finished work 1 in thread. \n";

  std::this_thread::sleep_for(
      std::chrono::milliseconds(50));  // simulate some work
  std::cout << "Finished work 2 in thread. \n";
}

int main() {
  // create thread
  std::thread t(threadFunction);

  // do something in main function
  std::this_thread::sleep_for(
      std::chrono::milliseconds(50));  // simulate some work
  std::cout << "Finished work 1 in MAIN. \n";

  std::this_thread::sleep_for(
      std::chrono::milliseconds(50));  // simulate some work
  std::cout << "Finished work 2 in MAIN. \n";

  // wait for threads to finish
  t.join();

  return 0;
}