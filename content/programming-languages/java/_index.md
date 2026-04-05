+++
title = "java"
+++

# Java

## Java Enums

In Java, enum types are implemented as classes and each enum constant is a
static final instance of the class. It is a compile-time error to attempt to
create an instance of each enum constant, therefore it is guaranteed that there
is only one instance of each enum constant throughout the application.

For enums, because there is only one instance of each enum constant, the `==`
operator can be used to compare enum constants. This is actully the recommended
way to compare, since its more efficient and null-safe. The `==` is more
efficient because it compares the references of the enum constants, which is
faster than comparing their values. `==` also provides type compatibility checks
at compile time, meaning that comparing two enum constants of different types
will result in a compile-time error, which can help catch bugs early in the
development process.

## Java Collection Framework

### Map

#### API

- `Map.of()`: Creates an immutable map with the specified key-value pairs.
  - In order to make a modifiable map, we can wrap the immutable map with
    `new HashMap<>(Map.of(...))`.
