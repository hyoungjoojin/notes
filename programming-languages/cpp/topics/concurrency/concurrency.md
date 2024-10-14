# C++ Concurrency

## C++ Parallel Algorithms
- C++ defines parallel algorithms in the standard library (C++17). 
- The compiler automatically changes sequential code into parallel code.
- The programmer must write the code so that there are no race conditions and locks inside the function.
- Existing STL functions support transformation to a C++ parallel algorithm.

```c++
  // Sequential code
  sum = std::reduce(array.begin(), array.end(), 0, std::plus<>{});

  // Parallel code
  sum = std::reduce(std::execution::par_unseq, array.begin(), array.end(), 0, std::plus<>{});
```

## C++ Threads
### std::thread
```c++
int main() {
    std::thread my_thread {[](int z) {
        std::cout << z << '\n';
    }, 42};

    my_thread.join();
}
```
- The constructor for std::thread returns a handle to the thread, not the actual thread (like a fork call).
- The std::thread constructor takes in any callable and the arguments for the callable.
- A join call waits for the thread to complete and blocks if neccesary.

### Race Conditions
- A data race happens when all of the following conditions are true.
    - Two or more threads access the same memory.
    - At least one access is a write access.
    - The threads do not synchronize with each other.
        - Parent threads and child threads are automatically synchronized on thread creation and joins.

## Synchronization Methods
- Mutexes (std::mutex)
    - Synchronization
        - A lock() call on a thread synchronizes with any previous call to unlock() on the same mutex. 
        - Everything that happened before the unlock on the other calls are visible to the thread after the lock call.
    - Available functions
        - lock()
        - try_lock()
        - unlock()
- Lock Guards (std::scoped_lock)
    - RAII wrappers for mutexes.
    - Mutexes should never be used directly, and instead be used through lock guards.
