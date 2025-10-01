+++
title = "stack"
math = true
+++

# Stack

## Postfix Expressions

<details>
<summary>
Given a postfix expression, compute the expression.
</summary>

### Related Problems

- Baekjoon 1935: The postfix expression is represented with variables that are separately given (ex. `ABC*+DE/-`).

</details>

## Parentheses Problems

<details>
<summary>
Given a string $s$ composed of parentheses ('()', '[]', '{}'), determine if $s$ forms
a valid expression.
</summary>

### Related Problems

- Baekjoon 9012: $s[i]\in\lbrace (, ) \rbrace$.

</details>

<details>
<summary>
Given a string $s$ composed of parentheses ('()', '[]', '{}') and a function $f$, compute $f(s)$.
</summary>

### Related Problems

- Baekjoon 10799: $f(x)$ is constructed by a given set of rules.

</details>

## Monotonic Stack

A monotonic stack is a stack where the elements are monotonically increasing or decreasing. This
can be constructed by iteratively popping all elements that are smaller or larger than the
current element.

<details>
<summary>
We are given the heights of $N$ towers. Each tower can only see towers that are higher then theirs.
If a tower sitting between two towers is higher than both towers, then the two towers can't see
each other. Count the number of towers that can be seen from each tower.
</summary>

### Related Problems

- Baekjoon 22866: Count the number of towers that can be seen from both left and right. Also, find
  the index to the closest tower that can be seen.

</details>
