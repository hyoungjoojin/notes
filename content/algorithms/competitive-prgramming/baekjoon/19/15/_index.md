+++
title = "1915"
+++

# 가장 큰 정사각형

> Level: Gold 4

## Problem

Given a grid of 0s and 1s, find the largest square containing only 1s and return its area.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (20ms, 17884KB) \
> Time: $O(n^2)$, Space: $O(n^2)$

We can keep a memoization table keeping track of the maximum size of the square whose bottom-right corner is at each cell.
