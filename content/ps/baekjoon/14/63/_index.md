+++
title = "1463"
math = true
+++

# 1로 만들기

> Level: Silver 3 \

## Problem

Given a non-negative integer $N$, find the minimum number of operations within the following set
to make $N$ into 1. Division is only allowed if the remainder is 0.

- $x\rarr x - 1$
- $x\rarr \frac{x}{2}$
- $x\rarr \frac{x}{3}$

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (4ms, 5928KB) \
> Time: $O(n)$, Space: $O(1)$

Let $f(x)$ be the number of minimum operations required to make $x$ into 1.
Then, the following recursive relation holds. Using this relation, a bottom-up
approach can be used to compute $f(x)$ efficiently.

```python
def f(x):
    if x == 1:
        return 0

    result = f(x - 1)

    if x % 2 == 0:
        result = min(result, f(x / 2))

    if x % 3 == 0:
        result = min(result, f(x / 3))

    return result
```
