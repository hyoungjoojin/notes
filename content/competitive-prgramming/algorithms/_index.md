+++
title = "algorithms"
math = true
+++

# Algorithms

# Dynamic Programming

## Longest Common Subsequence (LCS)

## Longest Increasing Subsequence (LIS)

The longest increasing subsequence problem is a problem of finding the longest subsequence within a sequence such that all
elements of the subsequence are sorted in increasing order.

### Patience Sorting

The LIS problem can be solved in $O(N\log N)$ using dynamic programming and binary search. This technique is also called
patience sorting.

**Problems**

- Find the length of the LIS.
  - [C++](./dp/src/lis-nlogn-find-length.cpp)
  - [ ] Baekjoon 11053 (Silver 2): $|A|\leq 10^3$.
- Find any one of the subsequences that form the LIS.
  - [C++](./dp/src/lis-nlogn-find-sequence.cpp)
  - [ ] Baekjoon 14002 (Gold 4): $|A|\leq 10^3$.
- Given an integer array $A$, each index $i$ represents a line between point $(0, i)$ and $(1, A[i])$. Find the minimum number
  of lines to remove such that no two remaining lines cross each other.
  - [ ] Baekjoon 2565 (Gold 5)
  - [ ] Baekjoon 1365 (Gold 2)
  - [ ] Baekjoon 2352 (Gold 2)

We apply binary search on the value $k$ since the search space of $k$ will be bounded by the
maximum value of $A$ and the cost of computing $\sum_{i}{\lceil \frac{A[i]}{k} \rceil}$ is
not that big.

#### Related Problems

- Leetcode 875

# Graph

## Depth-First Search (DFS)

Depth-first search (DFS) is a graph traversal algorithm that visits vertices by exploring as far as possible along each branch
before backtracking.

**Problems**

- Given a graph, find the order of nodes visited in a DFS traversal starting from a given node.
  - [ ] Baekjoon 24479 (Silver 2): Nodes are visited in ascending order.

## Breadth-First Search (BFS)

### BFS on Grids

While not strictly a graph, since grids can be represented as graphs where each cell is a node and edges exist between adjacent
cells, BFS can be applied to grids in the same way as graphs.
This can be useful for solving problems such as finding the shortest path in a maze or counting the number of connected
components in a grid.

**Problems**

- Given a grid of 0s and 1s, find the number of connected components of 1s.
  - [ ] Baekjoon 1012 (Silver 2): Cells are connected if they are adjacent horizontally or vertically.

# Tree

Trees are connected acyclic graphs.

## Tree Traversal

Tree traversal refers to the process of visiting all the nodes in a tree data structure in a specific order.
The following are examples of common tree traversal methods.

- Depth-First Search (DFS)
- Breadth-First Search (BFS)
- In-order Traversal
- Pre-order Traversal
- Post-order Traversal
- Level-order Traversal

**Problems**

- Given a preorder traversal and an inorder traversal of a binary tree, output the postorder traversal of the tree.
  - [ ] Baekjoon 4256 (Gold 2)
