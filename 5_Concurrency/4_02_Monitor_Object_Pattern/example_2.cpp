#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Vehicle {
 private:
  int _id;

 public:
  Vehicle(int id) : _id(id) {}
  int getID() { return _id; }
};

class WaitingVehicles {
 private:
  std::vector<Vehicle>
      _vehicles;  // list of all vehicles waiting to enter this intersection
  std::mutex _mutex;

 public:
  WaitingVehicles() {}

  bool dataIsAvailable() {
    std::lock_guard<std::mutex> myLock(_mutex);
    return !_vehicles.empty();
  }

  Vehicle popBack() {
    // perform vector modification under the lock
    std::lock_guard<std::mutex> uLock(_mutex);

    // remove last vector element from the queue
    Vehicle v = std::move(_vehicles.back());
    _vehicles.pop_back();

    // will not be copied due to return value optimization (ROV) in c++
    return v;
  }

  void pushBack(Vehicle &&v) {
    // simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // perform vector modification under the lock
    std::lock_guard<std::mutex> uLock(_mutex);

    // add vector to queue
    std::cout << "Vehicle #" << v.getID() << " will be added to the queue.\n";

    _vehicles.emplace_back(std::move(v));
  }
};

int main() {
  // create monitor object as a shared pointer to enable access by multiple
  // threads
  std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);

  std::cout << "Spawning threads...\n";
  std::vector<std::future<void>> futures;
  for (int i = 0; i < 10; i++) {
    Vehicle v(i);
    futures.emplace_back(std::async(
        std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
  }

  std::cout << "Collecting results...\n";

  while (true) {
    if (queue->dataIsAvailable()) {
      Vehicle v = queue->popBack();
      std::cout << " Vehicle #" << v.getID()
                << " has been removed from the queue" << std::endl;
    }
  }

  std::for_each(futures.begin(), futures.end(),
                [](std::future<void> &ftr) { ftr.wait(); });

  std::cout << "Finished processing queue.\n";
  return 0;
}