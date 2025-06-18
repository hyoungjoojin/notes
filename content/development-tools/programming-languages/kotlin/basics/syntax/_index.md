+++
title = "syntax"
+++

# Kotlin Syntax

The following document describes the syntax for Kotlin (v2.1.21).

## Variables

`val` is used for read-only variables, and `var` is used for mutable variables.

## Types

Kotlin is a strongly-typed language with support for type inference.

Variables can be initialized later, but reading a variable before initialization will cause an error.

```kotlin
val a: Int
a = 10

val b: String = "x"

val c = 3.14f // Type inferred as Float
```

### Type System

| Category               | Types                      |
| ---------------------- | -------------------------- |
| Integers               | Byte, Short, Int, Long     |
| Unsigned Integers      | UByte, UShort, UInt, ULong |
| Floating-point Numbers | Float, Double              |
| Booleans               | Boolean                    |
| Characters             | Char                       |
| Strings                | String                     |
| Void                   | Unit                       |

### Strings

String templates are declared using the dollar sign and optional curly braces.

```kotlin
val a = 1
println("a = $a, a + 1 = ${a + 1}")
```

### Nullable Types

Nullable types can be declared by adding a question mark at the end of the type declaration.
Variables that are not typed as nullable will throw a compilation error when assigning a null
value to the variable.

```kotlin
var nullableString: String? = null
```

For null safety, safe calls or the Elvis operator can be used. When accessing a nullable field
with a safe call, the call will return null if the field is null. The Elvis operator can provide
a default value if the value is null.

```kotlin
val nullableString: String? = null

val a = nullableString?.length // a is null
val b = nullableString?.length ?: 0 // b is 0
```

## Collections

Kotline provides lists, sets, and maps as default collection types.

### List

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

### Set

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

### Map

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

## Control Flow

### Conditionals

If statements and when statements are used in Kotlin. Both the if statements and when statements can
be used as either a statement or an expression. When using the conditionals as expressions, if the
resulting variable isn't typed, the branches are allowed to return different data types.

If statements are similar to other languages. Ternary operators do not exist, instead the if
statement can be used like an expression.

```kotlin
if(x) {
  y = 1
} else {
  y = 2
}

val a = if (x) a else b
val b = if(a > b) {
  a + b
} else {
  a - b
}
```

The when statement is like a switch statement. Using when, the parameter is compared with
all of the branches, and the branch where the parameter equals the branch value is taken. Using the
when statement without a parameter allows declaring branches with boolean expressions as predicates.
When statements must handle all possible cases.

```kotlin
val a = "1"
when(a) {
  "1" -> {
    val b = 2
    println("${a + b}")
  }
  "2" -> println("2")
  else -> println("default")
}

var b = when(a) {
  "1" -> 2
  "2" -> {
    a + 2
  }
  else -> 3
}

val c: Int = when {
  a == "1" -> {
    2
  }
  else -> {
    3
  }
}
```

### Loops

Ranges can be created using the following operators.

| Operator    | Result                                 |
| ----------- | -------------------------------------- |
| a..b        | a to b, inclusive                      |
| a..<b       | a to b - 1, inclusive                  |
| a downTo b  | a to b, inclusive in reverse order     |
| a..b step c | a to b, inclusive with increments in c |

The `in` operator is used in for loops, where it can be used with range values or collections.

```kotlin
for(a in 1..5) {
  print(a)
}
```

While loops and do-while loops aren't different from other programming languages.

```kotlin
while(a < 3) {
  a++
}
```

## Functions

`fun` is used to declare a function, and the main function is where the program starts.

```kotlin
fun main() {}
```

A function declaration can be done as below. Named arguments and default parameter values are supported.
Function declarations can be shortened into a single line using single-expression functions.

```kotlin
fun sum(x: Int, y: Int, z: Int = 0): Int {
  return x + y + z
}

fun sub(x: Int, y: Int): Int = x - y

sum(x = 1, y = 2)
```

A type of the function is expressed in the form of `(paramters) -> return`. For example, the `sum`
function's can be expressed as `(Int, Int) -> Int`. For a function that takes no parameters and
returns nothing, the type would be `() -> Unit`.

### Lambda Expressions

Lambda expressions are defined inside curly braces where the last line in the lambda statement
is the value that will be returned by the lambda. If the lambda expression is the last parameter
of a function, trailing lambdas can be used where the expression is written outside the function.
Lambdas with no function parameters can omit the function parameters.

```kotlin
val numbers = listOf(1, 2, 3, 4)

val filtered = numbers.filter({ x: Int -> x < 3 })

val mapped = numbers.map({
  x: Int ->
    var y = x - 2
    var z: (Int) -> Int = { x: Int -> x + 2 }
    x * y * z(y)
})

val folded = numbers.fold(0) { x, item -> x + item }


```

Lambda expressions can be used as variables. They can be returned from functions.

```kotlin
fun multiplyWith(x: Int): (Int) -> Int = {
  y: Int -> y * x
}

var multiplyWithTwo = multiplyWith(2)
multiplyWithTwo(5)
```

## Classes

A class in Kotlin is composed of a class header within parentheses, and a class body within
curly braces. Creating a new instance is like Java without the new keyword. Accessing and
modifying properties can be done like C structs.

```kotlin
class User(val id: Int, var email: String) {

  fun printId() {
    println(id)
  }
}

val user = User(1, "email")
val email = user.email
```

### Class Constructors

A default constructor that uses the class header parameters is created automatically.

```kotlin
class User(val id: Int, var email: String)

fun main() {
  val user = User(1, "email")
}
```

### Data Classes

Data classes provide additional member functions that are automatically added.

```kotlin
data class User(val id: Int, var email: String)
```

The following methods are some of the functions that are automatically added.

| Method Name | Description                              |
| ----------- | ---------------------------------------- |
| toString()  | Get a string value of the class instance |
| equals()    | Compare class instances                  |
| copy()      | Create a class instance by copying       |
