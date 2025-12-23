+++
title = "24479"
math = true
+++

# 알고리즘 수업 - 깊이 우선 탐색 1

> Level: Silver 2

## Problem

Given a graph, find the order of nodes visited in a DFS traversal starting from a given node.
Nodes are visited in ascending order.

## Solution

### DFS

> Implementation: [C++](./src/a.cpp) (80ms, 14056KB) \
> Time: $O(V+E)$, Space: $O(V)$

Keep a global counter to track the order of visits.
We can use a `order` array to store the order of each node when visited and also use this array to check if a node has been
visited or not.
Since nodes have to be visited in ascending order, we can sort the adjacency list of each node before performing DFS.
