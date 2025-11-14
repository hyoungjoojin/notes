+++
title = "2660"
math = true
+++

# 회장뽑기

> Level: Gold 5

## Problem

Given a graph $G$, find the node with the smallest maximum distance to all other nodes.

## Solution

### BFS

> Implementation: [C++](./src/a.cpp) (0ms, 2024KB) \
> Time: $O(n^2)$, Space: $O(n)$

Use graph traversal starting from all nodes to find the maximum distance from each node to all other nodes.
