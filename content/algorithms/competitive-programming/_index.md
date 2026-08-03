+++
title = "competitive-programming"
heading = "Competitive Programming Algorithms"
+++

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

- **Interval Point Cover**: Find the minimum number of points required to cover
  a set of intervals.
  - Related Problems
    - CSES 1084: Find the maximum number of points that can be selected from a
      set of points such that each interval contains at most one selected point.

- **Ferris Wheel**: Given an array of integers, find the minimum number of
  groups required to group all the integers in the array, where each group can
  hold at most 2 integers and the sum of the integers in each group is less than
  or equal to a given integer $x$.
  - Algorithms
    - Sort the array and use two pointers to find the number of packages
      required by matching the smallest and largest integers in the array.
  - Related Problems
    - LC 881: Duplicate of the above problem.
    - CSES 1090: Duplicate of the above problem.

- **Collecting Numbers**: Count the number of left to right passes to collect a
  permutation's values in increasing order.
- Related Problems
  - CSES 2216: Duplicate of the above problem.

- **Maximum Overlapping Intervals**: Given $N$ intervals, find the maximum
  number of overlapping intervals at any point in time.
  - Algorithms
    - Use a greedy approach by maintaining two arrays, one for the start times
      and one for the end times of the intervals. Sort both arrays and use two
      pointers to find the maximum number of overlapping intervals.
  - Related Problems
    - CSES 1619: Duplicate of the above problem.

- **Activity Selection**: Given $N$ intervals, find the maximum number of
  non-overlapping intervals that can be selected.
  - Algorithms
    - Use a greedy approach by sorting the intervals by their end times and
      selecting the intervals that end the earliest.
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

- **Missing Positive Integer Sum**: Given an array of integers, find the
  smallest positive integer that cannot be represented as the sum of any subset
  of the array.
  - Algorithms
    - Sort the array and iterate through the elements. If the next integer is
      greater than the next expected sum, then the next expected sum is the
      smallest positive integer that cannot be represented as the sum of any
      subset of the array. The next expected sum can be updated by adding the
      current integer to it. This is because all integers less than or equal to
      the next expected sum can be represented as the sum of a subset of the
      array, and any integer greater than the next expected sum cannot be
      represented as the sum of any subset of the array.
  - Related Problems
    - CSES 2183: Duplicate of the above problem.

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
  - CF 456A: Given two arrays of integers, determine if there exists a pair of
    indices $(i, j)$ such that $a[i] < a[j]$ and $b[i] > b[j]$.

- **Distinct Numbers**: Given an array of integers, find the number of distinct
  values in the array.
  - Related Problems
    - CSES 1621: Duplicate of the above problem.

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

### Monotonic Stack

- **Nearest Smaller Element**: Given an array of integers, find the nearest
  smaller element for each element in the array.
  - Related Problems
    - CSES 1645: Given a sequence of integers, find the nearest smaller value to
      its left for each element.

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

- **Two Sum**: Given an array of integers and a target integer, find the indices
  of the two numbers in the array that add up to the target.
  - Related Problems
    - LC 1: Duplicate of the above problem.
    - CSES 1640: Duplicate of the above problem.
    - CF 1931D: Given an array of integers and two values $x$ and $y$, find the
      number of pairs of indices $(i, j)$ such that $i < j$ and
      $(a_i + a_j) \mod x = 0$ and $(a_i - a_j) \mod y = 0$.
    - CF 1915E: Given an array of integers, determine if there exists two
      distinct indices $i$ and $j$ such that the sum of the elements at odd
      indices and even indices are equal in the subarray between $i$ and $j$.

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
  - CF 304A: Given an integer $n$, find the number of triplets $(a, b, c)$ such
    that $1 \leq a \leq b \leq c \leq n$ and $a^2 + b^2 = c^2$.

