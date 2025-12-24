+++
title = "875"
math = true
+++

# Koko Eating Bananas

> Level: Medium \

## Problem

Given an array $A$ and an integer $h$, find the minimum value of $k$ where
$\sum_{i}{\lceil \frac{A[i]}{k} \rceil}\leq h$ holds.

## Solution

### Binary Search

> Implementation: [C++](./src/a.cpp) (15ms, 22.98MB) \
> Time: $O(n\log n)$, Space: $O(1)$
