+++
title = "1662"
tags = ["prefix sum"]
math = true
+++

# Subarray Divisibility

> Tags: Prefix Sum

## Problem

Given an array of integers $A$ with size $n$, find the number of pairs $(i, j)$ where the
$\sum_{k=i}^{j}{A_k} \mod n = 0$.

## Solution

### Prefix Sum

> Implementation: [C++](./src/a.cpp) (0.04s) \
> Time: $O(n)$, Space: $O(1)$
