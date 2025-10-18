+++
title = "graphql"
+++

# GraphQL

## GraphQL Fragments

GraphQL fragments are used for creating reusable units in repetitive queries.

```graphql
query {
  left: character(episode: "1") {
    ...CharacterFields
  }
  right: character(episode: "2") {
    ...CharacterFields
  }
}

fragment CharacterFields on Character {
  name
}
```

Inline fragments are used for querying on interfaces or union types.

```graphql
query {
  character(episode: "1") {
    name
    ... on Human {
      height
    }
    ... on Animal {
      species
    }
  }
}
```
