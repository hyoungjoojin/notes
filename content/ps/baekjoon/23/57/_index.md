+++
title = "2357"
math = true
+++

# 최솟값과 최댓값

> Level: Gold 1

## Problem

Given an array $A$ and $m$ queries of form $(a, b)$, find $\min(A[a], A[a+1], \ldots, A[b])$ and
$\max(A[a], A[a+1], \ldots, A[b])$ for each query.

## Solution

### Segment Tree

> Implementation: [C++](./src/a.cpp) (60ms, 4468KB) \
> Time: $O(m\log n)$, Space: $O(n)$

We can use a segment tree to efficiently answer the range minimum queries.
