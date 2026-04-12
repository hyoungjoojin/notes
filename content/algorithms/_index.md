+++
title = "algorithms"
+++

# Algorithms

## Data Structures

### Search Trees

#### Terminology

- Fanout: The number of keys stored in each node.

#### Binary Search Tree

A binary search tree is a binary tree data structure that maintains the property
that for any given node, all values in the left subtree are less than the node's
value and all values in the right subtree are greater than the node's value.

#### Paged Binary Tree

Since elements can be added in random order, a binary search tree can be stored
across multiple disk pages. Paged binary trees store multiple nodes on a single
disk page to improve read performance.

- [B-Tree](./btree)

## String Algorithms

### Suffix Array

The suffix array of a string $s$ is an array constructed from $s$, where the
$i$-th element of the suffix array is the starting index of the $i$-th
lexicographically smallest suffix of $s$.
