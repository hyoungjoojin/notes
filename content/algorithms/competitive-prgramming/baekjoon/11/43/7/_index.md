+++
title = "11437"
+++

# LCA

> Level: Gold 3

## Problem

Given a tree and two nodes u and v, find their lowest common ancestor (LCA).

## Solution

### Naive LCA with Parent Pointers

> Implementation: [C++](./src/a.cpp) (936ms, 5304KB) \
> Time: $O(mn)$, Space: $O(n)$

### Sparse Table + Binary Lifting

> Implementation: [C++](./src/b.cpp) (24ms, 8112KB) \
> Time: $O(m\log n)$, Space: $O(n\log n)$
