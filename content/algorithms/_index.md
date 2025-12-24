+++
title = "algorithms"
+++

# Algorithms

## Competitive Programming

Competitive programming is the act of solving well-defined hypothetical algorithmic problems with constrained inputs
within a limited resource bound.
Even though competitive programming is related to algorithms, it doesn't require knowledge of a wide variety of
algorithms or the ability to invent entirely new algorithms.
Instead, there are patterns in which problems are solved and the skill lies in recognizing these patterns quickly.

I have separated competitive programming into a separate section since the small quirks and tricks that are
used in competitive programming problems are hard to generalize and I also wanted to make a list that associates
algorithms with competitive programming problems.

[This page](./competitive-prgramming/algorithms) contains a list of algorithms commonly used in competitive programming
and problems related to each algorithm.
All problems present in that page will have my own solution code available, which can be found by indexing into one
of the following problem sets using the problem ID.

- [Baekjoon Online Judge](./competitive-prgramming/baekjoon)

## Page Replacement Algorithms

Page replacement algorithms are used in cache eviction, virtual memory, database buffer pools.
These are used when we have a limited amount of cache storage, where at some point we need to
evict some data and replace it with another piece of data. The choice of a page replacement
algorithm depends on how efficient it should run and what data the algorithm can be utilize.

- LRU
- Clock Sweep
- [LRU-K](./lru-k)
- ARC (Adaptive Replacement Cache)
