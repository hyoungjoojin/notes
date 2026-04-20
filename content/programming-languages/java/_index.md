+++
title = "java"
+++

# Java

## Java Enums

In Java, enum types are implemented as classes and each enum constant is a
static final instance of the class. Instantiating an enum constant is a
compile-time error, therefore there is only one instance of each enum constant
in the application.

Although comparisons between class instances should use the `equals()` method
for value-based comparison, since enums can have only one instance of each
constant, the `==` operator can be used to compare enum constants. This is the
recommended way to compare enum constants because this is null-safe and can
provide type compatibility checks at compile time. The type compatibility checks
can grab errors like comparing constants from different enum types.

## Java Collection Framework

### Map

#### API

- `Map.of()`: Creates an immutable map with the specified key-value pairs.
  - In order to make a modifiable map, we can wrap the immutable map with
    `new HashMap<>(Map.of(...))`.
  - `Map.of()` does not allow null values. This is because null values can lead
    to unexpected behaviors (like whether the value is null or the key does not
    exist) and null pointer exceptions.
  - `Map.of()` does not allow duplicate keys. If duplicate keys are provided, an
    `IllegalArgumentException` is thrown. This is because not all map
    implementations allow duplicate keys.
- `Map.copyOf()`: Creates an immutable copy of the given map.
  - This is more memory efficient than creating a new `HashMap` instance because
    the JVM can optimize the internal structure to be more compact by using the
    fact that the map is immutable.

#### ConcurrentHashMap

- `ConcurrentHashMap`s do not allow null keys or null values like `HashMap`s.
