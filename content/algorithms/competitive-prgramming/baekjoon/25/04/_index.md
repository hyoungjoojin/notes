+++
title = "2504"
+++

# 괄호의 값

> Level: Gold 5

## Problem

We are given a string composed of characters `'(', ')', '[', ']'`. This string represents an
expression, where the value of the expression is computed using the following rules.

- Adjacent parentheses and brackets each compute to 2 and 3 respectively.
- If $x$ is a valid expression, $(x)$ is computed as $2f(x)$ and $[x]$ is computed as $3f(x)$.
- If $x$ and $y$ are valid expressionss, $xy$ is computed as $f(x) + f(y)$

## Solution

### Stack

> Implementation: [C++](./src/a.cpp) (0ms, 2024KB) \
> Time: $O(n)$, Space: $O(n)$
