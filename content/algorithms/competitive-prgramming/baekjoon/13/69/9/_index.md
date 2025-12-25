+++
title = "13699"
+++

# 점화식

> Level: Silver 4

## Problem

$t(n) = \sum_{i=0}^{n-1} t(i) \times t(n-1-i)$ with base case $t(0) = 1$. Given $n$, find $t(n)$.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (0ms, 2020KB) \
> Time: $O(n)$, Space: $O(n)$
