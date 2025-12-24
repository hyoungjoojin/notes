+++
title = "1963"
+++

# 소수 경로

> Level: Gold 4

## Problem

Given two prime numbers $p$ and $q$, find the minimum number of steps to convert $p$ to $q$ by changing one digit at a time,
and that each intermediate number is also a prime number.

## Solution

### BFS

> Implementation: [C++](./src/a.cpp) (0ms, 2196KB) \
> Time: $O(n)$, Space: $O(n)$

Start by filtering out all the prime numbers using Eratosthenes' sieve.
Then, we can use BFS to go to the next number by subtracting and adding each digit.
