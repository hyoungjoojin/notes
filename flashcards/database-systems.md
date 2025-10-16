# Database Systems

> 1

What does the buffer manager do in database systems?

--

The buffer manager manages buffers for the database, where a buffer is like a cache for database
pages stored on disk. The buffer manager maintains a buffer pool and a page table. A buffer pool
is an array of frames allocated by the database system to store database pages. A frame is a
region of memory, typically the size of a database page, where the database page can fit in.
The page table is a hash table that keeps track of which database pages are in the buffer pool
and also maintains some additional metadata alongside the buffers.

--

> 1

What is sequential flooding?

--

When using page eviction policies like LRU, which evicts the oldest remaining page first,
the performance degrades due to sequential flooding. Sequential flooding is where a long
sequential scan results in every page being read causing a page eviction due to the least
recently accessed page being evicted.

--

> 6

What are some strategies for optimizing buffer pools?

--

- Buffer Pool Localization
- Buffer Prefetching
- Scan Sharing (Synchronized Scans)

--

> 6

What are the disadvantages of tuple-oriented storage and how does log-structured storage fix this?

What are the disadvantages of log-structured storage?

--

Tuple-oriented storage can lead to fragmented data within a page and can cause unnecessary disk I/O
since accessing a single tuple means the entire page has to be fetched. Also, for systems where
only appends are available, tuple-oriented storage becomes very difficult to implement efficiently.

Log-structured storage maintains a fast in-memory tree-based MemTable and a set of key-value pairs
sorted in order called the SSTables. Log-structured storage is very fast for write-heavy workloads
since writes can be done directly to the MemTable. This structure however causes high write
amplification and slow reads.

--
