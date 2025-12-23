+++
title = "16401"
math = true
+++

# 과자 나눠주기

> Level: Silver 2

## Problem

Given an array $A$ and an integer $x$, find
$\argmax_{n}\sum_{a\in A}{\lfloor{\frac{a}{n}}\rfloor}\geq x$.

## Solution

### Parametric Search

> Implementation: [C++](./src/a.cpp) (184ms, 5824KB) \
> Time: $O(n\log n)$, Space: $O(1)$
