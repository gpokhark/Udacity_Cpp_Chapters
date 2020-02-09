#include <iostream>
#include <thread>

class Vehicle {
 private:
  int _id;

 public:
  Vehicle() : _id(0) {}
  void addID(int id) { _id = id; }
  void printID() { std::cout << "Vehicle ID = " << _id << std::endl; }
};

int main() {
  // create thread
  std::shared_ptr<Vehicle> v(new Vehicle);
  std::thread t =
      std::thread(&Vehicle::addID, v, 1);  // call member funcions on object v

  // wait for thread to finish
  t.join();

  // print Vehicle id
  v->printID();

  return 0;
}