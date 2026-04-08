+++
title = "spring"
+++

# Spring

## Spring Beans

### Conditional Beans

Conditional beans are for declaring beans that should only be created under
certain conditions. This can be configured using annotations on beans.

- `@Conditional`

  ```java
  @Service
  @Conditional(MyCondition.class)
  public class MyService {}

  public class MyCondition implements Condition {

    @Override
    public boolean matches(ConditionContext context, AnnotatedTypeMetadata metadata) {
      return true;
    }
  }
  ```

- `@ConditionalOnBean`

  ```java
  @Service
  @ConditionalOnBean(MyService.class)
  public class MyOtherService {}
  ```

## Spring Data JPA

### Transaction Management

Spring's transaction annotation manages database rollbacks for exceptions. The
default setting rolls back for runtime exceptions but not for checked
exceptions. This can be configured using the `rollbackFor` attribute.

In Hibernate, read-only entities are not dirty-checked and therefore changes are
not flushed to the database.

## Jackson

### Spring Jackson Properties

- `spring.jackson.mapper.accept-case-insensitive-enums=true`: Allows Jackson to
  accept case-insensitive enum values when deserializing JSON.
