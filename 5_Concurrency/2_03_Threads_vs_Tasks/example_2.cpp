#include <cmath>
#include <future>
#include <iostream>
#include <memory>
#include <thread>

double divideByNumber(double num, double denom) {
  // print the system id of the worker thread
  std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  if (denom == 0)
    throw std::runtime_error("Execption from thread: Division by zero!");

  return num / denom;
}

int main() {
  // print the system if of the main thread
  std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

  double num = 42.0, denom = 2.0;

  // use async to start a thread
  // two different threads
  //   std::future<double> ftr = std::async(divideByNumber, num, denom);

  // same threads
  std::future<double> ftr =
      std::async(std::launch::deferred, divideByNumber, num, denom);

  // retrieve the result with try catch block
  try {
    double result = ftr.get();
    std::cout << "Result = " << result << std::endl;
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}