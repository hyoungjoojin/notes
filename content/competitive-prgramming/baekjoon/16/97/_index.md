+++
title = "1697"
math = true
+++

# 숨바꼭질

> Level: Silver 1

## Problem

Given a starting index $s$ and a target index $t$ on an infinite number line, and if we can move to either $s-1$, $s+1$,
or $2s$ in each iteration, find the minimum number of iterations required to reach from $s$ to $t$.

## Solution

### BFS

> Implementation: [C++](./src/a.cpp) (0ms, 2544KB) \
> Time: $O(n)$, Space: $O(n)$
