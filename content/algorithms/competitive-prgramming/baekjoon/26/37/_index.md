+++
title = "2637"
+++

# 장난감 조립

> Level: Gold 2

## Problem

We are given a weighted directed acyclic graph where an edge $(u, v, w)$ indicates that in order to build $v$, $w$ units of
$u$ are required. For every basic component (a node with no incoming edges), we find out how many units of it are required to
build one unit of the final component (a node with no outgoing edges).

## Solution

### Topological Sort

> Implementation: [C++](./src/a.cpp) (0ms, 2024KB) \
> Time: $O(V+E)$, Space: $O(V)$
