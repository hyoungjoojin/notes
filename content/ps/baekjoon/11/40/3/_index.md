+++
title = "11403"
math = true
+++

# 경로 찾기

> Level: Silver 1

## Problem

Given a adjacency matrix of a directed graph with $n$ vertices, determine whether there is a path from vertex
$i$ to vertex $j$ for all pairs $(i, j)$.

## Solution

### BFS

> Implementation: [C++](./src/a.cpp) (0ms, 2156KB) \
> Time: $O(n^2)$, Space: $O(n^2)$

Iterate through each vertex as a starting point, and perform BFS to find all reachable vertices from that starting point.
