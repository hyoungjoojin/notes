+++
title = "11660"
+++

# 구간 합 구하기 5

> Level: Silver 1

## Problem

Answer queries of the sum of elements in a submatrix of a given n x n matrix.

## Solution

### Prefix Sum

> Implementation: [C++](./src/a.cpp) (112ms, 6264KB) \
> Time: $O(n^2)$, Space: $O(n^2)$

We can use a 2D prefix sum table.
