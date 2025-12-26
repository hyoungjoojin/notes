+++
title = "3184"
+++

# 양

> Level: Silver 1

## Problem

Given a grid of elements in the set $\lbrace 0, 1, o, v \rbrace$, the grid is separated by 1s.
For each separated area, count the number of $o$s and $v$s where within each area if the number of $o$s is greater than the
number of $v$s, all $v$s are removed, otherwise all $o$s are removed.

## Solution

### BFS

> Implementation: [C++](./src/a.cpp) (0ms, 2160KB) \
> Time: $O(nm)$, Space: $O(nm)$
