#include "ThreadPool.h"
#include <iostream>

// Beispiel zur Verwendung des ThreadPool

void printNumber(int number) { std::cout << "Number: " << number << std::endl; }

int multiply(const int a, const int b) {
    return a * b;
}

int main() {
  ThreadPool pool(4);

  std::vector<std::future<void>> results;
  for (int i = 0; i < 8; ++i) {
    results.emplace_back(pool.enqueue(printNumber, i));
  }

  for (auto &&result : results) {
    result.get();
  }

  results.clear();

  for (int i = 0; i < 8; ++i) {
    results.emplace_back(pool.enqueue(printNumber, i));
  }

  for (auto &&result : results) {
    result.get();
  }

  std::future<int> result = pool.enqueue(multiply, 3, 5);

  std::cout<< result.get();

  return 0;
}
