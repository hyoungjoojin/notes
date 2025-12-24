+++
title = "2667"
+++

# 단지번호붙이기

> Level: Silver 1

## Problem

Given a grid of 1s and 0s, find the number of connected components of 1s and the size of each component.

## Solution

### BFS

> Implementation: [C++](./src/a.cpp) (0ms, 2160KB) \
> Time: $O(n)$, Space: $O(1)$

We can use BFS to go through every connected component.
