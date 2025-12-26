+++
title = "cp-algorithms"
+++

# Competitive Programming Algorithms

## Dynamic Programming

### Longest Increasing Subsequence (LIS)

**Problems**

- Given a sequence of integers, return one of its longest increasing subsequences.
  - [ ] Baekjoon 14003 (Platinum 5): The maximum possible length of the sequence is $10^6$.
- Given an array of integer pairs, each pair represents a line between point $(0, p_1)$ and $(1, p_2)$. Find the maximum number
  of lines that do not cross each other.
  - [ ] Baekjoon 2568 (Platinum 5): Return the list of lines to remove such that the remaining lines do not cross each other
        and the number of removed lines is minimized.

## Graph Algorithms

### Depth-First Search (DFS)

**Problems**

- Given an undirected graph and a starting node, perform a DFS traversal and return the order of nodes visited.
  - [ ] Baekjoon 24480 (Silver 2): Visit the nodes in descending order.

### Breadth-First Search (BFS)

**Problems**

- Given an undirected graph, find the number of connected components.
  - [ ] Baekjoon 2606 (Silver 3): Find the number of nodes connected to node 1.

#### Shortest Path

If the graph is unweighted, BFS can be used to find the shortest path from a starting node to all other nodes in the graph.

**Problems**

- Find the distance from vertex $a$ to $b$ in an unweighted graph.
  - [ ] Baekjoon 2644 (Silver 2)

#### BFS on Grid

**Problems**

- Given a grid that has walls and open spaces, find the area of each connected component of open spaces.
  - [ ] Baekjoon 3184 (Silver 1): There are elements $a$ and $b$ in the open spaces, and for each connected component the
        minority element gets removed. Count the number of remaining elements.

#### BFS on Number Line

**Problems**

- Given two integers $a$, $b$ and a set of transformations $S$, find the minimum number of operations required to transform
  $a$ into $b$.
  - [ ] Baekjoon 16953 (Silver 2): $S=\lbrace x\rarr 2x, x\rarr 10x + 1 \rbrace$

### Minimum Spanning Tree (MST)

**Problems**

- Given a weighted undirected graph, find the weight of its minimum spanning tree.
  - [ ] Baekjoon 16398 (Gold 4): The graph is given as an adjacency matrix.

## Sliding Window

**Problems**

- Find the maximum sum of a contiguous subarray of size $k$.
  - [ ] Baekjoon 2559 (Silver 3)

## String Algorithms

### Knuth-Morris-Pratt (KMP) Algorithm

The KMP algorithm is an efficient string matching algorithm that can find occurrences of a pattern string within a text
string.

**Problems**

- Find all occurrences of a pattern string within a text string [[C++](./strings/src/kmp.cpp)].
  - [ ] Baekjoon 1786 (Platinum 5)

## Math

### Number Theory

#### Sieve of Eratosthenes

**Problems**

- Given an integer $n$, find the prime factorization of $n$.
  - [ ] Baekjoon 2312 (Silver 3)
