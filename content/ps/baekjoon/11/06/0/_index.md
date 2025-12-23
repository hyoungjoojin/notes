+++
title = "11060"
math = true
+++

# 점프 점프

> Level: Silver 2

## Problem

Given an array $A$, we can jump from index $i$ to any index in the range $[i+1, i+A[i]]$.
Find the minimum number of jumps required to reach the last index from the first index.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (0ms, 2020KB) \
> Time: $O(n)$, Space: $O(n)$
