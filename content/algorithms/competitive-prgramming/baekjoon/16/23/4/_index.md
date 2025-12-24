+++
title = "16234"
+++

# 인구 이동

> Level: Gold 4

## Problem

Given a $N\times N$ grid of numbers, for each iteration we merge connected components by taking the average of their values,
where components are connected if the difference between adjacent cells is between $L$ and $R$ inclusive.
Find the number of iterations until no more merges occur.

## Solution

### BFS

> Implementation: [C++](./src/a.cpp) (152ms, 2156KB) \
> Time: $O(n^3)$, Space: $O(n^2)$
