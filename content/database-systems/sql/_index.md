+++
title = "sql"
+++

# SQL

## Creating Tables

Identity columns can be defined using the `IDENTITY(seed, increment)` keyword.

```sql
CREATE TABLE books (
    id int IDENTITY (1, 50)
);

```
