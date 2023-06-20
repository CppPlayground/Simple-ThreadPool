# Header only simple thread pool

> put your tasks into threads


## How to use it

```c++
#include "ThreadPool.h"
#include <iostream>

void printNumber(int number) { std::cout << "Number: " << number << std::endl; }

int main() {
    ThreadPool pool(4);

    std::vector<std::future<void>> results;

    // starting the threads
    for (int i = 0; i < 8; ++i) {
        results.emplace_back(pool.enqueue(printNumber, i));
    }

    // getting the results
    for (auto &&result : results) {
        result.get();
    }

    return 0;
}
```

multiply example

```c++
#include "ThreadPool.h"
#include <iostream>

int multiply(const int a, const int b) {
    return a * b;
}

int main() {
    ThreadPool pool(12);

    std::future<int> result = pool.enqueue(multiply, 3, 5);

    std::cout<< result.get();

    return 0;
}
```