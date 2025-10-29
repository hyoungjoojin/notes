+++
title = "2512"
math = true
+++

# 예산

> Level: Silver 2

## Problem

Given an array $A$ and a target $x$, find the maximum cap value $c$ such that $\sum_{a\in A}{\min{(a, c)}} \leq x$.

## Solution

### Paremetric Search

> Implementation: [C++](./src/a.cpp) (0ms, 2180KB) \
> Time: $O(n\log n)$, Space: $O(1)$
