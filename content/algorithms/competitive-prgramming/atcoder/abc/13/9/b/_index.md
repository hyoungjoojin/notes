+++
title = "abc139-b"
math = true
+++

# Power Socket

## Problem

Given a power socket with 1 port and power lines with $a$ ports, find the minimum number of
power lines to make $b$ ports.

## Solution

### Brute Force

> Implementation: [C++](./src/a.cpp) (1ms, 3629KB) \
> Time: $O(n)$, Space: $O(1)$

Except for the last power line added (which adds $a$ ports), each power line adds $a - 1$ ports.
