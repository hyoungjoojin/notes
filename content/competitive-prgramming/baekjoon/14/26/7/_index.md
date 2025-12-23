+++
title = "14267"
math = true
+++

# 회사 문화 1

> Level: Gold 4

## Problem

We are given a tree $T$ and a set of relations $(a, b, x)$, where the relation indicates that node $a$
will give node $b$ value $x$. Let all nodes that receive a value, pass the value to all of its
children. Find the resulting value of each node.

## Solution

### BFS

> Implementation: [C++](./src/a.cpp) (32ms, 9104KB) \
> Time: $O(n)$, Space: $O(n)$
