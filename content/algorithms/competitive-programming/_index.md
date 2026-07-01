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

### String Parsing

- Related Problems
  - PG 64065: Parse a string that represents a list of integers and return the
    integer array.

### Simulation

- Related Problems
  - PG 67256: Given a number pad and a sequence of numbers to press, determine
    which hand should be used to press each number based on the given rules.

## Constructive Algorithms

- Related Problems
  - CSES 1070: Given an integer $n$, find any permutation of numbers 1 to $n$
    such that no two adjacent numbers have a difference of 1.
    - Solutions
      - This can be solved by placing all even numbers first, then all odd
        numbers.
  - CSES 1071: Given a grid of numbers that forms a spiral, determine the number
    at a given coordinate $(r, c)$.

## Brute Force

- Related Problems
  - CF 466A: Given the cost of a single ride and the cost of an $m$-day pass,
    find the minimum cost of traveling for $n$ days.
  - CSES 1069: Given a string, find the longest substring that contains only one
    unique character.

- **Collatz Sequence**: Simulate the Collatz sequence. The sequence is generated
  by the following rules. Given an integer $n$, divide it by 2 if $n$ is even
  and make it $3n+1$ if $n$ is odd. Terminate the sequence when $n$ becomes 1.
  - Related Problems
    - CSES 1068: The initial value is at most $10^6$.

### Backtracking

- **String Permutations**: Given a string, generate all possible permutations of
  the characters in the string.
  - Related Problems
    - CSES 1622: Given a string, print the number of distinct permutations of
      the characters in the string and print all distinct permutations in
      lexicographical order.

## Greedy Approach

- Related Problems
  - CF 265B
  - CSES 1094: Given an array of integers, find the minimum number of moves
    required to make the array increasing, where one move consists of increasing
    the value of any element by one.

- **Activity Selection**: Given $N$ intervals, find the maximum number of
  non-overlapping intervals that can be selected.
  - Related Problems
    - CSES 1629: Duplicate of the above problem.
    - AC 131D: Given $N$ tasks with a deadline and the time it takes to complete
      each task, determine whether it is possible to complete all tasks before
      their respective deadlines.

- **Tower Building**: Given a sequence of integers, find the minimum number of
  increasing subsequences that can be formed from the sequence where each
  element of the sequence belongs to exactly one subsequence.
  - Algorithms
    - This problem can be solved using a greedy approach with the patience
      sorting algorithm.
  - Related Problems
    - CSES 1073: Duplicate of the above problem.

## Recursion

- **Tower of Hanoi**
  - Related Problems
    - CSES 2165: Find the minimum number of moves required to solve the Tower of
      Hanoi problem for $N$ disks and print the sequence of moves.

## Array

- Related Problems
  - CF 315B: Given an array we perform one of the following operations: change
    $a_i$ to $x$, increment every element by $x$, or query the value for $a_i$.

## Sorting

- Related Problems
  - CSES 1621: Given an array of integers, find the number of distinct values in
    the array.
  - CF 456A: Given two arrays of integers, determine if there exists a pair of
    indices $(i, j)$ such that $a[i] < a[j]$ and $b[i] > b[j]$.

- **Missing Number**: Given an array, find the missing number in the array.
  - Related Problems
    - CSES 1083: Given an array of $n-1$ distinct integers in the range
      $[1, n]$, find the missing number.
    - CF 27A: Given an array of integers, find the smallest positive integer
      that is not present in the array.

## Stack

### Valid Parentheses

- Related Problems
  - LC 20: Given a string of parentheses, determine if the string is valid.

### Expression Evaluation

- Related Problems
  - PG 67257: Given a infix expression consisting of numbers and the operators
    `+`, `-`, and `*`, find the maximum absolute value of the result by changing
    the order of operations.

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
  - PG 42576: Given two string arrays $s$ and $t$, where $t$ is missing one
    element from $s$, return the missing element.
  - PG 1845: Given an array of integers, find the maximum number of different
    integers you can choose from the array, given that you can only choose half
    of the total number of integers in the array.

