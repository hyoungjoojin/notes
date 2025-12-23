+++
title = "queue"
math = true
+++

# Queue

## Brute Force Simulation

### Josephus Problems

The Josephus problem is where there are $n$ elements in an array, and we eliminate the $k$-th element
in every iteration. If the input size is small, we can directly simulate the Josephus problem using
a queue.

<details>
<summary>Baekjoon 1158 (S4): Given $n$ and $k$, find the Josephus permutation $j_{n, k}$.</summary>

## Related Problems

- Baekjoon 2164 (S4): Given a deck of cards, in each iteration we remove the first card and then move the
  next card to the bottom of the deck. Find the last remaining card.
- Baekjoon 2346 (S3): For each iteration, we eliminate an element at index $x$ and then move $a_k$ steps.
  Find the sequence of eliminated elements.
- Baekjoon 1874 (S2): We can either push or pop elements from a stack. Find the sequence of commands
- Baekjoon 1966 (S3): We pop elements from a queue, but move the element to the back if there is a higher
  priority value in the queue. Find out when a specific element is popped.
- Baekjoon 18115 (S3): Given a deck of cards, we can either remove the first card, the second card, or the
  last card. Given the order of removal and the sequence of commands, find the original order of the
  cards.
- Baekjoon 1021 (S3): Given an array, we can either remove the first element or rotate the array left/right.
  Find the minimum number of rotations required to make a target array.
- Baekjoon 5430 (G5): Given an array, we can either reverse the array or have the first element removed.
  Find the resulting array after applying a sequence of commands.

</details>
