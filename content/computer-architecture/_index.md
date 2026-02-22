+++
title = "computer-architecture"
+++

# Computer Architecture

## Instruction Pipelining

Instructions take varying amounts of clock cycles to complete, but processors
can be designed to execute instructions in a pipelined way to make it seem like
instructions are executed in a shorter clock cycle. Pipelining is where a single
instruction is decomposed into multiple stages, and each stage is executed in a
different clock cycle. This makes multiple components of the processor work in
parallel in the same clock cycle, improving the overall performance of the
processor.

## Cache

### Cache Associativity

### Cache Misses

There are four types of cache misses, and they are called the 4Cs.

- Compulsory Misses
  - Misses that occur because the data has never been loaded into the cache
    before.
- Capacity Misses
  - Misses that occur because the cache is too small to hold all the data needed
    by the program.
- Conflict Misses
  - Misses that occur because multiple data blocks map to the same cache
    location, causing them to evict each other.
- Coherence Misses
  - Misses that occur because the data has been modified by another processor or
    an external device.
