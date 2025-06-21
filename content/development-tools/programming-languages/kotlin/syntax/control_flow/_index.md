+++
title = "control-flow"
+++

# Kotlin Control Flow

## Conditionals

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

## Loops

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
