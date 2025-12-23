+++
title = "10026"
math = true
+++

# 적록색약

> Level: Gold 5

## Problem

Given a grid of values where the values are either $R$, $G$, or $B$, count the number of connected components in the grid
where a vertical or horizontal connection is considered valid if they have the same value. Also, count the number of connected
components when considering $R$ and $G$ as the same value.

## Solution

### BFS

> Implementation: [C++](./src/a.cpp) (0ms, 2156KB) \
> Time: $O(n^2)$, Space: $O(n^2)$
