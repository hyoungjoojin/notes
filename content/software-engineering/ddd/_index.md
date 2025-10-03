+++
title = "ddd"
+++

# Domain-Driven Design

Domain-driven design is a software design principle that focuses on the domains of the application.

The process of domain-driven design can be viewed as a two-step process of strategic design and
tactical design. Strategic design is the process of defining the domains from a high-level
point of view, and tactical design is the process of deciding on the low-level implementation details.

## Strategic Design

### Ubiquitous Language

Within the strategic design stage, software engineers and domain experts must decide on a common
language. This common language is called the ubiquitous language.

### Event Storming

Event storming is one of the activities performed within the strategic design phase.

## Tactical Design

### Bounded Context

Domain models can be grouped into bounded contexts. A bounded context is a clearly separated
group of domains.

Aggregates are group of entities that are interconnected with each other. Aggregates are used
to prevent the entire application becoming a mess by grouping strongly connected entities together.
Each aggregate has a single root entity, where all other child entities are referenced by the root
entity. Typically the aggregate is bounded to a transaction scope.
