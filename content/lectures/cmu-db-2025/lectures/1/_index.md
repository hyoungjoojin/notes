+++
title = "1"
+++

# Lecture 1

> Relational Model and Algebra

## Database Management System

A database is a collection of inter-related data that models some aspect of the real world.

A database management system is software that allows applications to store and analyze information in a database.
Building a proper database management system requires implementation of various features.
The following are some examples of required features in a database management system.

- Efficient data storage and retrieval
- Integrity constraints and consistency guarantees
- Complex relationship modeling with a type system
- Language-agnostic interface with no hard-coded logic
- Support for concurrent database access
- Data duplication and crash recovery

A data model is a high-level collection of concepts for describing the data in the database.
They are the rules that define the relationship between data.
The following are examples of data models.

- Relational Model
- NoSQL: Not an academic term, but refers to non-relational data models
  - Key/Value Model
  - Document Model
  - Graph Model
  - JSON/XML/Object Model
  - Wide-Column/Column-Family Model
- Array (Vector, Matrix, Tensor) Model: Used in ML and scientific computing
- Obsolete/Legacy Models
  - Hierarchical Model
  - Network Model
  - Semantic Model
  - Entity-Relationship Model

A schema is a description of a particular collection of data based on some data model.
It is the structure of the database within a data model.

## Relational Data Model

Early database systems were used by navigating through the internal data structures of the database.
This is a bad idea since the application depends on the internal implementation of the database and the database cannot make
meaningful optimizations without breaking the application.

The relational model is a data model based on relations.

A relation is an unordered set of tuples that represent some relationship between attributes.
A tuple is a set of attribute values, which are called the domain of the relation, and can be viewed as rows in a table.
Attribute values are normally atomic and scalar, with null values allowed if there are no constraints.
An $n$-ary relation is a table with $n$ columns.

### Relational Model Properties

The relational model's structure shows data independence, the application is isolated from the low-level data representation.
The database system can optimize the layout according to the operating environment, database contents and workloads.
The data is structured in the following levels.

- Database Storage
- Physical Schema (Pages, Files, Extents)
- Logical Schema (Schema, Constraints): The separation between the physical schema and the logical schema is called physical
  data independence.
- External Schema (Views): The separation between the logical schema and the external schema is called logical data independence.
- Application: The application can see the external schema or the logical schema only.

The relational model can enforce integrity constraints to ensure the database's contents satisfy user-defined conditions.

The relational model can provide a declarative API for accessing and modifying a database's contents via relations.
The relational model is independent from any query language implementation, and SQL is the standard for relational databases.

### Relational Model Concepts

**Primary Key**

Relations will have a primary key attribute that uniquely identifies each tuple in the relation.
Some database systems will automatically create an internal primary key.
Database systems can auto-generate primary keys using an identity column.

- SQL Standard: `IDENTITY`
- PostgreSQL, Oracle: `SEQUENCE`
- MySQL: `AUTO_INCREMENT`

Primary keys can also be defined across multiple attributes as a composite key.

**Foreign Key**

Relations can define foreign keys, which specifies that an attribute from one relation maps to a tuple in another relation.
We can use foreign keys to construct complex relationships such as many-to-many relationships between relations.

**Constraints**

Constraints are user-defined conditions that must hold for any instance of the database.
They can be enforced on the entire relation or on individual tuples.

- Unique Constraint
- Referential Integrity Constraint
- Non-Null Constraint: `NOT NULL`
- Check Constraint: `CHECK (condition)`
- Global Assertion
  - Global asserts are supported by SQL:92 but are rarely used in practice due to performance issues.
  - They are defined using `CREATE ASSERTION` statements.

## Data Manipulation Language

A data manipulation language (DML) is an API for storing, retrieving, and modifying the contents of a database.
DML can be procedural or non-procedural.
A procedural DML specifies the high-level strategy to obtain the desired results, while a non-procedural declarative DML
specifies what results are desired, not how to compute them.
Relational algebra is an example of a procedural DML, while SQL and relational calculus are examples of non-procedural DMLs.
Relational calculus is rarely used in practice and is mostly used in query optimization research.

### Relational Algebra

Relational algebra defines the fundamental set algebra operations for manipulating relations.
Since they are set operations, duplicate tuples are eliminated by default.

- Select
  - $\sigma_{p}(R)$
  - `SELECT * FROM R WHERE p`
- Projection
  - $\Pi_{a} (R)$
  - `SELECT a FROM R`
- Union
  - $R \cup S$
  - `(SELECT * FROM R) UNION (SELECT * FROM S)`
- Intersection
  - $R \cap S$
  - `(SELECT * FROM R) INTERSECT (SELECT * FROM S)`
- Difference
  - $R - S$
  - `(SELECT * FROM R) EXCEPT (SELECT * FROM S)`
- Product
  - Apply a Cartesian product between two relations, which computes all the combinations of tuples from both relations.
  - $R \times S$
  - `SELECT * FROM R, S`
  - `SELECT * FROM R CROSS JOIN S`
- Join
  - Generate a relation that contains tuples that combine related tuples from two relations based on some join condition.
  - $R \bowtie_{p} S$
  - `SELECT * FROM R NATURAL JOIN S`
    - Natural joins match by the same name attributes.
    - They are not recommended since the system must look up which attributes to join on.
    - If there are no predicates specified, natural joins will be used.
  - `SELECT * FROM R JOIN S USING (a, b)`
  - `SELECT * FROM R JOIN S ON p`

There are other relational algebra operators as well.

- Rename ($\rho$)
- Assignment ($R\larr S$)
- Duplicate Elimination ($\delta$)
- Aggregation ($\tau$)
- Division ($R\div S$)
