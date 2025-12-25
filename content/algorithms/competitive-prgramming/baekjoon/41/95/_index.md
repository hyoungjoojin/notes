+++
title = "4195"
+++

# 친구 네트워크

> Level: Gold 2

## Problem

Given a series of strings $s$ and $t$, for each pair we merge the sets containing $s$ and $t$ and output the size of the resulting set.

## Solution

### Disjoint Set Union

> Implementation: [C++](./src/a.cpp) (96ms, 19420KB) \
> Time: $O(n)$, Space: $O(n)$

We can use a disjoint set union data structure to represent the sets.
