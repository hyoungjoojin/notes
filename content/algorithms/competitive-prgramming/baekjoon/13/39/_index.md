+++
title = "1339"
+++

# 단어 수학

> Level: Gold 4

## Problem

Given a list of words composed of characters A to Z, find the maximum sum of the words when each character is replaced by a
unique digit from 0 to 9. Each word represents a number formed by the digits assigned to its characters.

## Solution

### Greedy

> Implementation: [C++](./src/a.cpp) (0ms, 2024KB) \
> Time: $O(n)$, Space: $O(n)$

We can take the sum of values for each character based on its position, then assign the largest digits to the characters
with the highest values.
