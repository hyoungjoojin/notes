+++
title = "collections"
+++

# Kotlin Collections

Kotline provides lists, sets, and maps as default collection types.

## List

A list is an array. Read-only lists are of type `List`, and mutable lists are of type `MutableList`.
The `listOf()` function is used to create a `List` and `mutableListOf()` is used to create a
`MutableList`. Casting a mutable list into a read-only list creates a unmodifiable view of the list.

```kotlin
val readOnlyList = listOf(1, 2, 3)
val mutableList: MutableList<Int> = mutableListOf(1, 2, 3)
val lockedList: List<Int> = mutableList;
```

Indexing elements is the same as other languages. Out of bounds problems will cause an exception.
In order to check if an item exists in the list, the `in` operator can be used.

```kotlin
val a = list[0];

val b: Boolean = 2 in list
```

The following are provided methods for lists.

| Method Name | Description                                           |
| ----------- | ----------------------------------------------------- |
| .first()    | Get the first element.                                |
| .last()     | Get the last element.                                 |
| .count()    | Get the number of elements in the list.               |
| .add(el)    | Add the element to the back of the list.              |
| .remove(el) | Remove the first instance of the element in the list. |

## Set

Sets are unordered collections that store unique items. A read-only set is a `Set` and a mutable set
is a `MutableSet`. The methods `setOf()` and `mutableSetOf()` are used to create read-only sets and
mutable sets. Casting a mutable set into a read-only set creates a unmodifiable view of the set.

```kotlin
var readOnlySet = setOf(1, 2, 1, 1)
var mutableSet: MutableSet<Int> = setOf(1, 2, 1, 1)
var lockedSet: Set<Int> = mutableSet
```

Indexing is not available with sets. To check if an item is in a set, the `in` operator can be used.

```kotlin
let a: Boolean = 1 in set
```

The following are provided methods for sets.

| Method Name | Description                            |
| ----------- | -------------------------------------- |
| .count()    | Get the number of elements in the set. |
| .add(el)    | Add the element to the set.            |
| .remove(el) | Remove the element from the set.       |

## Map

A map is a key-value item store. Maps can be a read-only `Map` created by `mapOf()`, or a mutable
map `MutableMap` created by `mutableMapOf()`. Casting can be used to create an unmodifiable view
of a mutable map.

```kotlin
val readOnlyMap = mapOf("a" to 1, "b" to 2, "c" to 3)
val mutableMap: MutableMap<String, Int> = mutableMapOf("a" to 1, "b" to 2, "c" to 3)
val lockedMap: Map<String, Int> = mutableMap.
```

Indexing a value is the same as indexing an element in a list. If the value doesn't exist in the map,
null will be returned. Adding elements is done using the index operator as well.

```kotlin
val x = map["a"]
map["d"] = 4
```

To get the keys and values of a map, property access can be used.

```kotlin
val keys = map.keys
val values = map.values
```

The following are provided methods for maps.

| Method Name       | Description                            |
| ----------------- | -------------------------------------- |
| .count()          | Get the number of elements in the map. |
| .remove(el)       | Remove the element from the map.       |
| .containsKey(key) | Check if a specific key is in the map. |
