+++
title = "11047"
math = true
+++

# 동전 0

> Level: Silver 4 \

## Problem

Given an array $A$ of $N$ integers ($A_i | A_{i-1}$) and an integer $v$,
find the minimum value of $\sum_{i} k_i$ such that $\sum_{i}{A_i k_i} = v$.

## Solution

### Greedy Algorithm

> Implementation: [C++](./src/a.cpp) (0ms, 2020KB) \
> Time: $O(n)$, Space: $O(1)$

Since $A_i$ divides $A_{i-1}$, we can take the greedy approach of taking as many larger elements
as possible.
