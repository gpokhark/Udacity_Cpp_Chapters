#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

template <class T>
class MessageQueue {
 public:
  MessageQueue() : _numMessages(0) {}

  int getNumMessages() {
    std::lock_guard<std::mutex> uLock(_mutex);
    return _numMessages;
  }

  T receive() {
    // perform queue modification under the lock
    std::unique_lock<std::mutex> uLock(_mutex);
    // pass  the unique lock to conidition variable
    _cond.wait(uLock, [this] { return !_messages.empty(); });

    // remove last vector element from queue
    T msg = std::move(_messages.back());
    _messages.pop_back();
    --_numMessages;
    // will not be copied due to Return Value Optimization (RVO) in c++
    return msg;
  }

  void send(T &&msg) {
    // simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // perform vector modification under the lock
    std::lock_guard<std::mutex> uLock(_mutex);

    // add the vector to queue
    std::cout << "   Message " << msg << " has been sent to the queue.\n";

    _messages.push_back(std::move(msg));
    ++_numMessages;
    // notify client after pushing new message into the vector
    _cond.notify_one();
  }

 private:
  std::mutex _mutex;
  std::condition_variable _cond;
  std::deque<T> _messages;
  int _numMessages;
};

int main() {
  // create monitor object as a shared pointer to enable access by multiple
  // threads
  std::shared_ptr<MessageQueue<int>> queue(new MessageQueue<int>);

  std::cout << "Spawning threads...\n";
  std::vector<std::future<void>> futures;
  for (int i; i < 10; i++) {
    int message = i;
    futures.emplace_back(std::async(std::launch::async,
                                    &MessageQueue<int>::send, queue,
                                    std::move(message)));
  }

  std::cout << "Collecting results...\n";

  while (true) {
    int message = queue->receive();
    std::cout << "    Message #" << message
              << " has been removed form the queue.\n";

    if (queue->getNumMessages() <= 0) {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
      break;
    }
  }

  std::for_each(futures.begin(), futures.end(),
                [](std::future<void> &ftr) { ftr.wait(); });

  std::cout << "======================Finished!======================="
            << std::endl;
  return 0;
}