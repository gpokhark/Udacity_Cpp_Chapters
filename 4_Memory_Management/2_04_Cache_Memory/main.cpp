#include <chrono>
#include <iostream>

int main() {
  // create array
  const int size = 10000;
  static int x[size][size];

  auto t1 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      x[i][j] = i + j;
      // std::cout << &x[j][i] << ": i=" << i << ", j=" << j << std::endl;
    }
  }

  // print execution time to console
  auto t2 = std::chrono::high_resolution_clock::now();  // stop time measurement
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
  std::cout << "Execution time: " << duration << " microseconds" << std::endl;

  auto t3 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      x[j][i] = i + j;
      // std::cout << &x[j][i] << ": i=" << i << ", j=" << j << std::endl;
    }
  }

  // print execution time to console
  auto t4 = std::chrono::high_resolution_clock::now();  // stop time measurement
  duration =
      std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
  std::cout << "Execution time: " << duration << " microseconds" << std::endl;

  return 0;
}