+++
title = "1966"
math = true
+++

# 프린터 큐

> Level: Silver 3

## Problem

Given a queue $A$, we pop $\text{front}(A)$ of $A$ if no other element in $A$ is larger than
$\text{front}(A)$. If there is a larger element, then we push the front of $A$ and pop the front.
Given an index $i$, find the order in which $A_i$ is removed from $A$.

## Solution

### Queue

> Implementation: [C++](./src/a.cpp) (0ms, 2024KB)

Maintain separate buckets for each priority value, and empty each buck from the highest priority to the lowest.
