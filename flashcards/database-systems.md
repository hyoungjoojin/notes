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

> 9

What are some algorithms for implementing sorting in database systems?

--

- In-memory Sorting: If the data fits in memory, we can use any in-memory sorting algorithm.
- Top-N Heap Sort: If the result set is small (typically for limit clauses), we can use a priority queue to store only the top N
  elements.
- External Merge Sort: If the data does not fit in memory, external merge sort can be used. External merge sort works in two
  phases. The sorting phase, which sorts the data in page-sized chunks and then writing them to disk and the merging phase, which
  merges the pages by using $B-1$ input buffers and 1 output buffer to merge the sorted runs.
- B+Tree Index Scan: If a clustered index exists on the sorting key, we can perform an index scan to retrieve the tuples in
  sorted order.

--

> 9

How can we optimize external merge sort?

--

External merge sort can be optimized in the following ways.

- Double Buffering
- Comparison Operation Optimization
  - Code Specialization
  - Suffix Truncation
  - Key Normalization

--

> 9

What are the algorithms for implementing aggregation in database systems?

--

- Sort-based aggregation: The database system sorts the input tuples by the grouping keys, then scans the sorted tuples to
  compute aggregates for each group. This is efficient for large datasets but computationally expensive due to record
  comparisons.
- Hash-based aggregation: The database system builds a hash table on the grouping keys and updates aggregate values as tuples
  are processed. Faster but requires more memory and can have hash collision problems.

--
