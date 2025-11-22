+++
title = "concurrency"
+++

# Java Concurrency

## Java Threads

In Java, each thread is associated with an instance of the class `Thread`.
A thread can be created by either passing a `Runnable` object or by subclassing the `Thread` class.
Subclassing `Thread` can be used in simple applications, however the target class must extend the `Thread` class.
The `Runnable` interface is a functional interface, therefore it can be implemented using lambda expressions.

```java
class MyThread extends Thread {
  @Override
  public void run() {
    System.out.println("Thread is running");
  }
}

class MyRunnable implements Runnable {

  @Override
  public void run() {
    System.out.println("Runnable is running");
  }
}

public class Main {

  public static void main(String[] args) {
    Thread[] threads = {
      new MyThread(),
      new Thread(new MyRunnable()),
      new Thread(
          new Runnable() {

            @Override
            public void run() {
              System.out.println("Anonymous Runnable is running");
            }
          }),
      new Thread(
          () -> {
            System.out.println("Lambda Runnable is running");
          })
    };

    for (Thread thread : threads) {
      thread.start();
    }
  }
}
```

The following methods are used to manage threads.

- `sleep`: Threads can be paused for a specified duration using the `sleep` method.
- `join`: The current thread will wait until the thread on which `join` is called has finished executing.

Thread methods may throw an `InterruptedException`.
This is due to the thread being interrupted while it is in a sleeping or waiting state.
Interrupts are indications that a thread should stop what it is doing and do something else.
A thread can be interrupted by calling the `interrupt` method on the thread instance.
Methods that throw `InterruptedException` (like sleep) will cancel their current operation and return immediately, when
an interrupt is detected.

Interrupts are implemented using an internal flag called the interrupt status.
Threads can check if they have been interrupted by calling the `isInterrupted` method (doesn't clear the flag) or by
the `Thread.interrupted()` static method (clears the flag).

## Synchronization Mechanisms

When multiple threads access shared resources, synchronization mechanisms are required for data consistency.
In order to provide memory synchronization, programmers have to define happens-before relationships between threads.
These happens-before relationships ensure that memory writes by one specific statement are visible to another specific statement.
This can be achieved using the following synchronization mechanisms.

- `Thread.start` and `Thread.join` methods create happens-before relationships.
- Synchronized blocks and methods create happens-before relationships.
- Volatile variables create happens-before relationships.

### Executor Service

### Virtual Threads

Unlike Java's traditional platform threads, which are threads mapped directly to a native operating system thread, virtual
threads use a many-to-one threading model, where multiple lightweight virtual threads are mapped to a small number of
platform threads.

Platform threads are expensive to create due to the thread context and call stacks.
Reactive programming and asynchronous programming models attempt to solve this problem, but it is hard to use them in a
clean and straightforward way.
Virtual threads are lightweight threads that store the stack frames on the heap
Each virtual thread tend to use around several hundred bytes of memory, compared to several megabytes for platform threads.

Creating a virtual thread can be done by calling the `Thread.ofVirtual()` method.
There also exists an executor service for virtual threads.
In order to provide each virtual thread a name, we can pass a factory to the executor service.

```java
class VirtualThreads {

  public static void main(String[] args) throws InterruptedException {
    Thread.ofVirtual()
        .start(
            () -> {
              System.out.println("Virtual thread is running");
            });

    try (var executor = Executors.newVirtualThreadPerTaskExecutor()) {
      var result =
          executor.submit(
              () -> {
                System.out.println("Virtual thread is running");
              });
      result.get();
    }

    final ThreadFactory factory = Thread.ofVirtual().name("virtual-thread-", 0).factory();
    try (var executor = Executors.newThreadPerTaskExecutor(factory)) {
      var result =
          executor.submit(
              () -> {
                System.out.println(Thread.currentThread().getName() + " is running");
              });
      result.get();
    }
  }
}
```

To implement virtual threads, the JVM maintains a pool of platform threads using a `ForkJoinPool` with an initial
number of threads equal to the number of CPU cores.

In order for a virtual thread to start executing, the JVM first schedules the virtual thread onto a platform thread.
This platform thread is called the carrier thread of the virtual thread.
When executing, the JVM will copy the stack frame of the virtual thread from heap to the stack of the carrier thread.
When a virtual thread performs a blocking operation, the JVM saves the stack frame of the virtual thread back to the heap
and the carrier thread is returned to the pool of available platform threads.

Virtual threads are scheduled using a dedicated queue on the thread pool.
The threads are also cooperatively scheduled, so if a virtual thread does not perform any blocking operations, it will run
until it completes.

### Synchronized Blocks and Methods

Synchronized methods are methods with the `synchronized` keyword in their declaration.
It is not possible for two calls to synchronized instance methods on the same object to interleave.
This means that if one thread is executing a synchronized instance method on an object, no other thread can execute
a synchronized instance method on the same object until the first thread finishes.

Synchronized methods work by using intrinsic (or monitor) locks.
Synchronized instance methods lock the instance of the class, while synchronized static methods lock the `Class` object
associated with the class.

Constructors cannot be synchronized, but synchronized blocks can be used within constructors.
This is because other threads cannot access an object until after the constructor has finished executing.

Synchronized blocks provide a more fine-grained control over synchronization.
We pass in the object to lock on in parentheses after the `synchronized` keyword.

```java
public class Synchronization {

  private final Object lock = new Object();

  public synchronized void synchronizedMethod() {
    // critical section
  }

  public void synchronizedBlock() {
    synchronized (lock) {
      // critical section
    }
  }
}
```

### Atomic Variables

Atomicity refers to either having an operation complete fully or not at all.
Reads and writes to primitive types (except for `long` and `double`) and reference types are atomic by default.
Longs and doubles are not atomic by specification, due to hardware support for 32-bit machines, they can be written
in 32-bit chunks (although this will not happen on 64-bit machines).

Primitive types and reference types offer basic atomicity, but they are not atomic for compound operations like incrementing
a value.
The standard library provides atomic classes for such use cases.

### Volatile Variables

Volatility refers to visibility guarantees between threads, where a write to a variable by one thread is always visible
to the other threads.
This works by guaranteeing that reads and writes to a volatile variable are always done directly from and to the main memory
by flushing to memory for every writes.

Volatile variables refer to variables that provide atomic access and visibility guarantees.
Other types can be declared as volatile using the `volatile` keyword.

```java
public class VolatileExample {

  private volatile boolean flag = false;

  public void read() {
    if (flag) {}
  }

  public void write() {
    flag = true;
  }
}
```

## Thread Communication

### Wait and Notify

In the case where threads have to coordinate their actions, especially when a thread needs to wait for a condition to be
met before proceeding, the `wait` method can be used.
Instead of polling for a condition, if a thread calls `wait` on an object, it releases the lock on that object and enters a
waiting state.
If another thread modifies the condition and wants to notify waiting threads, it can call the `notify` or `notifyAll`.
The waiting thread will then reacquire the lock and continue execution.

The `wait`, `notify`, and `notifyAll` methods must be called from within a synchronized block or method.

```java
public class WaitNotifyExample {

  private final Object lock = new Object();
  private boolean condition = false;

  public void waitingThread() throws InterruptedException {
    synchronized (lock) {
      while (!condition) {
        lock.wait();
      }
    }
  }

  public void notifyingThread() {
    synchronized (lock) {
      condition = true;
      lock.notifyAll();
    }
  }
}
```
