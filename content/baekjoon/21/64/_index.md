+++
title = "2164"
math = true
+++

# 카드2

> Level: Silver 4

## Problem

Given an array of size $N$ where each element $a_i = i (i\in [1, N])$, we repeatedly
remove the leftmost element and move the next leftmost element to the right end unitl
we are left with one card. Find the number of this last remaining card.

## Solution

### Queue

> Implementation: [C++](./src/a.cpp) (4ms, 4156KB) \
> Time: $O(n)$, Space: $O(1)$
