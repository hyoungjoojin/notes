+++
title = "linear-algebra"
+++

# Linear Algebra

## Vector Norms

The norm of a vector measures the length of a vector.

A norm of a vector $v$, $\lVert v \rVert$, must follow the following properties.

- $\lVert av \rVert = \lvert a \rvert \cdot \lVert v \rVert$
- $\lVert x + y \rVert \leq \lVert x \rVert + \lVert y \rVert$
- $\lVert v \rVert \geq 0 \land (\lVert v \rVert = 0 \iff v = 0)$

### Types of Vector Norms

The Manhattan norm (also known as the L1 norm) is defined as the sum of the
absolute values of the vector components.

The Euclidean norm (also known as the L2 norm) is defined as the square root of
the sum of the squares of the vector components.

## Inner Product

An inner product is a way to multiply two vectors together to get a single
scalar value.

An inner product $\langle \cdot, \cdot \rangle$ must follow the following
properties.

- $\langle ax, y \rangle = a \langle x, y \rangle$
- $\langle x + y, z \rangle = \langle x, z \rangle + \langle y, z \rangle$
- $\langle x, y \rangle = \langle y, x \rangle$
- $\langle x, x \rangle \geq 0 \land (\langle x, x \rangle = 0 \iff x = 0)$

### Dot Product

The dot product is a major example of an inner product.

$$
\langle x, y \rangle = \sum_{i=1}^n x_i y_i
$$

### Symmetric Positive Definite Bilinear Mappings

Inner products can be defined as symmetric positive definite bilinear mappings.

A bilinear mapping maps two vector spaces to a single vector space, and is
linear in each argument separately.

Symmetric bilinear mappings are mappings that follow $f(x, y) = f(y, x)$.
Positive definite bilinear mappings are mappings that follow
$\forall x \neq 0, f(x, x) > 0$ and $f(0, 0) = 0$.

### Inner Product and Vector Norms

Any inner product can be used to define a norm by
$\lVert x \rVert = \sqrt{\langle x, x \rangle}$. This isn't true for the
converse, not all norms can be defined by an inner product (the L1 norm is a
counterexample).

A norm induced by an inner product satisfies the Cauchy-Schwarz inequality.

$$
\lvert \langle x, y \rangle \rvert \leq \lVert x \rVert \lVert y \rVert
$$

### Inner Product of Functions

Functions can also have inner products. This value can be used to measure how
similar two functions are.

$$
\langle f, g \rangle = \int_a^b f(x) g(x) dx
$$

## Vector Distances

The distance $d: V \times V \rarr \R$ between two vectors must satisfy the
following properties.

- $\forall x, y \in V, d(x, y) \geq 0$
- $\forall x, y \in V, d(x, y) = 0 \iff x = y$
- $\forall x, y \in V, d(x, y) = d(y, x)$ (Symmetry)
- $\forall x, y, z \in V, d(x, z) \leq d(x, y) + d(y, z)$ (Triangle inequality)

## Vector Angles

From the Cauchy-Schwarz inequality, we can derive the following for vectors $x$
and $y$.

$$
-1 \leq \frac{\langle x, y \rangle}{\lVert x \rVert \lVert y \rVert} \leq 1
$$

From this, we can define an angle $\theta$ between $x$ and $y$ such that the
following holds.

$$
\cos \theta = \frac{\langle x, y \rangle}{\lVert x \rVert \lVert y \rVert}
$$

Also, two vectors are orthogonal ($x \perp y$) if and only if
$\langle x, y \rangle = 0$.
