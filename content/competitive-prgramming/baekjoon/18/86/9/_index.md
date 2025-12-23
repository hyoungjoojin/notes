+++
title = "18869"
math = true
+++

# 멀티버스 ⅡI

> Level: Gold 5

## Problem

Given $n$ arrays, find the number of distinct pairs of arrays $(A, B)$ where the ordering of the elements in $A$ and $B$
are identical.

## Solution

### Sorting + Hash Table

> Implementation: [C++](./src/a.cpp) (400ms, 31480KB) \
> Time: $O(n)$, Space: $O(1)$

We can get the ordering of each input array by sorting a copy of it and then using a hash table.
The result can be computed by going through every pair to see if the two arrays are identical.
