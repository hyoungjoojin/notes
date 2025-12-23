+++
title = "1012"
math = true
+++

# 유기농 배추

> Level: Silver 2

## Problem

Given a grid of size $N\times M$ with cells of either 0 or 1, count the number of connected components of 1s.
Cells are connected if they are adjacent horizontally or vertically.

## Solution

### BFS

> Implementation: [C++](./src/a.cpp) (0ms, 2156KB) \
> Time: $O(NM)$, Space: $O(NM)$

We can use BFS to explore each connected component of 1s in the grid.
