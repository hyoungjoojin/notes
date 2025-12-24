+++
title = "2346"
+++

# 풍선 터뜨리기

> Level: Silver 3

## Problem

We are given $N$ cards where each card has an integer value. We do the following until all the cards are removed.

- We remove the card on the top of the deck. If the value on the removed card $x$ is positive we iteratively take
  one card from the top and put it in the back for $x$ iterations. We do the opposite if $x$ is negative.

## Solution

### Deque + Brute Force

> Implementation: [C++](./src/a.cpp) (0ms, 2156KB) \
> Time: $O(n)$, Space: $O(1)$
