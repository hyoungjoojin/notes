+++
title = "16987"
+++

# 계란으로 계란치기

> Level: Gold 5

## Problem

We are given $n$ pairs of $(s, w)$. We apply the following operation by iterating from the first pair to the last pair.

1. If the current value of $s$ is non-positive, continue to the next iteration.
2. Select another pair whose current value of $s$ is positive. If there is no such pair, continue to the next iteration.
3. Decrease the current value of $s$ of both selected pairs by the $w$ of the other pair.

Find the maximum number of pairs whose current value of $s$ is non-positive after applying the above operation for all pairs.

## Solution

### Backtracking

> Implementation: [C++](./src/a.cpp) (60ms, 2020KB) \
> Time: $O(n^n)$, Space: $O(n^n)$
