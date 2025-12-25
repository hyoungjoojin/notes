+++
title = "16194"
+++

# 카드 구매하기 2

> Level: Silver 1

## Problem

Given an array $A$ and a target value $N$, find the minimum value of $\sum_{i\in S}{A[i]}$ where $s$ is a multiset such that
$\sum_{j\in s}{j} = N$.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (0ms, 2020KB) \
> Time: $O(n)$, Space: $O(1)$

We can use dynamic programming to memoize the minimum value for each target value from $1$ to $N$.
