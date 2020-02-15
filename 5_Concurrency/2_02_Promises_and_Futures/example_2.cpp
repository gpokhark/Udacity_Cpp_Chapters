#include <future>
#include <iostream>
#include <thread>

void modifyMessage(std::promise<std::string>&& prms, std::string message) {
  std::this_thread ::sleep_for(
      std::chrono::milliseconds(4000));  // simulate work

  std::string modifiedMessage = message + " has been modified.";
  prms.set_value(modifiedMessage);
}

int main() {
  // define message
  std::string messageToThread = "My message";

  // create promise and future
  std::promise<std::string> prms;
  std::future<std::string> ftr = prms.get_future();

  // start thread and pass promise and argument
  std::thread t(modifyMessage, std::move(prms), messageToThread);

  // print original message to console
  std::cout << "Original message from main(): " << messageToThread << std::endl;

  // retrive modified message via future and print to console
  std::string messageFromThread = ftr.get();
  std::cout << "Modified message from thread(): " << messageFromThread
            << std::endl;

  // thread join
  t.join();

  return 0;
}