+++
title = "11049"
math = true
+++

# 행렬 곱셈 순서

> Level: Gold 3 \

## Problem

Given an array of pairs $(r_i, c_i)$, each pair $(r_i, c_i)$ represents the dimensions of array $A_i$.
Assume the input is given so that $A_1 A_2 \cdots A_n$ can be computed. Find the minimum number of
multiplications required to compute $A_1 A_2 \cdots A_n$ (the number of multiplications required
to compute $A_i A_j$ is $r_i c_i c_j$).

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (152ms, 3084KB) \
> Time: $O(n^2)$, Space: $O(n^2)$
