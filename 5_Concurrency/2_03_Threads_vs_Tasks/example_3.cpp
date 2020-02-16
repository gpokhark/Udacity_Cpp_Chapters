#include <chrono>
#include <cmath>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

void workerFunction(int n) {
  // print system id of the worker thread
  std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;

  // perform work
  for (int i = 0; i < n; i++) sqrt(12345.6789);
}

int main() {
  // print the system if of the main thread
  std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

  // start time measurement
  std::chrono::high_resolution_clock::time_point t1 =
      std::chrono::high_resolution_clock::now();

  // launch various tasks
  std::vector<std::future<void>> futures;
  //   int nLoops = 10, nThreads = 5;

  std::vector<double> nLoops{1e7, 1e7, 10, 10};
  std::vector<int> nThreads{50, 50, 50, 50};

  // From class definition enum class launch { async = 1, deferred = 2}
  std::vector<std::launch> enumAsync{std::launch::async, std::launch::deferred,
                                     std::launch::async, std::launch::deferred};

  std::vector<int64_t> durations;
  int count = 0;

  for (auto nThread : nThreads) {
    std::cout << "==========================================================\n";
    std::cout << "Case no. " << count + 1 << " No. Threads = " << nThread
              << " No. of loops = " << nLoops[count] << std::endl;
    for (int i = 0; i < nThread; i++) {
      futures.emplace_back(
          std::async(enumAsync[count], workerFunction, nLoops[count]));
    }

    // wait for tasks to complete
    for (const std::future<void> &ftr : futures) ftr.wait();

    // stop time measurement and print execution time
    std::chrono::high_resolution_clock::time_point t2 =
        std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "Execution finished after " << duration << " microseconds.\n";
    durations.push_back(duration);
    count++;
  }
  std::cout << "********SUMMARY******** \n";
  count = 0;
  for (auto nThread : nThreads) {
    std::cout << "Case no. " << count + 1 << " No. Threads = " << nThread
              << " No. of loops = " << nLoops[count]
              << " Async type = " << static_cast<int>(enumAsync[count])
              << " Duration = " << durations[count] << std::endl;
    count++;
  }
  return 0;
}