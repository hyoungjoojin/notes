+++
title = "dsu"
math = true
+++

# Disjoint Set Union

A disjoint set union is a data structure that can be used for efficient union-find operations on disjoint sets.

## Union Find

Union find is a set of operations made to disjoint sets. Disjoint sets are sets of elements where each set is
disjoint from each other.

The operations of union find are as below.

- $\text{union}(x, y)$: Merge the sets $X$ and $Y$, where $x\in X$ and $y\in Y$.
- $\text{find}(x)$: Find the set $X$ where $x\in X$.

## Implementation

> [C++ Implementation](./src/a.cpp)

Disjoint set unions represent sets as trees, where each set is represented by a tree.
The root of the tree is the representative element of the set.

Since only the union and find operations have to be supported, only keeping track of the parent
node for each element is enough. This can be used to compactly represent the set of trees by
maintaining only a parent array where each array element stores the index to its parent node.
The representative element stores its index.

The union operation can merge sets by having one tree be the child of the other's root. The find
operation can operate by finding the root of a given set.

```c++
void union(int x, int y) {
    x = find(x);
    y = find(y);

    if(x != y) {
        parent[x] = y;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }

    return find(parent[x]);
}
```

This method takes $O(n)$ time (due to imbalanced trees) and $O(n)$ space.

### Optimizations

#### Path Compression

Since there are no limits to how many children a node can have, each element encountered while
traversing to the root of the tree can be compressed into a direct child of the root of the tree.

```c++
int find(int x) {
    if(x == parent[x]) {
        return x;
    }

    return parent[x] = find(parent[x]);
}
```

This results in the time complexity to be reduced to $O(\log n)$.

#### Union by Rank

The union operation can be optimized by taking consideration into how the trees should be merged.
By using heuristics like the tree's size or tree's depth, we can union sets in a more efficient way.

```c++
void union(int x, int y) {
    x = find(x);
    y = find(y);

    if(x != y) {
        if(size[x] > size[y]) {
            swap(x, y);
        }

        parent[x] = y;
        size[b] += size[a];
    }
}
```

Combined with path compression, the time complexity gets reduced to near constant time.
