+++
title = "11057"
math = true
+++

# 오르막 수

> Level: Silver 1 \

## Problem

Find the number of strings where the strings are composed of numeric digits and the digits are
monotonically increasing.

## Solution

### Dynamic Programming

> Implementation: [C++](./src/a.cpp) (0ms, 2020KB) \
> Time: $O(n^2)$, Space: $O(n)$

Let $f(n, i)$ be the number of strings that meet the condition where the length is $n$ and
the last digit is $i$. Then, $f(n, i) = \sum_{x <= i}{f(n-1, x)}$.
