+++
title = "data"
+++

# Spring Framework Data Access

## Transaction Management

### Declarative Transaction Management

#### `@Transactional`

The `@Transactional` annotation tells Spring to manage the transaction for a method or a
class (if the annotation is in the class-level, all methods are transactional).
Due to proxying mechanisms, the annotation works for public, protected and package-visible methods.

```java
public class BookService {

  @Transactional(
    propagation
  )
  @Transactional(
      propagation = Propagation.REQUIRES_NEW,
      isolation = Isolation.READ_COMMITTED,
      rollbackFor = Exception.class)
  public void action() {}
}
```

The attributes used with this annotation are as follows.

- Propagation Level: Define the boundaries of the transaction.

  | Propagation   | Transaction   | No Transaction | Description |
  | ------------- | ------------- | -------------- | ----------- |
  | MANDATORY     | Use           | Throw          |             |
  | REQUIRED      | Use           | Create         | Default     |
  | REQUIRES_NEW  | Wait + Create | Create         |             |
  | NESTED        | Create Nested | Create         |             |
  | SUPPORTS      | Use           | -              |             |
  | NOT_SUPPORTED | Wait          | -              |             |
  | NEVER         | Throw         | -              |             |

- Isolation Level: Define the isolation level of the transaction.

  | Isolation        | Description                      |
  | ---------------- | -------------------------------- |
  | DEFAULT          | Default level of the data store. |
  | SERIALIZABLE     |                                  |
  | REPEATABLE_READ  |                                  |
  | READ_COMMITTED   |                                  |
  | READ_UNCOMMITTED |                                  |

  - Applied only if propagation levels are `REQUIRED` or `REQUIRES_NEW`. This is because the
    two levels are the only ones that create a transaction and a new database connection.
