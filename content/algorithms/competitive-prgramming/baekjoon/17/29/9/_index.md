+++
title = "17299"
+++

# 오등큰수

> Level: Gold 3

## Problem

Given an array $A$, for each element $A[i]$, find the first element to the right of $A[i]$ that occurs more frequently
than $A[i]$.

## Solution

### Monotonic Stack + Hash Table

> Implementation: [C++](./src/a.cpp) (440ms, 25216KB) \
> Time: $O(n)$, Space: $O(n)$

We can use a hash table to maintain the frequency of each element in the array.
Then, we can use a monotonic stack to find the first element to the right of each element that has a higher frequency.
