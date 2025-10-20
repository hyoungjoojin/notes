+++
title = "entity-projections"
+++

# Entity Projections

Projection types are used to manually select the attributes that we want to fetch from the database.
These projection types should live outside of the type hierarchy of the entity, otherwise the entity
will be fetched in the same way as before (ex. if we fetch a super-class, the entity will be fully
fetched).

## Interface-based Projections

If we define a query method that returns an interface specifying accessors to the fields that we
want to project, Spring Data will generate the query. It does this by creating a proxy object of
the interface at runtime, in which the proxy object will forward the methods to the target entity.
If we override the base methods defined in `CrudRepository`, like `findById`, then Spring will not
create the proxy object and instead will fetch the entire entity.

```java
interface UserProjection {

  String getFirstname();

  String getLastname();
}

interface UserRepository extends Repository<User, String> {

  Collection<UserProjection> findByLastname(String lastname);
}
```

Closed projections are where all attributes of the projection exists in the original entity, while
open projections have new values derived from the original entity. Closed projections can be optimized
by Spring data, while open projections work will SpEL expressions that are not optimized by Spring.
It would be better to use a default interface method for derived values instead of using open
projections.

```java
interface UserProjection {

  @Value("#{target.firstname + ' ' + target.lastname}")
  String getFullname();
}
```

Nested projections are allowed, in which case a projection interface of another entity can be used
within a projection interface.

## Class-based Projections

Class-based projections refer to DTO-based projections, where the fields to return are the properties
of the DTO class. Spring cannot create proxy objects for classes, and therefore nested projections
are not possible (because the DTO class has to be explicitly constructed).

The class used for projections should have one single constructor, since that will be the one Spring
uses to construct the projection. If there are multiple constructors, we can use the
`@PersistenceCreator` annotation to state the constructor to use for projections.

```java
public class UserProjection {

  private final String firstname;
  private final String lastname;

  protected UserProjection() {}

  @PersistenceCreator
  public UserProjection(String firstname, String lastname) {
    this.firstname = firstname;
    this.lastname = lastname;
  }
}
```

Dynamic projections can be used for selecting the type to return at run-time.

```java
interface UserRepository extends Repository<User, String> {

  <T> Collection<T> findByLastname(String lastname, Class<T> type);
}
```
