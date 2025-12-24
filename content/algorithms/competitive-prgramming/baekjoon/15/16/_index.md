+++
title = "1516"
+++

# 게임 개발

> Level: Gold 3

## Problem

Given a directed acyclic graph where each node has some value, find the cost for each node where the cost of a node
is defined as the sum of its own value and the minimum cost among all its direct predecessors.

## Solution

### Topological Sort + Dynamic Programming

> Implementation: [C++](./src/a.cpp) (4ms, 2420KB) \
> Time: $O(V+E)$, Space: $O(V)$

We can use topological sorting while maintaining a memoized array that stores the cost for each node.
