+++
title = "classes"
+++

# Kotlin Classes

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

## Class Constructors

A default constructor that uses the class header parameters is created automatically.

```kotlin
class User(val id: Int, var email: String)

fun main() {
  val user = User(1, "email")
}
```

## Data Classes

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
