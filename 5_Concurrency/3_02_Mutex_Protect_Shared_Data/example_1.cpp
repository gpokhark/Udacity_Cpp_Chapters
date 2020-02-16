#include <algorithm>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

class Vehicle {
 public:
  Vehicle(int id) : _id(id) {}

 private:
  int _id;
};

class WaitingVehicles {
 private:
  std::vector<Vehicle>
      _vehicles;  // list of all vehicles waiting to enter this intersection
  int _tmpVehicles;

 public:
  WaitingVehicles() : _tmpVehicles(0) {}

  // getters and setters
  void printSize() { std::cout << "#vehicles = " << _tmpVehicles << std::endl; }

  // typical behaviour methods
  void pushBack(Vehicle &&v) {
    //_vehicles.push_back(std::move(v)); // data race would cause an exception
    int oldNum = _tmpVehicles;
    std::this_thread::sleep_for(std::chrono::microseconds(
        1));  // wait deliberately to expose the data race
    _tmpVehicles = oldNum + 1;
  }
};

int main() {
  std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);
  std::vector<std::future<void>> futures;

  for (int i = 0; i < 1000; i++) {
    Vehicle v(i);
    // std::launch::async gives error -> less number of vehicles.
    futures.emplace_back(std::async(std::launch::deferred,
                                    &WaitingVehicles::pushBack, queue,
                                    std::move(v)));
  }

  std::for_each(futures.begin(), futures.end(),
                [](std::future<void> &ftr) { ftr.wait(); });

  queue->printSize();

  return 0;
}