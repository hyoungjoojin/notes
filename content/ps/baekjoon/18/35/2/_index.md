+++
title = "18352"
math = true
+++

# 특정 거리의 도시 찾기

> Level: Silver 2

## Problem

Given a unweighted directed graph, find all nodes that are exactly K distance away from a starting node X.

## Solution

### BFS

> Implementation: [C++](./src/a.cpp) (356ms, 21316KB) \
> Time: $O(V+E)$, Space: $O(V)$

Since the graph is unweighted, we can use BFS to track the distance from the starting node to each node.
