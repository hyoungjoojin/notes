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
$1 + \lceil \log_{B-1} \lceil \frac{N}{B} \rceil \rceil$ passes (1 initial pass producing $\lceil \frac{N}{B} \rceil$
sorted runs, and the rest using $B-1$ pages to merge the runs to a buffer page in each pass).

#### Optimizations

Double buffering is an optimization technique that uses two or more output buffers to hide I/O latency.
While a buffer is being written to disk, the other buffer can be filled with data.

Since sorting involves a lot of record comparisons, we can optimize the comparison operations to improve performance.
Code specialization involves generating a hard-coded comparison function that can be used with specific data types.
Suffix truncation compares only the binary prefix of long keys first, and falls back to full comparison if the prefixes
are equal.
Key normalization transforms the key into a format that is faster to compare.

### B+Trees

If a B+Tree index exists on the sorting key, we can perform an index scan to retrieve the tuples in sorted order.
However, if the index is not clustered, it may be beneficial to simply sort the tuples instead since there would be a lot
of random I/O (if the query is a top-N query, it might not matter).

## Aggregation

Aggregation operations are used in group-by-aggregate (GBA) queries.
Aggregation operations are implemented by either sort-based or hash-based algorithms.
Sort-based algorithms work by sorting the input tuples based on the grouping keys and then grouping the sorted tuples.
Sort-based algorithms are efficient in large datasets but are comutationally expensive due to record comparison.
Hash-based algorithms work by building a hash table based on the grouping keys and then updating the aggregate values.
Hash-based algorithms are more faster but require more memory and can have hash collision problems.

### Sort-Based Aggregation

The database system will sort the tuples based on the grouping keys, and then perform a sequential scan over the
sorted tuples to compute the aggregate values for each group.

### Hash-Based Aggregation

An external hash aggregation algorithm is used when the data does not fit in memory.
External hash aggregation works in two phases: the partitioning phase and the rehashing phase.

In the partitioning phase, the hash value of each input record is computed.
If an aggregate already exists in memory, the record is added to the aggregate.
If the aggregate does not exist and there is enough memory, a new aggregate is created.
If a aggregate exceeds the memory capacity, some partitions are spilled to disk.

In the rehashing phase, each partition in memory and in disk is read and rehashed into an in-memory hash table.
The aggregate value can be updated as the records are read (like a running sum).
