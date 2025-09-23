+++
title = "11652"
math = true
+++

# 카드

> Level: Silver 4 \

## Problem

Given an array of $N$ integers, find the most frequent element.

## Solution

### Sorting

> Implementation: [C++](./src/a.cpp) (24ms, 2804KB) \
> Time: $O(n\log n)$, Space: $O(1)$

Sort the array, then iterate through the array to find the most frequent element.
