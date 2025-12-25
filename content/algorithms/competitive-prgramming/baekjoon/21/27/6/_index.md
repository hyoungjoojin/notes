+++
title = "21276"
+++

# 계보 복원가 호석

> Level: Gold 2

## Problem

We are given a list of pairs $(u, v)$, where each pair indicates that $v$ is an ancestor of $u$. Given that these pairs
represent a valid tree, reconstruct the tree.

## Solution

### Topological Sort

> Implementation: [C++](./src/a.cpp) (104ms, 5096KB) \
> Time: $O(V+E)$, Space: $O(V)$
