+++
title = "5525"
math = true
+++

# IOIOI

> Level: Silver 1

## Problem

Let $P_n$ be a string of length $2n+1$ consisting of alternating 0s and 1s starting with 1.
Given a string $S$, find the number of occurrences of $P_n$ as a substring of $S$.

## Solution

### Pattern Matching

> Implementation: [C++](./src/a.cpp) (12ms, 3000KB) \
> Time: $O(n)$, Space: $O(1)$

We can extract the longest substring of $S$ that matches the pattern $P_n$ in a linear scan.
