+++
title = "1074"
tags = ["recursion"]
math = true
+++

# Z

> Level: Gold 5 \
> Tags: Recursion

## Problem

Given a square grid of size $2^n\times 2^n$, we traverse through the grid such that we visit
the quadrants in the order of top-left, top-right, bottom-left, bottom-right recursively.
Given the row index $r$ and column index $c$, compute the order of access for this element.

## Solution

### Recursion

> Implementation: [C++](./src/a.cpp) (0ms, 2020KB) \
> Time: $O(n)$
