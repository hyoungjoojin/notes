+++
title = "cp-algorithms"
+++

# Competitive Programming Algorithms

## Dynamic Programming

### Longest Increasing Subsequence (LIS)

**Problems**

- Given a sequence of integers, return one of its longest increasing subsequences.
  - [ ] Baekjoon 14003 (Platinum 5): The maximum possible length of the sequence is $10^6$.

## Graph Algorithms

### Depth-First Search (DFS)

**Problems**

- Given an undirected graph and a starting node, perform a DFS traversal and return the order of nodes visited.
  - [ ] Baekjoon 24480 (Silver 2): Visit the nodes in descending order.

### Breadth-First Search (BFS)

#### BFS on Number Line

**Problems**

- Given two integers $a$, $b$ and a set of transformations $S$, find the minimum number of operations required to transform
  $a$ into $b$.
  - [ ] Baekjoon 16953 (Silver 2): $S=\lbrace x\rarr 2x, x\rarr 10x + 1 \rbrace$

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
