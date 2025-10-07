+++
title = "database-storage"
+++

# Database Storage

## Page Organization

### Slotted Pages

A slotted page is organized into its header, slot array, and tuples. The slot array and the
tuples grow in opposite directions like stacks and heaps, and a slot array's element maps
to a tuple. The header keeps track of the number of used slots and the offset of the starting
location of the last slot used.

## Disk Organization

### Tuple-Oriented Storage

In tuple-oriented storage, finding a tuple is done by first loading the page that has the tuple
into the buffer pool (which is found by consulting the page directory) and then using the slot
array within the slotted page to locate the tuple's offset within the page.

Tuple-oriented storage has the following disadvantages.

- Fragmentation: Tuple deletion can leave gaps within the pages.
- Unnecessary Disk I/O: In order to update a single tuple, the entire block has to be read into memory.
- Random Disk I/O: Since the ordering of tuples are not guaranteed, a sequential scan could fetch
  a separate block for every tuple in the worst case.
- Append-only Systems: Systems like HDFS, Google Colossus, or some objects stores only allow appends
  and does not provide semantices for in-place updates. Tuple-oriented storage makes it hard to work
  with these systems since we would have to delete the entire block and rewrite the block to update
  one single tuple.

### Log-structured Storage

Log-structured storage maintains two data structures, an in-memory MemTable and a set of persistent
SSTables. Log-structured storage provides an API consisting of only put and deletes. In order to get
a record, we search through the MemTable and SSTables to find the most recent operation performed
on that record.

The MemTable is a fast in-memory data structure, which can be implemented using data structures like
B-trees, tries, or skip lists. Once the MemTable is filled up, it is periodically written out to an
SSTable.

SSTables are written to disk with the keys in sorted order. If SSTables get larger than some threshold,
they can be merged together easily since all the keys are sorted and we only take the most recent
updates to a tuple.

SSTables can be placed in multiple levels, where each level below stores a larger and older SSTable.
This is called level compaction. Otherwise, if the SSTables are all placed in one single level, it
is called universal compaction.

Finding tuples would theoretically have to go through every single SSTable in the
worst case, but we can optimize this by using a summary table that tracks additional metadata for
each table and for each level, for example the minimum/maximum keys and Bloom filters.

Log-structured storage is efficient for fast sequential writes on append-only storage,
but reads are slow and write amplification is high.

### Index-organized Storage

In an index-organized storage, each individual page (stored as a slotted page) is organized by
the index. SQLite and MySQL uses index-organized storage, while Oracle and SQL Server provides options
for storing pages as index-organized.
