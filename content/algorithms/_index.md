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

## Dynamic Programming

### Problems

<details>
<summary>
Count the number of ways to make $n$ by iteratively adding 1 or 2.
</summary>

```c++
int fib(int n) {
  if (n < 3) {
    return n;
  }

  int a = 1, b = 2, result;
  for (int i = 3; i <= n; i++) {
    result = a + b;
    a = b;
    b = result;
  }

  return result;
}
```

Let the number of ways to make $n$ be $f(n)$. Then, since $n$ can be made by $(n - 1) + 1$ or
$(n-2) + 2$, $f(n) = f(n-1) + f(n-2)$.

#### Related Problems

- Leetcode 70

</details>
