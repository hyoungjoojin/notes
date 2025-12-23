+++
title = "20955"
math = true
+++

# 민서의 응급 수술

> Level: Gold 4

## Problem

Given an undirected graph $G$, find the minimum number of edges to remove to make $G$ a single connected tree.

## Solution

### BFS

> Implementation: [C++](./src/a.cpp) (36ms, 8840KB) \
> Time: $O(V+E)$, Space: $O(V)$

The result can be computed by the number of edges to remove in each connected component to make it a tree, and the number of
edges required to connect the separated components into a single tree. The first part can be calculated manually by considering
that a tree with $n$ nodes has $n-1$ edges. The second part is simply $\text{number of components} - 1$.
