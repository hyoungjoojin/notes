+++
title = "10844"
+++

# 쉬운 계단 수

> Level: Silver 1

## Problem

Find the number of integers of length $n$, such that the digits of each integer differ by 1 from its adjacent digits.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (0ms, 2020KB) \
> Time: $O(n)$, Space: $O(n)$

We can use dynamic programming to memoize $f(n, s)$, where $f(n, s)$ is the number of integers that fit the conditions having
length $n$ and starting with digit $s$.
