+++
title = "1654"
+++

# 랜선 자르기

> Level: Silver 2

## Problem

Given an array $A$ and an integer $x$, find
$\argmax_{n}\sum_{a\in A}{\lfloor{\frac{a}{n}}\rfloor}\geq x$.

## Solution

### Parametric Search

> Implementation: [C++](./src/a.cpp) (4ms, 2180KB) \
> Time: $O(n\log m)$, Space: $O(1)$
