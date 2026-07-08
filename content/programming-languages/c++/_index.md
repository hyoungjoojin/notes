+++
title = "c++"
heading = "C++"
+++

## C++ Standard Library

### C++ Iterators

- `std::advance`
- `std::prev`
- `std::next`

### `std::set`

`std::set` has its own `lower_bound` and `upper_bound` member functions. If we
use `std::lower_bound` and `std::upper_bound` with a `std::set`, we will get a
much more inefficient implementation than the member functions because the
`std::lower_bound` and `std::upper_bound` functions will assume that the
`std::set` is a random access container, making it $O(N)$ instead of
$O(\log N)$. The member functions use the underlying tree structure of the
`std::set` to perform a binary search and achieve logarithmic time complexity.

### C++ Numeric Library

#### Rounding

The `round` function family rounds a floating-point value to the nearest integer
and halfway cases rounded away from zero. `std::round` returns the rounded value
as a floating-point value and variants like `std::lround` and `std::llround`
return the rounded value as an integer type (`long` and `long long`).
