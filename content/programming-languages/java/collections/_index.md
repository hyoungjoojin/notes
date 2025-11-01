+++
title = "collections"
+++

# Java Collection Framework

The Java Collection Framework (JCF) is a standard library in Java that provides a unified interface for working with
multiple types of data structures.

The JCF is mainly split into two categories, collections and maps. Collections are for iterating over elements and maps are for
storing key-value pairs.

The JCF also includes various legacy classes, like `Vector`, `Stack`, or `HashTable`. These can be identified by their names,
which do not end in `List` or `Map` like the modern counterparts.

## Collections

Collections implement the `Collection` interface, and the `Collection` interface extends the `Iterable` interface.

The `Iterable` interface is used to implement objects that can be iterated over, like supporting for-each statements or
iterators. Maps do not implement `Iterable`, so they can't be used with these features.

The `Collection` interface provides the following functionalities.

- Adding (`add`) or removing (`remove`) elements. These methods return a boolean since the operation could fail, for example
  inserting a duplicate value in a set.
- Getting the number of elements (`size`) and if the collection is empty or not (`isEmpty`).
- Testing if an element is present or not (`contains`).
- Clearing the collection (`clear`).
- Testing if a collection is included in another collection or not (`containsAll`).
- Union (`addAll`), intersection (`retainAll`), complements (`removeAll`) of collections.
- Iterating over the elements of a collection.
  - The `Iterable` interface provides multiple methods to iterate over a collection.
    - For-each syntax (`for(String s : collection)`).
    - Iterator (`for(Iterator<String> it  = collection.iterator(); iterator.hasNext();) element = iterator.next()`)
- Creating streams or parallel streams from a collection.
- Creating an array from the collection (`toArray`). This method creates an array of plain objects.
  - In order to create a type-safe array from a collection, we can either provide an array or a generator to the `toArray` method.
    - `.toArray(new String[15])`: If the given array is too large, the first unused element will be filled with a null-value. If
      it is too small, a new array will be allocated.
    - `.toArray(String[]::new)`: In this case, a zero-length array is created and passed in as the argument.
- Filtering out elements in a collection based on a predicate (`removeIf`).
- Creating immutable collections (`of`, `copyOf`).
  - The implementation of the resulting collection will differ based on the number of elements.
  - Null-values are not accepted in the created collections, a `NullPointerException` will be raised.

### List

Lists are ordered collections that allow duplicates and index-based access (`get`, `set`, `add(index, el)`, `remove(index)`).

Lists provide the following additional features on top of collections.

- Finding the index of an object (`indexOf`, `lastIndexOf`).
- Sublists (`sublist`).
- Sorting (`sort`).
  - A comparator is required as an argument. In order to use the natural order, either using a null argument or
    using `Comparator.naturalOrder()` could work.
- A list-specific iterator (`listiterator`).

#### ArrayList

A simple dynamic array implementation like C++'s vectors. Some major things to note with `ArrayList`s are as follows.

- `ArrayList`'s size grow by 50% when its full.
- `ArrayList`s are not synchronized and are not thread-safe.
- `ArrayList`s allow null-insertions.

Although `Vector` provides similar features to `ArrayList` with additional thread-safety, it is advised to use the Collection
API's `synchronizedList`.

#### LinkedList

A doubly linked list implementation. `LinkedList` also implements the `Deque` interface. Same as a C++ linked list, due to
the cost of CPU cache misses, iterating through a `LinkedList` can be very slow.

#### Vector

Similar to `ArrayList` but it is thread-safe and synchronized.

#### Stack

A standard thread-safe stack that extends `Vector`. If thread-safety is unnecessary, `ArrayDeque` class should be used instead.

### Queue

#### PriorityQueue

#### ArrayDeque

`ArrayDeque` uses a resizable array to implement a double-ended queue.

#### BlockingQueue

### Set

Sets are an unordered collection that do not allow duplicates. Depending on the implementation, the result of iteration on a
set could be in order, however this behavior should not be relyed upon.

#### HashSet

A `HashSet` is a set that internally uses a `HashMap`.

#### LinkedHashSet

#### SortedSet

The `SortedSet` interface keeps the elements stored in order.

The following methods are added in the `SortedSet` on top of `Set`.

- First (`first`) and last (`last`) elements of the set.
- Subsets between two elements (`subSet`), smaller than an element (`headSet`), or larger than an element (`tailSet`).

#### NavigableSet

`NaviagbleSet` extends from `SortedSet` to provide searching elements that are close to a search target.

#### TreeSet

`TreeSet` implements the `NavigableSet` interface.

## Map

### HashMap

### HashTable

A thread-safe implementation of a hash table. `HashTable` should not be used and should be replaced by either
`HashMap` (for non-concurrent environments) or `ConcurrentHashMap` (for concurrent environments).

### LinkedHashMap

### IdentityHashMap

### SortedMap

### NavigableMap

### TreeMap

## Factory Classes

### Arrays

### Collections

#### Synchronized Collections

Methods with `synchronized` followed by the collection name (`synchronizedList`, `synchronizedMap`, etc.) return a thread-safe
version of the given collection. However, using the Java Concurrency Utilities may be a better option in most cases.
