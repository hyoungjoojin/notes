+++
title = "abstract-algebra"
heading = "Abstract Algebra"
+++

## Groups

A set of elements $G$ and a binary operation $\cdot : G \times G \rarr G$ is
called a group if it satisfies the following properties.

- Associativity:
  $\forall a, b, c \in G, (a \cdot b) \cdot c = a \cdot (b \cdot c)$
- Identity Element:
  $\exists e \in G ~ \forall a \in G, e \cdot a = a \cdot e = a$
- Inverse Element:
  $\forall a \in G, \exists a^{-1} \in G, a \cdot a^{-1} = a^{-1} \cdot a = e$

A group $G$ is called an Abelian group (or a commutative group) if it also
satisfies the following property.

- Commutativity: $\forall a, b \in G, a \cdot b = b \cdot a$

## Fields

A set of elements $F$ and two binary operations $+ , \cdot : F\times F \rarr F$
is called a field if it satisfies the following properties.

- $(F, +)$ is an Abelian group with an identity element $0$.
- $(F \setminus \lbrace 0 \rbrace, \cdot)$ is an Abelian group with an identity
  element $1$.
- Distributivity:
  $\forall a, b, c \in F, a \cdot (b + c) = (a \cdot b) + (a \cdot c)$