- **Search Target in Sorted Array**: Given a sorted array of integers and a
  target integer, find the index of the target in the array.
  - Related Problems
    - LC 704: Duplicate of the above problem.
    - LC 374: Guess the number selected by the program, where the program will
      return hints on whether the guessed number is higher, lower, or equal to
      the selected number.
    - LC 540: Given a sorted array consisting of integers where every element
      appears exactly twice, except for one element which appears exactly once.
      Find this single element that appears only once.

- **Search Target in Sorted 2D Matrix**: Given a 2D matrix where each row is
  sorted in ascending order and the first integer of each row is greater than
  the last integer of the previous row, find a target integer in the matrix.
  - Algorithms
    - This problem can be solved by using binary search on the first column,
      then using binary search on the row that contains the target.
  - Related Problems
    - LC 74: Duplicate of the above problem.

- **Lower and Upper Bounds**: Given a sorted array of integers and a target
  integer, find the lower and upper bounds of the target in the array.
  - Related Problems
    - LC 35: Given a sorted array and a target value, find the index to insert
      the target.

### Binary Search on Sets

- **Dynamic Lower and Upper Bounds**: Given a sorted array of integers and a
  target integer, find the lower and upper bounds of the target in the array,
  where the array can be modified by adding or removing elements.
  - Related Problems
    - CSES 1091: Find the largest number in the array that is less than or equal
      to a given integer and remove it from the array.

- **Traffic Lights**: Given a street of length $x$ with traffic lights added one
  at a time at distinct positions, after each addition report the length of the
  longest gap between consecutive lights (including the ends 0 and x).
  - Algorithms
    - Use a set to store the positions of the traffic lights and a multiset to
      store the lengths of the gaps between consecutive lights. After each
      addition, update the sets and report the length of the longest gap. To
      find the position of the traffic light to be added, use binary search on
      the set of traffic lights.
  - Related Problems
    - CSES 1163: Duplicate of the above problem.

### Binary Search on Custom Data Structures

- **Time-Based Key-Value Store**: Implement a time-based key-value store that
  supports setting and getting values based on timestamps.
  - Related Problems
    - LC 981: Duplicate of the above problem.

### Parametric Search

- Related Problems
  - PG 43238: Given an array of integers and a target value $k$, find the
    minimum value $x$ such that
    $\sum_{i=1}^{n} \lfloor \frac{x}{t_i} \rfloor \geq k$.
  - CF 371C: Given 4 arrays of length 3, representing $r$ for the required
    resources to make one entity, $c$ for the cost of each resource, $n$ for the
    number of resources you have, and $p$ for the price of each resource, find
    the maximum number of entities you can make.

- **Square Root**: Given an integer $n$, find the largest integer $x$ such that
  $x^2 \leq n$.
  - Related Problems
    - LC 367: Given an integer, determine if it is a perfect square.

- **Koko Eating Bananas**: Given an array of integers representing the number of
  bananas in each pile and an integer $h$ representing the number of hours, find
  the minimum integer $k$ such that Koko can eat all the bananas in $h$ hours,
  where Koko can eat at most $k$ bananas per hour.
  - Related Problems
    - LC 875: Duplicate of the above problem.

## Sliding Window

- Related Problems
  - CSES 3220: Given an array of integers, calculate the sum of each window of
    size $k$ and return the XOR of all sums.

## Two Pointers

- Related Problems
  - LC 344: Given a string, reverse the string in place.

- **Subarray Sum**: Given an array of positive integers, find the number of
  subarrays whose sum is equal to a target value.
  - Related Problems
    - CSES 1660: Duplicate of the above problem.
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

- **Minimum Required Edges to Connect Graph**: Given an undirected graph, find
  the minimum number of edges required to connect all the connected components
  in the graph.
  - Related Problems
    - CSES 1666: Duplicate of the above problem. Also, find any valid set of
      edges that can be added to connect the graph.

#### Distance in Unweighted Graphs

