+++
title = "algorithms"
math = "true"
+++

# Algorithms

- [Brute Force](./brute-force)
- [Stack](./stack)
- [Queue](./queue)
- [Two Pointers](./two-pointers)
- [Trees](./trees)

## Stack

<details>
<summary>
Given a string $s$ where $s[i]\in\{ (, ) \}$, find if the parentheses of $s$ are valid.
</summary>

```c++
bool isValid(string &s) {
  stack<int> parens;
  for (char ch : s) {
    if (ch == '(') {
      parens.push(1);
    } else if (ch == ')') {
      if (parens.empty()) {
        return false;
      }

      parens.pop();
    }
  }

  return parens.empty();
}
```

#### Related Problems

- Baekjoon 1158

</details>

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
