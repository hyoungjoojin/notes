+++
title = "2156"
+++

# 포도주 시식

> Level: Silver 1

## Problem

Given an array $A$, find the maximum sum of elements such that no more than two consecutive elements are chosen.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (0ms, 2180KB) \
> Time: $O(n)$, Space: $O(n)$

Let $f(i, x)$ be the maximum sum we can obtain by considering the first $i$ elements of the array and $x$ indicating
if we took the $i$-th element or not.
Then $f(i, 1) = \max(f(i-2, 1), f(i-2, 0) + A[i-1]) + A[i]$ and $f(i, 0) = \max(f(i-1, 1), f(i-1, 0))$.
