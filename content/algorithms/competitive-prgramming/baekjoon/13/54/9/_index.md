+++
title = "13549"
+++

# 숨바꼭질 3

> Level: Gold 5

## Problem

We are allowed to either move one step left or right in 1 second, or teleport to double our current position in 0 seconds.
Given two integers $N$ and $K$, find the minimum time required to reach from position $N$ to position $K$ on a number line.

## Solution

### BFS

> Implementation: [C++](./src/a.cpp) (0ms, 2544KB) \
> Time: $O(n)$, Space: $O(n)$

We can use the numbers as nodes and use BFS to find the shortest time to reach from $N$ to $K$.
