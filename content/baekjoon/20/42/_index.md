+++
title = "2042"
math = true
+++

# 구간 합 구하기

> Level: Gold 1

## Problem

Given an integer array and $n$ queries, where each query is of form $(q, a, b)$, answer the queries.

- If $q = 1$, update the element at index $a$ to $b$.
- If $q = 2$, print the sum of the elements between indices $a$ and $b$ (inclusive).

## Solution

### Segment Tree

> Implementation: [C++](./src/a.cpp) (180ms, 26224KB) \
> Time: $O(n + m\log n)$, Space: $O(n)$

A standard segment tree used for range-sum queries and point updates.
