+++
title = "buffer-manager"
+++

# Buffer Manager

## Buffer Manager Data Structures

The buffer manager in a database system is composed of the buffer pool and the page table.
The buffer pool is where the buffers are stored, and the page table is a hash table that
keeps track of the buffers.

### Buffer Pool

The buffer pool is a large array of memory allocated to the database system on start up.
The database system does not heap-allocate any additional memory after constructing the buffer pool.
The buffer pool is organized as an array of fixed-size frames. Each frame has the same size as
a database page, so that when the database system requests a page from disk to the buffer manager
the database page gets copied into a frame entry on the buffer pool.

The buffer pool is handled as a write-back cache, where dirty pages are buffered and not written
to disk immediately.

Buffer pools are not only used for database pages, but also for sorting and join buffers,
query caches, maintenance buffers, log buffers, and dictionary caches.

### Page Table

The page table is a data structure that keeps track of pages in the buffer pool. The page table
is implemented as a fixed-size hash table. Each page table entry keeps track of a dirty flag,
a pin/reference counter, and access tracking information.

In order to prevent other threads copying a page into a frame that is currently being copied into,
latches are used to ensure thread-safe access.

A page table is an in-memory data structure, and it is not required to be durable. However, a page
table can be implemented so that it is durable, in which case the buffers can be preloaded so
that it matches the page table's state on start up.

## Buffer Manager Implementation

### Memory-mapped I/O

Since virtual memory and OS-controlled memory-mapped files can do the same exact thing as
buffer managers, they can be used to implement buffer pools. Systems like Elasticsearch, LevelDB
use memory-mapped I/O and some systems like SQLite give the users the option to use
memory-mapped I/O.

The disadvantages of using memory-mapped I/O for buffer management are as follows.

- The operating system does not have enough information required for efficient buffer management.
- Ensuring transactional safety and correct error handling is difficult when using memory-mapped I/O.

### Buffer Replacement Policies

Buffer replacement policies have to be fast and correct with minimal metadata.

LRU and Clock are policies that evict the oldest accessed page. These algorithms are simple, but
are susceptible to sequential flooding. Sequential flooding is when a sequential scan reads in
every page only once and never again, therefore polluting the buffer pool with unnecessary pages.
For OLAP workloads, MRU (most recently used) is often the best policy to use.

To prevent the sequential flooding problem, the least-frequently used algorithm was proposed.
However, least-frequently used had problems such as high accessed pages never being flushed and
higher overhead for getting the least frequently used item.
The LRU-K algorithm, MySQL's buffer replacement algorithm, and ARC algorithm addresses this.

Besides using a better eviction algorithm, the following methods provide a more efficient
buffer replacement strategy.

- Localization: Each query is given their own part of the buffer pool in which the
  local buffer pool is managed on a per-query basis.
- Priority Hints: The database programmer can provide hints for how important a page is.
  For example, pages like the root of a B-tree should rarely be evicted.

### Flushing Dirty Pages

Dirty pages can be flushed periodically in a page cleaning stage.

### I/O Scheduling

The operating system and hardware may try to reorder and batch I/O requests to maximize
disk bandwidth, but there may be certain requests that have a higher priority than others,
such as background threads having lower priority than others. The database system can use
data that they have to schedule I/O requests.

### OS Page Cache

The operating system maintains a page cache on its own, but since the database system is managing
its own buffer pool, this isn't necessary. We can use direct I/O (`O_DIRECT`) to bypass the OS
page cache.
