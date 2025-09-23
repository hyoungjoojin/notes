+++
title = "9095"
math = true
+++

# 1, 2, 3 더하기

> Level: Silver 3 \

## Problem

Given a non-negative integer $N$, find the number of integer compositions of $N$ using the numbers 1, 2, and 3.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (0ms, 2020KB) \
> Time: $O(n)$, Space: $O(n)$

Let $f(x)$ be the number of integer compositions of $x$ using 1, 2, and 3.
Then, the following recursive relation holds. Using this relation, a top-down
approach can be used.

```python
def f(x):
    if x == 1:
        return 1
    elif x == 2:
        return 2
    elif x == 3:
        return 4

    return f(x - 1) + f(x - 2) + f(x - 3)
```
