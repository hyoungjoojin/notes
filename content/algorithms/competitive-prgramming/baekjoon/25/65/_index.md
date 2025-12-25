+++
title = "2565"
+++

# 전깃줄

> Level: Gold 5

## Problem

We are given $n$ pairs of form $(a, b)$, where each pair indicates a connection between point $a$ on the left side and point
$b$ on the right side. Find the minimum number of pairs to remove such that no two remaining pairs cross each other.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (0ms, 2024KB) \
> Time: $O(n\log n)$, Space: $O(n)$

We can sort the pairs by the left component, and then the length of the longest increasing subsequence (LIS) of the right
components will give us the maximum number of non-crossing pairs.
