+++
title = "2805"
math = true
+++

# 나무 자르기

> Level: Silver 2

## Problem

Given an array $A$ and a target $x$, find the value $h$ such that $\sum_{i}{\max{(A[i] - h, 0)}}$
is maximized and is greater than $x$.

## Solution

### Parameric Search

> Implementation: [C++](./src/a.cpp) (140ms, 9836KB) \
> Time: $O(n\log n)$, Space: $O(1)$
