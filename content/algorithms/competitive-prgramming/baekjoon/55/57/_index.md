+++
title = "5557"
+++

# 1학년

> Level: Gold 5

## Problem

Given an array $A$ of $n$ numbers, count the number of permutations of $k (k\in \lbrace 1, 2 \rbrace)$ such that
$\sum_{i=1}^{n-1}{(-1)^{k[i]} A[i]} = A[n]$.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (0ms, 2152KB) \
> Time: $O(n)$, Space: $O(n)$

We can use a 2-dimensional DP table that stores the number of ways to achieve a certain sum using the first $i$ numbers.
