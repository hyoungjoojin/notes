+++
title = "b-tree"
+++

# B-Tree

A B-tree is a balanced tree data structure that is mainly used in database
systems. While other balanced binary search trees can work well on in-memory
systems, they are not suitable for disk-based systems due to the low fanout.
B-trees have a high fanout and low height, making data retrieval possible with
fewer disk accesses.

## B-Tree Properties

A B-tree node can have $N$ keys and $N + 1$ pointers to child nodes. The keys
are stored in sorted order. Although it isn't mandatory, a single B-tree node is
usually designed to fit within a single disk page.

A B-tree must remain balanced, meaning that all leaf nodes must be at the same
depth within the tree.

A non-root B-tree node must have at least $\lfloor N/2 \rfloor$ keys if the
degree of the B-tree is $N$.

## B-Tree Operations

### Search

Searching within a B-tree can be done in a similar way to searching within a
binary search tree. Since the keys are stored in sorted order and pointers to
child nodes are stored between the keys, we can determine which child node to
follow by comparing the search key with the keys in the current node using
binary search.

Range search queries can be performed by following sibling pointers until the
end of the range is reached.

The time complexity of searching within a B-tree is $O(\lg N)$, where $N$ is the
number of elements in the B-tree. There will be $O(\log_{K}{N})$ pages to read,
where $K$ is the number of keys stored in each node.

### Insertion

Finding the node to insert a new key into is the same as searching for the key.
If the node has space for the new key, we can simply insert it into the node
while maintaining the sorted order.

If the node is full, we have to split the node. The overflowed node is split
into two nodes, where the middle key is pushed up to the parent node and keys to
the left of the middle key are stored in the left node and keys to the right of
the middle key are stored in the right node. This process is done recursively
until the nodes are no longer full, since the parent node can be overflowed by
the middle key being pushed up from the child node.

### Deletion

Finding the node to delete a key from is the same as searching for the key.

Removing a key from a node can lead to a node having fewer keys than the minimum
required. In this case, we can take a key from a sibling node. For example, if
we decide to take a key from the right sibling, the leftmost key from the right
sibling is pushed up to the parent node to act as a separator and the separator
key from the parent node is pushed down to the current node.

In the case where there are no sibling nodes with enough keys, we can merge the
current node with a sibling node by merging the sibling node, the separator key
from the parent node, and the current node into a single node. In the case where
this leads to the parent having too few keys, we then recursively merge the
parent node with its sibling nodes until the tree is balanced again.

If the B-tree stores data in internal nodes as well, we can replace the deleted
key with either the largest key in the left subtree or the smallest key in the
right subtree and then delete the key from the leaf node.

## B-Tree Variants

### B+ Tree

In B+ trees, data is stored only in the leaf nodes and the internal nodes only
act as a guide to the leaf nodes.

### B-Link Tree

In B-link trees, each node has pointers to its sibling nodes.

### Concurrent B-Tree Algorithms
