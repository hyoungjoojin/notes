+++
title = "691"
math = true
+++

# Hoof, Paper, Scissors

> Level: Silver \

## Problem

Given an array $A$ where each element of $A$ is an element of the set $\lbrace 1, 2, 3\rbrace$,
we select an index $x$ and calculate $c_{:x}^i + c_{x:}^{j}$ where $c_{a:b}^{t}$ denotes
the number of occurrences of $t$ within the range of $[a, b)$ in $A$ and $i\neq j$.

## Solution

### Prefix Sum

> Implementation: [C++](./src/a.cpp) (0ms, 2152KB) \
> Time: $O(n)$, Space: $O(n)$

We maintain 3 separate prefix sum arrays that store the number of occurrences for each element.
