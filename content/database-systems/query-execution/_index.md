+++
title = "query-execution"
+++

# Query Execution

A query plan is given as a DAG of operators.

## Processing Model

The processing model defines how the system is going to execute the query plan and move the data from one operator to another.
The processing model will have two execution paths, one for the control flow and one for the data flow.
The processing model does not define what the output of an operator will look like, it can be the entire tuple or a subset
of the columns.

### Iterator Model

The iterator model (also called the volcano model or pipeline model) works by having each operator request data from its child
operators one tuple at a time.
Here, each operator implements three methods: `open()`, `next()`, and `close()`.
The `open` and `close` methods are like constructors and destructors for the operator.
The `next` method is called by the parent operator to request the next tuple from the child operator, and returns either a
single tuple or a EOF marker.

Implementation of the `next` method depends on the database system.
The database system can eagerly fetch each tuple every single time, or it could prefetch all the tuples into a buffer and return
them one by one.

The iterator model allows for pipelining, where the database system can process a tuple through as much operators as possible
before requesting the next tuple.
Here, a pipeline is a sequence of operators where tuples can continuously flow between them without intermediate storage.
A pipeline breaker is an operator that cannot finish until all children operations are finished.

This model is good for OLTP workloads, since the amount of data processed is small, and the overhead of function calls is
negligible.
However if the amount of data processed is large, the overhead of function calls can add up and become significant.

### Materialization Model

The materialization model passes up all the data from each operator to its parent operator.

The system can send down hints like limit clauses to avoid scanning too many tuples.
Operator fusion can also be applied to reduce the number of intermediate results created.

This model is very inefficient, but could work for OLTP workloads where the amount of data processed is small.
Since this model doesn't work well with large dataset OLTP and OLAP workloads, this model is rarely used, however systems
like MonetDB uses this model.

### Vectorized Model

The vectorized model (also called batch processing model) works by having each operator process a batch of tuples at a time.
It works the same way as the iterator model, but instead of returning a single tuple, the `next` method returns a batch of
tuples.
The size of the batch can vary based on the hardware and query properties.
Each batch can have one or more columns, and each column will have their own null bitmap and data array.
The implementation choices can vary based on the database system.
For example, the batch can either be filled up in the intermediate state or a partially filled batch can be returned.

This model is good for OLAP workloads, where since the amount of data processed is large, the data can be processed using
vectorized instructions and the number of function calls can be reduced.

## Data Flow

In a query plan, data can either be pulled from the child operators or pushed from the child operators.

### Top-to-Bottom Approach

The top-to-bottom approach is the pull-based approach, where the parent operator requests data from the child operators.
Here, the parent blocks until the child operator returns.
This comes at the cost of increased function calls and branching.

### Bottom-to-Top Approach

The bottom-to-top approach is the push-based approach, where the child operator pushes data to the parent operator.
Here, a global scheduler watches over the entire tree of operators and executes them.
This allows for a more tighter control over caches and registers in the pipeline.

This approach is more complex to implement for certain operators like sort-merge joins.
It also may not have exact control over the intermediate result sizes.

OLAP systems like HyPer, Umbra, Snowflake, or DuckDB uses this approach alongside the vectorized model.

## Access Methods

Access methods are how the database system retrieves data from the tables.

### Sequential Scan

Sequential scans are the most straightforward way to read all records in a table.
It sequentially reads each record one by one by reading each page to memory, and iterate over the tuples within each page.
The database system will also maintain an internal cursor to keep track of the last page or slot read.

#### Optimizations

Many optimizations can be applied to sequential scans.

- Data Encoding and Data Compression
- Data Prefetching
- Scan Sharing
- Buffer Bypass
- Task Parallelization
- Multi-Threading
- Clustering and Sorting
- Late Materialization
- Materialized Views
- Result Caching
- Data Skipping
  - Approximate Queries
  - Small Materialized Aggregates
- Data Parallelization
- Vectorization
- Code Specialization and Compilation

**Data Skipping**

Data skipping is a technique where data that are not relevant to the query are skipped during a scan.
Approximate queries are lossy queries that return approximate results, and can be used in queries where exact results are not
necessary.
This is done by sampling a subset of the data to compute approximate results, where the sample rate can be adjusted to fit
the query's accuracy and performance requirements.
Google's BigQuery, Databricks, Redshift, and Snowflake support approximate queries.
Small materialized aggregates (or zone maps) are for lossless queries, where aggregates like the minimum, maximum, sum, or
average are computed per-page.
Then, if a page does not fit the query predicate based on the aggregate values, it can be skipped during the scan.

### Index Scan

Index scans use an index to look up records in a table.
The choice on which index to use is made by the query optimizer.

### Multi-Index Scan

If there are multiple indexes for a query, the database system can compute sets of record IDs for each index, and then
combine them using either a union or intersection.
DB2's Multi-Index Scan, PostgreSQL's Bitmap Scan, and MySQL's Index Merge are examples of this technique.

## Modification Queries

Updates and deletes can use the same access methods as selection queries to find the records to be modified.
However, the Halloween problem can occur when processing updates.
This is when an update changes the physical location of the tuple, making the scan operator visit the tuple
multiple times, which can happen for clustered tables or index scans.
To prevent this, the database system can track the modified record IDs per query, and skip them if they are encountered again.

Inserts are done by either materializing tuples inside the opeartor or inserting tuples from child operators.

## Expression Evaluation

An expression in a query can be represented as a tree of nodes, where each node is either an operator or an operand.
This is called the expression tree, and can be used for `WHERE` clauses, computed columns, or other expressions in a query.
Given an execution context like the table schema, current tuple, or query parameters, the expression can be evaluated by
traversing the expression tree.

Although traversing through the expression tree works, since this has to be done for every tuple in a query, it can be quite
slow.
To optimize this, the expression tree can be compiled into a sequence of instructions that can be executed more efficiently.
For example, PostgreSQL uses a JIT compiler to compile expressions into machine code at runtime.
We can also use vector instructions to evaluate multiple tuples at once.

Constant folding is another optimization technique, where redundant computations are eliminated by pre-computing constant
expressions at compile time.
Common subexpression elimination reuses a previously computed subexpression instead of recomputing it multiple times.
