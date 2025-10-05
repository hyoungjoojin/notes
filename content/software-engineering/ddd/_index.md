+++
title = "ddd"
+++

# Domain-Driven Design

Domain-driven design is a software design approach that focuses on modeling the business requirements
as domains that closely match the domain expert's view of the business.

The process of domain-driven design can be viewed as a two-step process of strategic design and
tactical design.

## Strategic Design

Strategic design is the process of defining the domains from a high-level point of view. This
is the process where the domains and sub-domains of the business are recognized and a common
understanding for the domains are formed between the software engineers and the domain experts.

### Ubiquitous Language

Ubiquitous language is the common language software engineers and domain experts agree upon
in the strategic design phase.

### Bounded Context

A bounded context is a clearly separated area of the domain model, where within the bounded context
the models and language are consistent. Between bounded contexts the same concepts can be shared,
for example users, but each bounded context will refer to the shared concept in their own language,
like viewers or subscribers.

### Context Mapping

Context mapping is the process of defining the connections between each bounded context.

In order to prevent the domain from being polluted by information from another domain,
concepts like anti-corruption layers can be used to isolate the bounded context from other contexts.

### Event Storming

Event storming is an activity performed within the strategic design phase that can identify domain
events.

## Tactical Design

Tactical design is the process of deciding on the low-level implementation details.

### Domain Models

The following are the base models used in domain-driven design.

- Entity: Entities are mutable objects defined by its identity value.
- Value Object: Value objects are immutable objects that only contain attribute values.
- Aggregate: Aggregates are a group of entities and value objects. The aggregate defines the
  transactional boundary of the domain entities, ensuring core business logic.
- Aggregate Root: Each aggregate has a single root entity, and all entities within an aggregate are
  referenced by the aggregate root.
