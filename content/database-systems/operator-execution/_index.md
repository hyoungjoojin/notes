+++
title = "operator-execution"
+++

# Operator Execution

The query processor compiles SQL into a query plan, which is a tree of operators where the leaves are the relations
involved in the query and the data is moved up the tree by the operators to produce the final result at the root.

## Sorting

Sorting is used in sorting operations (`ORDER BY`), duplicate elimination (`DISTINCT`), aggregations (`GROUP BY`),
and sometimes in bulk loading tuples into indices. If the data can fit in memory, any efficient sorting algorithm can be used.
However, we need to account for the case where the data is too large to fit in memory, in which case we need to consider
I/O costs.

Each sorting algorithm sorts an input list of key-value pairs called runs. The value can be the entire tuple
(early materialization) or just the record ID (late materialization).

### Top-N Heap Sort

If the query asks for the top $N$ results (`ORDER BY` with `LIMIT` and an optional `WITH TIES`), we can use a priority queue
to keep track of the top $N$ results if the $N$ elements fit in memory.

### External Merge Sort

External merge sort is a divide-and-conquer algorithm that writes out intermediate results to disk. It works in the same
way as merge sort, but the intermediate results are written to disk instead of being kept in memory.

External merge sort consists of two phases: the sorting phase and the merging phase. The sorting phase reads chunks of data
that fit in memory, sorts them, and writes them out to disk as sorted runs. The merging phase reads the sorted runs from disk
and merges them together to produce a larger sorted run, until the entire data set is sorted. For example, if we have 1000
pages of data to sort and only 100 pages of memory available, we can read 100 pages at a time, sort them in memory, and write
them out to disk as 10 sorted runs of 100 pages each. Then, we can merge these 10 sorted runs together in multiple passes until
we have a single sorted run of 1000 pages.

In a general external merge sort that uses $B$ buffer pages to sort $N$ pages, there would be
$1 + \lceil \log_{B-1} \lceil N/B \rceil \rceil$ passes (1 initial pass producing $\lceil N/B \rceil$ sorted runs, and
the rest using $B-1$ pages to merge the runs to a buffer page in each pass).

#### Optimizations

- Double Buffering: Prefetch the next run in the background while processing the current run to hide I/O latency.
- Comparison Optimizations
  - Code Specialization: Create a hard-coded comparison function for the specific data types being sorted.
  - Suffix Truncation: For a long key, only compare the binary prefix first. Fallback to full comparison if equal.
  - Key Normalization: Transform the key into a format that is faster to compare (e.g., fixed-length).

### B+Trees

If a B+Tree index exists on the sorting key, we can perform an index scan to retrieve the tuples in sorted order.
However, if the index is not clustered, it may be beneficial to simply sort the tuples instead since there would be a lot
of random I/O (if the query is a top-N query, it might not matter).

## Aggregation

Aggregation operations groups values by a set of keys, and can be implemented by either sorting the tuples or by
using a hash table.

### Sort-Based Aggregation

The database system will sort the tuple based on the grouping keys, and then perform a sequential scan over the
sorted tuples to compute the aggregate values for each group.

### Hash-Based Aggregation

Hash-based aggregation is better than sort-based aggregation if the result doesn't have to be ordered.
For the case when the data does not fit in memory, we can use an external hash aggregation algorithm.
This works in two phases: the partitioning phase and the rehashing phase. In the partitioning phase, we split the
input tuples into partitions by keeping 1 buffer for input and the rest for the partitions, where each buffer is
spilled to disk when full. In the rehasing stage, each partition in disk is read into memory and rehashed into an
in-memory hash table. Here, if a partition is finished processing, we can flush out the in-memory hash table since
the values won't appear again.
