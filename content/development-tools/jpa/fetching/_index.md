+++
title = "fetching"
+++

# JPA Fetching Entities

## Lazy Fetching

Many-to-one and one-to-one associations are by default eager fetches. Even if it is guaranteed to
always use associated mappings, eager fetches should be avoided since they will cause N+1 queries.

### Join Fetch

### Enitty Graph

## Entity Reference

If we only need an entity as a reference, we can use the `getReferenceById` method to get a JPA
proxy object without having to fetch the database.

## Projections

### Dynamic Projections
