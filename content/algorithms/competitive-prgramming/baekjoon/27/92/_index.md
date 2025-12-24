+++
title = "2792"
+++

# 보석 상자

> Level: Silver 1

## Problem

Given an array $A$ and an integer $k$, find the minimum integer $x$ such that
$\sum_{i=1}^{n} \lceil \frac{A_i}{x} \rceil \leq k$.

## Solution

### Parametric Search

> Implementation: [C++](./src/a.cpp) (56ms, 3192KB) \
> Time: $O(\log n)$, Space: $O(1)$
