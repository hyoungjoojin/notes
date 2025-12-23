+++
title = "1520"
math = true
+++

# 내리막 길

> Level: Gold 3

## Problem

Given a grid of numbers, we can move to an adjacent cell only if the number in that cell is lower than the current cell's number.
Find the number of distinct paths from the top-left cell to the bottom-right cell.

## Solution

### DFS + Dynamic Programming

> Implementation: [C++](./src/a.cpp) (24ms, 4832KB) \
> Time: $O(n^2)$, Space: $O(n^2)$

The number of distinct paths from a cell to the destination is the sum of the number of distinct paths from each of its
adjacent lower-valued cells to the destination.
