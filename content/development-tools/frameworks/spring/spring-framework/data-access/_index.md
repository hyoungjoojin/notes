+++
title = "data"
+++

# Spring Framework Data Access

## Transaction Management

### Declarative Transaction Management

#### `@Transactional`

The `@Transactional` annotation tells Spring to manage the transaction for a method or a class.
The annotation works for public, protected and package-visible methods.

```java
public class BookService {

  @Transactional
  public void action() {
    // ...
  }
}
```

The attributes used with this annotation are as follows.

- Propagation Level: Define the boundaries of the transaction.

  | Propagation   | Transaction     | No Transaction  | Description |
  | ------------- | --------------- | --------------- | ----------- |
  | REQUIRED      | Use             | Create          | Default     |
  | SUPPORTS      | Use             | -               |             |
  | MANDATORY     | Use             | Throw Exception |             |
  | NEVER         | Throw           | -               |             |
  | NOT_SUPPORTED | Wait            | -               |             |
  | REQUIRES_NEW  | Wait & Create   | Create          |             |
  | NESTED        | Create (Nested) | Create          |             |

- Isolation Level: Define the isolation level of the transaction.

  | Isolation        | Description                      |
  | ---------------- | -------------------------------- |
  | DEFAULT          | Default level of the data store. |
  | SERIALIZABLE     |                                  |
  | REPEATABLE_READ  |                                  |
  | READ_COMMITTED   |                                  |
  | READ_UNCOMMITTED |                                  |

  - Applied only if propagation levels are `REQUIRED` or `REQUIRES_NEW`.
