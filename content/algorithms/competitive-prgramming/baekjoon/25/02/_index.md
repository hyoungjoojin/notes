+++
title = "2502"
+++

# 떡 먹는 호랑이

> Level: Silver 1

## Problem

Given two initial values $f(0)$ and $f(1)$, $f(n), (n\geq 2)$ is defined as $f(n) = f(n-1) + f(n-2)$.
Given $n$ and $f(n)$, find any possible pair of integers $f(0)$ and $f(1)$.

## Solution

### Dynamic Programming + Brute Force

> Implementation: [C++](./src/a.cpp) (0ms, 2020KB) \
> Time: $O(n)$, Space: $O(1)$

We can use dynamic programming to calculate $x$ and $y$ for $f(n) = f(0)x + f(1)y$.
Then, we can brute force all possible values of $f(0)$ and check if $f(1)$ is an integer.
