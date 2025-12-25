+++
title = "2579"
+++

# 계단 오르기

> Level: Silver 3 \

## Problem

Given an array $A$ of $n$ non-negative integers, find the maximum value of $\sum{s_i}$ where
$s$ is a subsequence of $A$ that follows the following conditions.

1. $A_i\in s\implies A_{i+1}\in s \lor A_{i+2}\in s$
2. $A_i\in s\land A_{i+1}\in s \implies A_{i+2}\notin s$
3. $A_n\in s$

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (0ms, 2020KB) \
> Time: $O(n)$, Space: $O(n)$

Let $f(x)$ be the maximum value at index $x$. Then, $f(x)$ is the larger value between having
$A_{x-1}\in s$ or $A_{x-2}\in s$. These two conditions are mutually exclusive due to the conditions.
The former case is $f(x - 3) + A_{x - 1} + A_x$ and the latter is $f(x - 2) + A_x$.

```python
def f(x):
    if x == 1:
        return a[1]
    elif x == 2:
        return a[1] + a[2]
    elif x == 3:
        return max(a[1], a[2]) + a[3]

    return a[x] + max(f(n - 3) + a[n - 1], f(n - 2))
```
