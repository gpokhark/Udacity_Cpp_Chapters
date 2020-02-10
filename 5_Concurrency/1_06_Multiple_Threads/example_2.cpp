#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

int main() {
  // create threads
  std::vector<std::thread> threads;

  // In order to ensure the correct view on the counter variable i, pass it to
  // the Lambda function by value and not by reference &i.
  for (size_t i = 0; i < 10; i++) {
    // create new thread from a Lambda
    threads.emplace_back([i]() {
      // wait for certain amount of time
      std::this_thread::sleep_for(std::chrono::milliseconds(10 * i));

      // perform work
      std::cout << "Hello from worker thread #" << i << std::endl;
    });
  }

  // do something in main()
  std::cout << "Hello from Main thread" << std::endl;

  // call join on all thread objects using a range-based loop
  for (auto &t : threads) t.join();

  // do something in main()
  std::cout << "Second hello from Main thread" << std::endl;

  return 0;
}