+++
title = "4256"
+++

# 트리

> Level: Gold 2

## Problem

Given a preorder traversal and an inorder traversal of a binary tree, output the postorder traversal of the tree.

## Solution

### Recursion

> Implementation: [C++](./src/a.cpp) (16ms, 2152KB) \
> Time: $O(V^2)$, Space: $O(V)$

We can use a recursive algorithm to construct the postorder traversal by setting the root node and recursively processing
the left and right subtrees.
The time complexity is $O(V^2)$ because we need to search for the root node in the inorder traversal to find the length
of the left subtree, making the time complexity $T(V) = O(V) + T(V-1), T(V) = O(V^2)$.
