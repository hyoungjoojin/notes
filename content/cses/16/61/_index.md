+++
title = "1661"
math = true
+++

# Subarray Sums II


## Problem

Given an array of integers $A$ and a target integer $x$, find the number of subarrays where the
sum of the subarray is $x$.

## Solution

### Prefix Sum + Hash Table

> Implementation: [C++](./src/a.cpp) (0.17s) \
> Time: $O(n\log n)$, Space: $O(n)$

Let $p$ be the prefix sum array for $A$. Then, the number of subarrays where the sum of the subarray
is $x$ is finding the number of pairs $(i, j)$ where $p_j - p_i = x, i\leq j$. Since $i$ is less than
$j$, we can iterate through $p$ and maintain a hash table where we store the number of times we
have seen each prefix sum value. Then for each iteration we can add the value for
`hash_table.get(p_j - x)`.
