+++
title = "1016"
+++

# 제곱 ㄴㄴ 수

> Level: Gold 1

## Problem

Given two integers $a$ and $b$, find the number of integers in the range $[a, b]$ that are not divisible by the square of any
integer greater than 1.

## Solution

### Sieve of Eratosthenes

> Implementation: [C++](./src/a.cpp) (12ms, 2264KB) \
> Time: $O(\sqrt{m} + n)$, Space: $O(n)$

We can use a modified Sieve of Eratosthenes to remove multiples of squares of integers in the range of $[a, b]$.
