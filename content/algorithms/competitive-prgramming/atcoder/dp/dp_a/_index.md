+++
title = "frog-1"
tags = ["dynamic programming"]
math = true
+++

# Educational DP Contest A - Frog 1

> Level: A \
> Tags: Dynamic Programming

## Problem

Given an array of integers $A$ of size $N$, find the minimum value of $f(N)$ if the following
recursive relation $f(n) = \min{(f(n-1) + |A_n - A_{n-1}|, f(n-2) + |A_n - A_{n-2}|)}$ holds.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (5ms, 3924KB) \
> Time: $O(n)$, Space: $O(n)$
