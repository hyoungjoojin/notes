+++
title = "updates"
+++

# JPA Updating Entities

## Dynamic Updates

If we prefer to update columns that actually have been changed, we can add the `@DynamicUpdate`
annotation to the entity so that Hibernate will only call updates for the fields that actually
have been changed.

## Saving Entities

When persisting an entity, Hibernate checks if the entity is new or not, and calls persist if
it is and calls merge if it isn't. This overhead can be reduced if we use the `@Version` annotation
to pervent this (if version is null, then the entity is new) or to explictly state if the entity
is new by implementing the `Persistable` interface.
