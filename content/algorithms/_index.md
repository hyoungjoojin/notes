+++
title = "algorithms"
+++

# Algorithms

## Page Replacement Algorithms

Page replacement algorithms are used in cache eviction, virtual memory, database buffer pools.
These are used when we have a limited amount of cache storage, where at some point we need to
evict some data and replace it with another piece of data. The choice of a page replacement
algorithm depends on how efficient it should run and what data the algorithm can be utilize.

- LRU
- Clock Sweep
- [LRU-K](./lru-k)
- ARC (Adaptive Replacement Cache)
