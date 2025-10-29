+++
title = "entity-persistence"
+++

# Entity Persistence

## Entity State Detection

When saving an entity, Spring Data will check the state of the entity first. If the entity
is not yet persisted, `persist` will be called, otherwise `merge` will be called. There
are a couple of ways Spring can detect the entity's state.

### `@Id`

If the identifier of the entity is null, the entity is considered to be new.

### `@Version`

If the entity has a version property, the entity is considered new if the the version is null.
Since the version field has to be nullable, primitive types can't be used as version fields.

### `Persistable`

If the entity implements the `Persistable` interface, the `isNew` method is used to determine if
the entity is null or not.

This is great if the identifier of the entity is manually assigned (like generated UUID business keys).
In this case, Spring will assume that the entity is not new and will call merge. This leads to an
extra select statement and if the identifier happens to exist in the database, the existing data
will be unexpectedly overwritten. A common practice is to use a transient field that gets changed
following JPA lifecycle events.

```java
@Entity
public class Book implements Persistable<UUID> {

  @Id private UUID id;

  @Transient private boolean isNew = true;

  @Override
  public boolean isNew() {
    return isNew;
  }

  @PostPersist
  @PostLoad
  private void markNotNew() {
    this.isNew = false;
  }
}
```
