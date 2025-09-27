+++
title = "1068"
math = true
+++

# Weird Algorithm

## Problem

Given an integer $a_i$, we define $a_{i+1}$ as $\frac{a_i}{2}$ if $a_i$ is even and
$3a_i + 1$ if $a_i$ is odd.

Given an integer $n$, print this sequence starting from $n$ and ending with $1$.

## Solution

### Brute Force

> Implementation: [C++](./src/a.cpp) \
> Time: $O(n)$, Space: $O(1)$
