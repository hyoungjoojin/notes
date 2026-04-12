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

## Storage

### Hard Disk Drives

### Solid State Drives

Solid state drives (SSDs) store data in memory cells. The smallest unit of
storage in an SSD is a page. Changes to data in an SSD can only be made at the
page level, but they can only be written if the page is empty (erased before
write). Erasing in an SSD can only be done at the block level.

The Flash Translation Layer (FTL) is a memory controller responsible for mapping
page IDs to physical memory locations.

SSDs do not have a huge gap between random I/O and sequential I/O like HDDs, but
sequential I/O is still faster than random I/O due to data prefetching or
internal parallelism.
