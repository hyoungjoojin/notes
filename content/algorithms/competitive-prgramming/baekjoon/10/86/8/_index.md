+++
title = "10868"
+++

# 최솟값

> Level: Gold 1

## Problem

Given an array $A$ and $m$ queries of form $(a, b)$, find $\min(A[a], A[a+1], \ldots, A[b])$ for each query.

## Solution

### Segment Tree

> Implementation: [C++](./src/a.cpp) (48ms, 3440KB) \
> Time: $O(m\log n)$, Space: $O(n)$

We can use a segment tree to efficiently answer the range minimum queries.