### Two Sum

- Related Problems
  - LC 1: Given an array of integers and a target integer, find the indices of
    the two numbers in the array that add up to the target.
  - CF 1931D: Given an array of integers and two values $x$ and $y$, find the
    number of pairs of indices $(i, j)$ such that $i < j$ and
    $(a_i + a_j) \mod x = 0$ and $(a_i - a_j) \mod y = 0$.
  - CF 1915E: Given an array of integers, determine if there exists two distinct
    indices $i$ and $j$ such that the sum of the elements at odd indices and
    even indices are equal in the subarray between $i$ and $j$.

## Binary Tree

- Related Problems
  - PG 150367: Given a method to encode a binary tree to a binary string,
    determine if a given number can be represented as a binary tree.

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

- **3 Sum**: Given an array of integers and a target integer, find all unique
  triplets in the array that sum up to the target.
  - Algorithms
    - This problem can be solved using binary search to be solved in
      $O(n^2 \log n)$.
    - This problem can also be solved using the two pointers technique to be
      solved in $O(n^2)$.
  - Related Problems
    - CSES 1641: Find any three distinct positions in the array such that the
      sum of the elements at those positions is equal to the target.

### Parametric Search

- Related Problems
  - PG 43238: Given an array of integers and a target value $k$, find the
    minimum value $x$ such that
    $\sum_{i=1}^{n} \lfloor \frac{x}{t_i} \rfloor \geq k$.
  - CF 371C: Given 4 arrays of length 3, representing $r$ for the required
    resources to make one entity, $c$ for the cost of each resource, $n$ for the
    number of resources you have, and $p$ for the price of each resource, find
    the maximum number of entities you can make.

## Sliding Window

- Related Problems
  - CSES 3220: Given an array of integers, calculate the sum of each window of
    size $k$ and return the XOR of all sums.

## Two Pointers

- Related Problems
  - LC 344: Given a string, reverse the string in place.

- **Contiguous Subarray Sum**: Given an array of integers and a target integer,
  find the number of contiguous subarrays whose sum equals the target.
  - Related Problems
    - CF 279B: Given an array of positive integers, find the maximum length of a
      contiguous subarray such that the sum of its elements is less than or
      equal to a given integer $T$.
    - AC 130D: Given an array of positive integers, find the number of
      contiguous subarrays such that the sum of its elements is greater than or
      equal to a given integer $T$.

- **Minimum Window Substring**: Given an array, find the smallest contiguous
  subarray that contains all the distinct elements in the array.
  - Related Problems
    - CSES 1141: Given an array of integers, find the longest subarray where
      every element of the subarray is unique.
    - CSES 2428: Given an array of integers, count the number of subarrays that
      have at most $k$ distinct values.
    - PG 67258: Duplicate of the above problem.

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
  - AC DP-I: Given an array of $N$ coins, each with a probability of $p_i$ of
    being heads, find the probability of getting more heads than tails when
    tossing all the coins.
  - CSES 1745: Given $n$ coins each with different values, find the number of
    distinct sums of money you can create using these coins by using each coin
    at most once.
  - CF 455A: Given an array of integers, find the maximum sum of elements that
    can be chosen such that when selecting an element $x$, you cannot select any
    element equal to $x-1$ or $x+1$ in subsequent selections.
  - PG 42897: Given an array of integers, find the maximum sum of selected
    elements in the array such that no two selected elements are adjacent and
    the first and last elements are not selected together.

### 0-1 Knapsack

- Related Problems
  - AC DP-D: Solve the 0-1 knapsack problem where the maximum weight of the
    knapsack is $10^5$.
  - CSES 1158: Duplicate of AC DP-D.

### Unbounded Knapsack

### Kadane's Algorithm

