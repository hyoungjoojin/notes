+++
title = "3896"
+++

# 소수 사이 수열

> Level: Silver 1

## Problem

Given an integer $k$, find the difference between $p_1$ and $p_2$ where $p_1$ is the largest prime number less than or equal to
$k$ and $p_2$ is the smallest prime number greater than or equal to $k$.

## Solution

### Erathosthenes Sieve + Binary Search

> Implementation: [C++](./src/a.cpp) (8ms, 3076KB) \
> Time: $O(n\log n)$, Space: $O(\log \log n)$