- Related Problems
  - PG 49189: Given an undirected graph, find the number of nodes that are the
    farthest from a node.

#### Graph Bipartition

- Related Problems
  - CF 687A: Given an undirected graph, partition the vertices into two groups
    where the groups are disjoint and each group is a vertex cover of the graph.

- **Bipartite Graph Check**: Given an undirected graph, determine if the graph
  is bipartite.
  - Related Problems
    - CSES 1668: Duplicate of the above problem. Also, find any valid coloring
      of the graph if it is bipartite.

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

#### Shortest Path on Unweighted Graphs

- **Shortest Path in Unweighted Graph**: Given an unweighted graph, find the
  shortest path from a source vertex to a target vertex.
  - Related Problems
    - CSES 1667: Duplicate of the above problem.

- **Shortest Path in Grid**: Given a 2D grid of 0s and 1s, find the shortest
  path from a source cell to a target cell, where you can only move to adjacent
  cells that contain 0s.
  - Related Problems
    - CSES 1193: Duplicate of the above problem.

#### Shortest Path on Weighted Graphs

- **Dijkstra's Algorithm**: Given a directed graph with non-negative edge
  weights, find the shortest path from a source vertex to all other vertices.
  - Related Problems
    - CSES 1671: Duplicate of the above problem.

- **Shortest Path with Discounts**: Given a directed graph with weighted edges,
  find the shortest path from a source vertex to a target vertex where there can
  be at maximum $k$ discounts applied to the edges.
  - Related Problems
    - CSES 1195: Duplicate of the above problem. There can be at most 1 discount
      that halves the weight of an edge.

- **Floyd-Warshall Algorithm**: Given a directed graph with weighted edges, find
  the shortest path between all pairs of vertices.
  - Related Problems
    - CSES 1672: Answer $N$ queries of the shortest path between two vertices.

### Topological Sort

- Related Problems
  - CSES 1679: Find any valid topological ordering of the graph.

### Minimum Spanning Tree

#### Minimum Spanning Tree for Dense Graphs

- Related Problems
  - LC 1584: Given $n$ points on a 2D plane, find the minimum cost to connect
    all points, where the cost to connect two points is the Manhattan distance
    between them.

## Tree Algorithms

- **Count Children**: Given a tree, count the number of children for a node.
  - Related Problems
    - CSES 1674: Count the number of children for every node in the tree.

- **Tree Diameter**: Given a tree, find the diameter of the tree.
  - Related Problems
    - CSES 1131: Find the length of the diameter of the tree.

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

## Mathematics

### Optimization

- **$\sum{|a_i - x|}$**: Given an array of integers, find the integer $x$ that
  minimizes the sum of the absolute differences between each element in the
  array and $x$.
  - Algorithms
    - This problem can be solved by finding the median of the array.
  - Related Problems
    - CSES 1074: Duplicate of the above problem.

### Number Theory

- **Trailing Zeros**: Given an integer $N$, find the number of trailing zeros in
  $N!$.
  - Related Problems
    - CSES 1618: Duplicate of the above problem.

#### Binary Exponentiation

- Related Problems
  - CSES 1095: Given $a$ and $b$, calculate $a^b$.
  - LC 1922: Find the number of strings of length $n$ where the even-indexed
    characters are even digits and the odd-indexed characters are prime digits.

#### Sieve of Eratosthenes

- Related Problems
  - LC 204: Given an integer $n$, count the number of prime numbers less than
    $n$.
  - CF 230B: Determine if a given integer has exactly three distinct positive
    divisors.

#### Greatest Common Divisor (GCD)

- Related Problems
  - CF 483A: Find any three numbers $(a, b, c)$ in the range $[l, r]$ such that
    $(a, b)$ and $(b, c)$ are coprime but $(a, c)$ are not coprime.

## Bit Manipulation

- Related Problems
  - CF 467B: Given an array of integers and a target value, count the number of
    integers that have at most $k$ different bits from the target value.
