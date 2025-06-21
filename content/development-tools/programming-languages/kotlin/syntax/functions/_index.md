+++
title = "functions"
+++

# Kotlin Functions

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

## Lambda Expressions

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
