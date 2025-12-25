+++
title = "12026"
+++

# BOJ 거리

> Level: Silver 1

## Problem

We are given a string of length n consisting of the characters 'A', 'B', and 'C'. Given that we can jump from left to right
in the order of A, B, C, and that jumping $k$ steps require a cost of $k^2$, find the minimum cost to reach the end of
the string starting from the first character.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (0ms, 2024KB) \
> Time: $O(n^2)$, Space: $O(n)$

We can use dynamic programming to compute the cost to jump to each position by finding the minimum cost to jump from all previous
positions that can jump to the current position.
