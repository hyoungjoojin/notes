+++
title = "1932"
+++

# 정수 삼각형

> Level: Silver 1

## Problem

Given a lower triangular matrix of integers, find the maximum sum from the top to the bottom by moving to adjacent numbers on
the row below.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (8ms, 3080KB) \
> Time: $O(n^2)$, Space: $O(n)$

We can use a 1D array to store the maximum sums for each position in the current row.
