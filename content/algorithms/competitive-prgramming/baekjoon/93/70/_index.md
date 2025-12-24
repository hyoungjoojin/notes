+++
title = "9370"
+++

# 미확인 도착지

> Level: Gold 2

## Problem

Given a weighted undirected graph, a starting point $s$, and two specific nodes $g$ and $h$.
Determine if a node's minimum distance from $s$ can include the edge between $g$ and $h$.

## Solution

### Dijkstra's Algorithm

> Implementation: [C++](./src/a.cpp) (28ms, 3512KB) \
> Time: $O(E\log V)$, Space: $O(V)$

Let $d(u, v)$ be the shortest distance between nodes $u$ and $v$.

We can determine if $u$ is reachable from $s$ via the edge between $g$ and $h$ by checking if:
either $d(s, g) + d(g, h) + d(h, u) = d(s, u)$ or $d(s, h) + d(h, g) + d(g, u) = d(s, u)$.
