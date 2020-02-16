#include <future>
#include <iostream>
#include <thread>

class Vehicle {
 private:
  int _id;
  std::string *_name;

 public:
  // default constructor
  Vehicle() : _id(0), _name(new std::string("Default Name")) {
    std::cout << "Vehicle #" << _id << "Default constructor called.\n";
  }

  // initializing constructor
  Vehicle(int id, std::string name) : _id(id), _name(new std::string(name)) {
    std::cout << "Vehicle #" << _id << " Initializing constructor called.\n";
  }

  // setter and getter
  void setID(int id) { _id = id; }
  int getID() { return _id; }
  void setName(std::string name) { *_name = name; }
  std::string getName() { return *_name; }
};

int main() {
  // create instances of class Vehicle
  Vehicle v0;                  // default constructor
  Vehicle v1(1, "Vehicle 1");  // initializing constructor

  // launch a thread that modifies the Vehicle name
  std::future<void> ftr = std::async(
      [](Vehicle v) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        v.setName("Vehicle 2");
      },
      v0);

  v0.setName("Vehicle 3");

  ftr.wait();

  std::cout << v0.getName() << std::endl;
  return 0;
}