- Related Problems
  - CSES 1643: Find the maximum sum of a contiguous subarray.
  - LC 53: Given an integer array, find the subarray with the largest sum.
  - CF 1927D: Given an array of integers, for a given query of $(l, r)$, find
    any pair of indices $i, j$ such that $l \leq i < j \leq r$ and
    $a_i \neq a_j$.

### Longest Common Subsequence

- Related Problems
  - AC DP-F: Given two strings, find any longest common subsequence of the two
    strings.

### Longest Increasing Subsequence

- Related Problems
  - CSES 1145: Find the length of the longest increasing subsequence.
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
  - CSES 1638: Duplicate of AC DP-H.

## Graph Algorithms

### Graph Traversal

- **Number of Connected Components**: Given an undirected graph, find the number
  of connected components in the graph.
  - Related Problems
    - PG 43162: Duplicate of the above problem, the graph is given as an
      adjacency matrix.

#### Distance in Unweighted Graphs

- Related Problems
  - PG 49189: Given an undirected graph, find the number of nodes that are the
    farthest from a node.

#### Graph Bipartition

- Related Problems
  - CF 687A: Given an undirected graph, partition the vertices into two groups
    where the groups are disjoint and each group is a vertex cover of the graph.

#### Grid BFS

- Related Problems
  - LC 463: Given a 2D grid of 0s and 1s, find the perimeter of the island
    represented by 1s.
  - LC 695: Given a 2D grid of 0s and 1s, find the maximum area of an island
    represented by 1s.
  - CSES 1192: Given a grid of 0s and 1s, find the number of connected
    components of 1s in the grid.

### Shortest Path Algorithms

- Related Problems
  - CF 20C: Given an undirected weighted graph with non-negative edge weights,
    find any one of the shortest paths from a source vertex to a target vertex.

- **Multi-Source Shortest Path**: Given an undirected weighted graph with
  non-negative edge weights and a set of source vertices, find the shortest path
  from any source vertex to a target vertex.
  - Related Problems
    - CF 707B: Duplicate of the above problem.

- **Shortest Path in Directed Acyclic Graph**: Given a directed acyclic graph
  with weighted edges, find the shortest path from a source vertex to a target
  vertex.

### Topological Sort

- Related Problems
  - CSES 1679: Find any valid topological ordering of the graph.

### Minimum Spanning Tree

#### Minimum Spanning Tree for Dense Graphs

- Related Problems
  - LC 1584: Given $n$ points on a 2D plane, find the minimum cost to connect
    all points, where the cost to connect two points is the Manhattan distance
    between them.

## Range Queries

- **Range Sum Query**: Given an array of integers, perform range sum queries on
  the array.
  - Algorithms
    - This problem can be solved using prefix sum arrays.
  - Related Problems
    - CSES 1646: Duplicate of the above problem.
    - CSES 1650: Perform range XOR queries on the array.

- **Range Minimum Query**: Given an array of integers, perform range minimum
  queries on the array.
  - Algorithms
    - This problem can be solved using segment trees.
    - This problem can also be solved using sparse tables.
  - Related Problems
    - CSES 1647: Duplicate of the above problem.

- **Point Update Range Query**: Given an array of integers, perform point
  updates and range queries on the array.
  - Related Problems
    - CSES 1648: Duplicate of the above problem, answer range sum queries.
    - CSES 1649: Duplicate of the above problem, answer range minimum queries.

## String Algorithms

- Given a list of strings, find if there exists a pair of strings such that one
  string is a prefix of the other.
  - Related Problems
    - PG 42577: Duplicate of the above problem.

## Number Theory

- **Trailing Zeros**: Given an integer $N$, find the number of trailing zeros in
  $N!$.
  - Related Problems
    - CSES 1618: Duplicate of the above problem.

### Binary Exponentiation

- Related Problems
  - CSES 1095: Given $a$ and $b$, calculate $a^b$.
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
