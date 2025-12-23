+++
title = "12904"
math = true
+++

# A와 B

> Level: Gold 5

## Problem

Given two strings $S$ and $T$, determine if $S$ can be transformed into $T$ by either appending `A` to the end of the string
or appending `B` to the end of the string and then reversing the string.

## Solution

### Deque

> Implementation: [C++](./src/a.cpp) (0ms, 2024KB) \
> Time: $O(n)$, Space: $O(n)$

We can use a deque to represent the operations in reverse.
