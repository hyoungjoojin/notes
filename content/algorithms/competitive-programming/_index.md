+++
title = "competitive-programming"
+++

# Competitive Programming Algorithms

Competitive programming is the practice of using well-known data structures and
algorithms to solve artificial problems efficiently within a time limit. This
page contains a collection of algorithms that are commonly used in competitive
programming contests, along with related problems from major competitive
programming platforms.

The IDs of the listed problems follow the same format, and my solutions to these
problems can be found [here](https://github.com/hyoungjoojin/ps) by following
the problem ID to the corresponding directory within the repository. Problem IDs
are composed of the platform ID and the problem number, and the platform IDs are
as follows: LC (LeetCode), CF (Codeforces), and AC (AtCoder).

## Implementation

- Related Problems
  - CF 61A: Given two binary strings, find the bitwise XOR of the two strings.
  - CF 451B: Given an array, determine if it can be sorted in non-decreasing
    order by reversing exactly one segment of the array.

## Brute Force

- Related Problems
  - CF 466A: Given the cost of a single ride and the cost of an $m$-day pass,
    find the minimum cost of traveling for $n$ days.

## Greedy Approach

- Related Problems
  - CF 265B

## Array

- Related Problems
  - CF 315B: Given an array we perform one of the following operations: change
    $a_i$ to $x$, increment every element by $x$, or query the value for $a_i$.

## Sorting

- Related Problems
  - CF 456A: Given two arrays of integers, determine if there exists a pair of
    indices $(i, j)$ such that $a[i] < a[j]$ and $b[i] > b[j]$.

- **First Missing Positive**: Given an array of integers, find the smallest
  positive integer that is not present in the array.
  - Related Problems
    - CF 27A

## Stack

### Valid Parentheses

- Related Problems
  - LC 20: Given a string of parentheses, determine if the string is valid.

## Set

- Related Problems
  - CF 368B: Given an array and an index $i$, find the number of distinct
    integers in the suffix of the array starting at index $i$.

## Priority Queue

- **Top K Elements**: Given an array of integers, return the $k$ largest
  elements in the array.
  - Related Problems
    - LC 703: Given a stream of integers, find the $k$-th largest element at any
      point in the stream.
    - LC 347: Given an array of integers, return the $k$ most frequent elements.
    - LC 215: Given an array of integers and an integer $k$, return the $k$-th
      largest element in the array.

## Hash Table

- Related Problems
  - LC 1: Given an array of integers and a target integer, find the indices of
    the two numbers in the array that add up to the target.

## 2D Prefix Sum

- Related Problems
  - LC 1314: Given a 2D matrix and an integer $k$, find the sum of all elements
    in the block of size $(2k + 1) \times (2k + 1)$ centered at that element for
    each element in the matrix.
  - LC 304: Given a 2D matrix, find the sum of the elements within a submatrix.

## Binary Search

- Related Problems
  - LC 704: Given a sorted array of integers, find the index of a target integer
    in the array.
  - CF 304A: Given an integer $n$, find the number of triplets $(a, b, c)$ such
    that $1 \leq a \leq b \leq c \leq n$ and $a^2 + b^2 = c^2$.

## Two Pointers

- Related Problems
  - LC 344: Given a string, reverse the string in place.

## Dynamic Programming

- Related Problems
  - AC DP-A: Given an array of integers, the cost of moving from position $i$ to
    $j$ is $|h_i - h_j|$. If we can only move from position $i$ to $i + 1$ or
    $i + 2$, find the minimum cost to move from the start to the end.
  - AC DP-B: Given an array of integers and $k$, the cost of moving from
    position $i$ to $j$ is $|h_i - h_j|$. If we can only move from position $i$
    to any position within the range between $i + 1$ and $i + k$, find the
    minimum cost to move from the start to the end.
  - AC DP-C: Given three arrays of same length $a$, $b$, and $c$, find the
    maximum sum of elements by choosing only one element from each array at any
    index and such that no consecutive elements are chosen from the same array.

### 0-1 Knapsack

- Related Problems
  - AC DP-D: Solve the 0-1 knapsack problem where the maximum weight of the
    knapsack is $10^5$.

### Unbounded Knapsack

### Kadane's Algorithm

- Related Problems
  - LC 53: Given an integer array, find the subarray with the largest sum.

### Longest Common Subsequence

- Related Problems
  - AC DP-F: Given two strings, find any longest common subsequence of the two
    strings.

### Longest Increasing Subsequence

- Related Problems
  - LC 300: Given an integer array, find the length of the longest strictly
    increasing subsequence.

### Matrix Chain Multiplication

### Bitmask DP

### Digit DP

### Dynamic Programming on Graphs

- Related Problems
  - AC DP-G: Given a directed acyclic graph, find the length of the longest path
    in the graph.

### Dynamic Programming on Grids

- Related Problems
  - AC DP-H: Given a grid of 0s and 1s, find the number of ways to move from the
    top-left corner to the bottom-right corner while moving only right or down,
    and only through cells containing 0.

## Graph Algorithms

### Graph Traversal

#### Grid BFS

- Related Problems
  - LC 463: Given a 2D grid of 0s and 1s, find the perimeter of the island
    represented by 1s.
  - LC 695: Given a 2D grid of 0s and 1s, find the maximum area of an island
    represented by 1s.

### Minimum Spanning Tree

#### Minimum Spanning Tree for Dense Graphs

- Related Problems
  - LC 1584: Given $n$ points on a 2D plane, find the minimum cost to connect
    all points, where the cost to connect two points is the Manhattan distance
    between them.

## Number Theory

### Binary Exponentiation

- Related Problems
  - LC 1922: Find the number of strings of length $n$ where the even-indexed
    characters are even digits and the odd-indexed characters are prime digits.

### Sieve of Eratosthenes

- Related Problems
  - LC 204: Given an integer $n$, count the number of prime numbers less than
    $n$.
  - CF 230B: Determine if a given integer has exactly three distinct positive
    divisors.

### Greatest Common Divisor (GCD)

- Related Problems
  - CF 483A: Find any three numbers $(a, b, c)$ in the range $[l, r]$ such that
    $(a, b)$ and $(b, c)$ are coprime but $(a, c)$ are not coprime.

## Bit Manipulation

- Related Problems
  - CF 467B: Given an array of integers and a target value, count the number of
    integers that have at most $k$ different bits from the target value.
