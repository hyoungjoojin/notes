+++
title = "1149"
+++

# RGB거리

> Level: Silver 1 \

## Problem

An array $A$ of $N$ nodes and three integer arrays $a, b, c$ each of size $N$ is given.
Each node $A_i$ can select one of $a_i, b_i, c_i$ but adjacent nodes have to select from
different arrays. Find the minimum sum of the selected values.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (0ms, 2152KB) \
> Time: $O(n)$, Space: $O(1)$

Let $f(x, s)$ be the minimum sum of the selected values up until index $x$ where node $A_x$
selected from array $s\in \\{ a, b, c\\}$. Then $f(x, s)$ is the minimum value between
$f(x - 1, s^\prime)$, where $s^\prime\neq s$. The final result is the minimum
of $f(x, a), f(x, b), f(x, c)$. This can be computed inplace using a botton-up approach.
