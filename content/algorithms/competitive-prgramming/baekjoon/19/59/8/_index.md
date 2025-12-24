+++
title = "19598"
+++

# 최소 회의실 개수

> Level: Gold 5

## Problem

Given $n$ pairs of $(s, e)$ values representing the start and end times of meetings, determine the minimum number of rooms
required to hold all meetings without overlap.

## Solution

### Greedy

> Implementation: [C++](./src/a.cpp) (44ms, 3320KB) \
> Time: $O(n)$, Space: $O(1)$

We can sort the input pairs, and then use a priority queue to pop out the meetings that end before the current meeting starts.
The answer would be the maximum size of the priority queue during the process.
