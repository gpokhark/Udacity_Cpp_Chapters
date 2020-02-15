#include <cmath>
#include <future>
#include <iostream>
#include <thread>

void computeSqrt(std::promise<double> &&prms, double input) {
  std::this_thread::sleep_for(
      std::chrono::milliseconds(2000));  // simulate some work
  double output = sqrt(input);
  prms.set_value(output);
}

int main() {
  // define input data
  double input = 42.0;

  // create promise and future
  std::promise<double> prms;
  std::future<double> ftr = prms.get_future();

  // start thread and pass promise as argument
  std::thread t(computeSqrt, std::move(prms), input);

  // Student task STARTS here
  // wait for result to become avaible
  auto status = ftr.wait_for(std::chrono::milliseconds(
      3000));  // 1000 and 2000 gives Result available.
  // if result is ready
  if (status == std::future_status::ready) {
    std::cout << "Result = " << ftr.get() << std::endl;
  }

  // timeout has expired or function has not yet been started
  else if (status == std::future_status::timeout ||
           status == std::future_status::deferred) {
    std::cout << "Result unavailbale. \n";
  }
  // Student task ends here

  // thread barrier
  t.join();

  return 0;
}