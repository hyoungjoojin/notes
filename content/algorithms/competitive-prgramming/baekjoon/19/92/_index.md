+++
title = "1992"
+++

# 쿼드트리

> Level: Silver 1

## Problem

We are given a grid of 0s and 1s. We recursively do the following.

- We split the grid into 4 sub-grids.
- If all the values in the sub-grid is the same, it can be represented as a single value.
- If it isn't, then we write the values of the sub-grids in order.

## Solution

### Recursion

> Implementation: [C++](./src/a.cpp) (0ms, 2160KB) \
> Time: $O(n)$, Space: $O(n\log n)$
