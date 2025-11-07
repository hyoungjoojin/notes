+++
title = "3584"
math = true
+++

# 가장 가까운 공통 조상

> Level: Gold 4

## Problem

Given a tree and two nodes, find their lowest common ancestor (LCA).

## Solution

### LCA (Slow Version)

> Implementation: [C++](./src/a.cpp) (8ms, 2812KB) \
> Time: $O(n)$, Space: $O(n)$

Instead of using the binary lifting + sparse table method, since the input size is small, we can walk up the tree one step
at a time until we find the common ancestor.
