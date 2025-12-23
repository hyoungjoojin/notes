+++
title = "2240"
math = true
+++

# 자두나무

> Level: Gold 4

## Problem

Given an array $A$ of 1s and 0s and an integer $k$, we can move between positions 1 and 0 at maximum $k$ times.
Find the maximum score that can be obtained where if at time $t$ the position $p$ is equal to $A[t]$, we gain a score of 1.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (0ms, 2952KB) \
> Time: $O(n^2)$, Space: $O(n^2)$

We can use a 2D dynamic programming table to compute the maximum score.
