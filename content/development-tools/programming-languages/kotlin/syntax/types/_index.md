+++
title = "types"
+++

# Kotlin Types

Kotlin is a strongly-typed language with support for type inference.

Variables can be initialized later, but reading a variable before initialization will cause an error.

```kotlin
val a: Int
a = 10

val b: String = "x"

val c = 3.14f // Type inferred as Float
```

## Type System

| Category               | Types                      |
| ---------------------- | -------------------------- |
| Integers               | Byte, Short, Int, Long     |
| Unsigned Integers      | UByte, UShort, UInt, ULong |
| Floating-point Numbers | Float, Double              |
| Booleans               | Boolean                    |
| Characters             | Char                       |
| Strings                | String                     |
| Void                   | Unit                       |

## Strings

String templates are declared using the dollar sign and optional curly braces.

```kotlin
val a = 1
println("a = $a, a + 1 = ${a + 1}")
```

## Nullable Types

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
