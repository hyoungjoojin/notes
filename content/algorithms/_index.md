+++
title = "algorithms"
math = "true"
+++

# Algorithms

## Two Pointers

The goal of the two pointers algorithm is to reduce the search space by skipping cases that
are logically impossible to happen.

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
