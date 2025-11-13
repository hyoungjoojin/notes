+++
title = "concurrency"
+++

# Java Concurrency

## Java Threads

In Java, each thread is associated with an instance of the class `Thread`.
A thread can be created by either passing a `Runnable` object or by subclassing the `Thread` class.
Subclassing `Thread` can be used in simple applications, however the target class must extend the `Thread` class.

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
    (new MyThread()).start();

    (new Thread(new MyRunnable())).start();
    (new Thread(
            new Runnable() {

              @Override
              public void run() {
                System.out.println("Anonymous Runnable is running");
              }
            }))
        .start();
    (new Thread(
            () -> {
              System.out.println("Lambda Runnable is running");
            }))
        .start();
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
In order to provice memory synchronization, programmers have to define happens-before relationships between threads.
These happens-before relationships ensure that memory writes by one specific statement are visible to another specific statement.
This can be achieved using the following synchronization mechanisms.

- `Thread.start` and `Thread.join` methods create happens-before relationships.
- Synchronized blocks and methods create happens-before relationships.
- Volatile variables create happens-before relationships.

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

### Volatile Variables

Volatile variables refer to variables that provide atomic access and visibility guarantees.
Reads and writes to volatile variables are always done directly from and to the main memory, and the changes to a
volatile variable are always visible to other threads.
Reference types and rimitive types (except for `long` and `double`) are volatile by default.
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
