+++
title = "stack"
math = true
+++

# Stack

## Basic STL Usage

<details>
<summary>Baekjoon 10828 (S4): Given a sequence of commands for a stack data structure, simulate the commands.</summary>

## Related Problems

- Baekjoon 18258 (S4): Simulate a queue data structure.
- Baekjoon 10845 (S4): Simulate a queue data structure.
- Baekjoon 10866 (S4): Simulate a deque data structure.

</details>

## Parentheses Problems

If a problem is related to parentheses or some kind of paired object (like brackets or left-right pairs),
it could be an indicator that stacks can be used to solve that problem.

### Valid Parenthesis String

<details>
<summary>
Baekjoon 9012 (S4): Given a string $s$ composed of parentheses `(` and `)`, determine if $s$ forms
a valid expression.
</summary>

### Related Problems

- Baekjoon 4949 (S4): $s$ is composed of `(`, `)`, `[`, and `]`.
- Baekjoon 3986 (S4): A string can be reduced by $a\epsilon a\rarr \epsilon$. Determine if a string $s$ can
  be reduced to an empty string.
- Baekjoon 22942 (G4): We are given $n$ circles that all have their origins placed on the $x$-axis. Determine
  if there are any interceptions between the circles.
- Baekjoon 2800 (G4): Given a string $s$, find all the strings that can be created by removing at least one
  parenthesis pairs from $s$.

</details>

### Parenthesis Expression Computation

<details>
<summary>
Baekjoon 2504 (G5): The function $f$ is defined on an expression $s$, which is composed of
`(`, `)`, `[`, and `]`. If $f([])=3, f(()) = 2, f(XY) = f(X) + f(Y), f((X)) = 2f(X), f([X]) = 3f(X)$,
compute $f(s)$ for a given string $s$.
</summary>

### Related Problems

- Baekjoon 10799 (S2): Each parentheses pair represents a block, and an adjacent pair represent a laser
  cutting through the block. Find the number of blocks.

</details>

## Computing Arithmetic Expressions

Stacks can be used for computing arithmetic expressions. Prefix expressions and postfix expressions
can be computed right away using stacks, and infix expressions can be converted into postfix
expressions using stacks as well.

<details>
<summary>
Baekjoon 1935 (S3): Given a postfix expression, compute the expression.
</summary>

### Related Problems

</details>

<details>
<summary>
Baekjoon 1918 (G2): Convert an infix expression into a postfix expression.
</summary>

### Related Problems

</details>

## Monotonic Stack

A monotonic stack is a stack where the elements are monotonically increasing or decreasing. This
can be constructed by iteratively popping all elements that are smaller or larger than the
current element.

<details>
<summary>
Baekjoon 2493 (G5): For each element $a_i$ in an array $a$, find the element $a_j$ that is larger
than $a_i$ where $j\lt i$ and $j$ is maximized.
</summary>

### Related Problems

- Baekjoon 1863 (G4): Given a city skyline, find the minimum number of rectangle buildings required to
  make the skyline.
- Baekjoon 22866 (G3): Count the number of towers that can be seen from both left and right. Also, find
  the index to the closest tower that can be seen.

</details>
