+++
title = "17103"
+++

# 골드바흐 파티션

> Level: Silver 2

## Problem

Given an even integer $n$, find all pairs of prime numbers $(p_1, p_2)$ such that $p_1 + p_2 = n$ and $p_1 \leq p_2$.

## Solution

### Erathosthenes' Sieve + Binary Search

> Implementation: [C++](./src/a.cpp) (100ms, 3040KB) \
> Time: $O(n \log \log n)$, Space: $O(\log \log n)$
