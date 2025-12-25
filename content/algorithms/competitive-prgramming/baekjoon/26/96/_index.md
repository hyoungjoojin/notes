+++
title = "2696"
+++

# 중앙값 구하기

> Level: Gold 2

## Problem

Given an array $A$, for each odd index $i$ find the median of the subarray $A[0:i]$.

## Solution

### Priority Queue

> Implementation: [C++](./src/a.cpp) (0ms, 2280KB) \
> Time: $O(n^2\log n)$, Space: $O(n)$

We can use two priority queues to find the median by maintaining the count of the two priority queues and balancing them.
