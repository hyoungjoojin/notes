+++
title = "algorithms"
math = true
+++

# Algorithms

- [Brute Force](./brute-force)
- [Stack](./stack)
- [Queue](./queue)
- [Deque](./deque)
- [Two Pointers](./two-pointers)
- [Trees](./trees)

## Two Pointers

The goal of the two pointers algorithm is to reduce the search space by skipping cases that
are logically impossible to happen.

Some common patterns to look out for are:

1. We need to iterate an array in two directions.
2. We need to search for pairs in an array.

### Problems

<details>
<summary>
Given a sorted array $A$ and a target $x$, find $i$ and $j$ such that $A[i] + A[j] = x$.
</summary>

```c++
pair<int, int> twoSum(vector<int> &numbers, int target) {
  for (int li = 0, ri = numbers.size(); li < ri;) {
    int sum = numbers[li] + numbers[ri];

    if (sum == target) {
      return {li, ri};
    } else if (sum > target) {
      ri--;
    } else if (sum < target) {
      li++;
    }
  }

  return {-1, -1};
}
```

If $A_i + A_j\lt x$ and we move the left pointer to the right, then we are skipping through
the cases where the first index is $i$. But, since $A_i + A_k \lt A_i + A_j \lt x (k\lt j)$ the cases
where the first index is $i$ can never be the solution. The same logic applies when $A_i + A_j\gt x$.

#### Related Problems

- Leetcode 167

</details>

<details>
<summary>
Given a sorted array $A$ and a target $x$, find all distinct triplets $(i, j, k)$ such that
$A[i] + A[j] + A[k] = x$.
</summary>

```c++
vector<array<int, 3>> threeSum(vector<int> &numbers, int target) {
  vector<array<int, 3>> result;

  for (int i = 0; i < numbers.size() - 2; i++) {
    if (numbers[i] > target) {
      break;
    }

    if (i > 0 && numbers[i] == numbers[i - 1]) {
      continue;
    }

    for (int li = i + 1, ri = numbers.size() - 1; li < ri;) {
      int sum = numbers[i] + numbers[li] + numbers[ri];

      if (sum == target) {
        result.push_back({i, li, ri});

        li++;
        ri--;

        while (li < ri && nums[li] == nums[li - 1]) {
          li++;
        }
      } else if (sum < target) {
        li++;
      } else if (sum > target) {
        ri--;
      }
    }
  }

  return result;
}
```

Using two pointers, we can find two integers that sum up to a target number in linear time.
Computing the three sum problem works by reducing the complete search space of $O(n^3)$ to
$O(n^2)$ by fixing one point and using two pointers to find the other two points.

To remove duplicates, we can iterate each pointer for duplicate elements.

#### Related Problems

- Leetcode 15

</details>

<details>
<summary>
Given an array $A$, find the value of $\max{((j - i)\min{(A[i],A[j])})}$.
</summary>

```c++
int maximum(vector<int> &numbers) {
  int result = 0;

  for (int li = 0, ri = numbers.size() - 1; li < ri;) {
    if (numbers[li] < numbers[ri]) {
      result = max(result, (ri - li) * numbers[li]);
      li++;
    } else {
      result = max(result, (ri - li) * numbers[ri]);
      ri--;
    }
  }

  return result;
}
```

The brute force method to compute this would be to go through all $n^2$ cases.
Let $A[i]\lt A[j]$ and $k$ be an integer in range $(i,j)$.
Then since $(k - i) \min{(A[i], A[k])}\lt (j - i)\min{(A[i], A[j])}$, we can
skip through the cases $(i, k)$ if $A[i]\lt A[j]$. The same logic applies to
the opposite case, hence the algorithm moves the pointer from the smaller side one step
on each iteration making an $O(n)$ time complexity.

#### Related Problems

- Leetcode 11

</details>

## Binary Search

Binary search is a search algorithm that reduces the search space logarithmically by
skipping through half of the search space in each iteration.

<details>
<summary>
Given an array $A$ and an integer $h$, find the minimum value of $k$ where
$\sum_{i}{\lceil \frac{A[i]}{k} \rceil}\leq h$ holds.
</summary>

```c++
int minValueOfK(vector<int> &a, int h) {
  int result = numeric_limits<int>::max();

  for (int low = 0, high = *max_element(a.begin(), a.end()); low <= high;) {
    int mid = (low + high) / 2;

    int count = 0;
    for (int x : a) {
      count += ((x / mid) + (x % mid == 0 ? 0 : 1));
    }

    if (count > h) {
      low = mid + 1;
    } else {
      result = min(result, mid);
      high = mid - 1;
    }
  }

  return result;
}
```

We apply binary search on the value $k$ since the search space of $k$ will be bounded by the
maximum value of $A$ and the cost of computing $\sum_{i}{\lceil \frac{A[i]}{k} \rceil}$ is
not that big.

#### Related Problems

- Leetcode 875

# Graph

## Depth-First Search (DFS)

Depth-first search (DFS) is a graph traversal algorithm that visits vertices by exploring as far as possible along each branch
before backtracking.

**Problems**

- Given a graph, find the order of nodes visited in a DFS traversal starting from a given node.
  - [ ] Baekjoon 24479 (Silver 2): Nodes are visited in ascending order.

## Breadth-First Search (BFS)

### BFS on Grids

While not strictly a graph, since grids can be represented as graphs where each cell is a node and edges exist between adjacent
cells, BFS can be applied to grids in the same way as graphs.
This can be useful for solving problems such as finding the shortest path in a maze or counting the number of connected
components in a grid.

**Problems**

- Given a grid of 0s and 1s, find the number of connected components of 1s.
  - [ ] Baekjoon 1012 (Silver 2): Cells are connected if they are adjacent horizontally or vertically.


# Tree

Trees are connected acyclic graphs.

## Tree Traversal

Tree traversal refers to the process of visiting all the nodes in a tree data structure in a specific order.
The following are examples of common tree traversal methods.

- Depth-First Search (DFS)
- Breadth-First Search (BFS)
- In-order Traversal
- Pre-order Traversal
- Post-order Traversal
- Level-order Traversal

**Problems**

- Given a preorder traversal and an inorder traversal of a binary tree, output the postorder traversal of the tree.
  - [ ] Baekjoon 4256 (Gold 2)

