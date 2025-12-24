+++
title = "16139"
+++

# 인간-컴퓨터 상호작용

> Level: Silver 1

## Problem

Given a string $s$, and $q$ queries of form $(c, s, e)$, answer each query with the number of occurrences of character $c$
in the substring $s[s:e]$.

## Solution

### Prefix Sum

> Implementation: [C++](./src/a.cpp) (84ms, 23568KB) \
> Time: $O(n)$, Space: $O(n)$
