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

## Join

Join operations are used to combine tuples from two relations based on a join condition.

Although there are many variations of join operations, the most commmon algorithm is based on a binary inner equi-join operation.
This algorithm can be modified to support other join operations.
Multi-way joins, which joins more than two relations at a time, are typically hard to implement efficiently and therefore not
commonly used in practice.
There are algorithms like the worst-case optimal join that can perform multi-way joins efficiently in some cases,

Cross products are rarely used in practice, but even if they are used, they have no optimized algorithm since they are simply
a nested loop over both relations.

In general, join algorithms will place the smaller table to be the left table for efficiency.
This is done by the query optimizer by using statistics about the tables.

The output of a join operation can depend on whether we do early or late materialization.
When using early materialization, the output will be the concatenation of the tuples of both input relations.
This prevents the need to go to the base table to fetch the full tuples, but requires more memory.
When using late materialization, the output will be the record IDs that match the join condition.
This prevents the need to copy unnecessary data, but requires going to the base table to fetch the full tuples later.

For cost analysis, the number of I/O operations, computation costs, network costs (for distributed databases), and output size
can be considered as metrics.
Here, only the number of I/O operations will be considered.
The number of I/O operations will be measured based on the join of two relations $R$ and $S$, and we set $R$ to have $M$ pages
with $m$ tuples and $S$ to have $N$ pages with $n$ tuples.

### Nested Loop Join

The nested loop join algorithm is a simple nested loop over both relations.
We go through each tuple in the left relation, and for each tuple, we go through each tuple in the right relation
to check if the join condition is satisfied.
If the join condition is satisfied, we push the joined tuple to the output result.

A naive implementation would be to read one tuple from the left relation and then scan the entire right relation for each tuple.
This algorithm is highly inefficient since there are a lot of I/O operations ($M + mN$).

```python
def naive_nested_loop_join(R, S, join_condition):
    result = []
    for r in R:
        for s in S:
            if join_condition(r, s):
                result.append((r, s))
    return result
```

A block nested loop join algorithm improves the naive implementation by reading a block of tuples from the left relation
into memory, and then scanning the entire right relation for each block.
The resulting I/O operations is reduced to $M + MN$.
If we have $B$ buffer pages available, we can read $B-2$ pages from the outer relation into memory, and use 1 page for reading
from the inner relation and 1 page for output.
Then, the algorithm will use $B-2$ buffers in the outer loop, making the number of I/O operations to
$M + \lceil \frac{M}{B-2}\rceil N$.
If the outer relation fits in memory, this will be $M + N$.
We prioritize placing the outer relation in memory first since it is going to be smaller.

```python
def block_nested_loop_join(R, S, join_condition):
    result = []

    for r_block in R.get_blocks():
        for s_block in S.get_blocks():
            for r in r_block:
                for s in s_block:
                    if join_condition(r, s):
                        result.append((r, s))
    return result
```

If a index is defined for the tuples in the inner relation, an index nested loop join can be used.
The I/O cost of this algorithm is $M + mC$, where $C$ is the cost of looking up a tuple in the index.
Some systems like SQL Server will use this algorithm by building the index while processing even if there is no index defined.

```python
def index_nested_loop_join(R, S_index, join_condition):
    result = []

    for r in R:
        matching_s = S_index.lookup(r)
        for s in matching_s:
            if join_condition(r, s):
                result.append((r, s))
    return result
```

### Sort-Merge Join

Hash joins are typically faster than sort-merge joins, but sort-merge joins can be more efficient
when the input relations are already sorted on the join keys, or when the output needs to be sorted.
Sort-merge joins work in two phases, the sorting phase and the merging phase.

The sorting phase works with any sorting algorithm, and is typically done using external merge sort.
The merging phase steps through the sorted tables with cursors and outputs the joined tuples when the join
condition is satisfied.

The I/O cost for this algorithm would be the sum of the cost of the sorting phase
($2M(1 + \lceil \log_{B-1} \lceil \frac{M}{B} \rceil \rceil) + 2N(1 + \lceil \log_{B-1} \lceil \frac{N}{B} \rceil \rceil)$)
and the merging phase ($M + N$).

```python
def sort_merge_join(R, S, join_condition):
    R_sorted = sort(R)
    S_sorted = sort(S)

    result = []
    r_cursor = 0
    s_cursor = 0
    last_value = None

    while r_cursor < len(R_sorted) and s_cursor < len(S_sorted):
        r = R_sorted[r_cursor]
        s = S_sorted[s_cursor]

        if r > s:
            s_cursor += 1
        elif r < s:
            r_cursor += 1
            if R_sorted[r_cursor] == last_value:
                s_cursor -= 1
        else:
            result.append((r, s))
            last_value = s
            r_cursor += 1

    return result
```

### Hash Join

A hash join algorithm uses the fact that the matching tuples will have the same hash value for the join keys.
A simple hash join algorithm works in two phases: the build phase and the probe phase.
In the build phase, we iterate through the outer table to build a hash table in memory based on the join keys.
In the probe phase, we iterate through the inner table and compute the hash value for each tuple to look up matching tuples.

One optimization for cases when the join condition selects only a small portion of the inner table is to use a bloom filter.
This sideways information passing technique builds a bloom filter in the build phase, and the probe phase first checks the
bloom filter before looking up the hash table.

For large relations, the hash table may not fit in memory.
In these cases, we can use a partitioned hash join algorithm (or GRACE hash joins).
The partitioned hash join algorithm works in two phases: the partitioning phase and the probing phase.
In the partitioning phase, the input tuple gets partitioned into buckets based on the hash value of the join keys.
This is done for both relations, and the partitions are written to disk if they do not fit in memory.
In the probing phase, each partition is read from disk and an in-memory hash table is built for one partition so that the
other partition can be probed against it.

If each partition does not fit in memory, we use a recursive partitioned hash join algorithm.
Here, the overflowed partitions are partitioned again using a different hash function until the partitions fit in memory.

The number of I/O operations for the partitioned hash join algorithm is $3(M + N)$, where the partition phase uses $2(M+N)$
operations and the probing phase uses $M+N$ operations.

One optimization for data that gets skewed into a few partitions is to use a hybrid hash join algorithm.
Here, the database system will keep one partition in memory during the partitioning phase if it detects that a lot of the
data is going into that partition.
All other partitions are spilled to disk as usual.
Then, the in-memory partition can be joined using an in-memory join algorithm such as the nested loop join.
