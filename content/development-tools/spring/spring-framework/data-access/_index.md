+++
title = "data-access"
+++

# Data Access

## Transaction Management

Managing transactions of the underlying data source can be done either declaratively or
programmatically through Spring's transaction features.

Programmatic transaction management can be done using the `TransactionTemplate`.

```java
@Service
public class BookService {

  private final TransactionTemplate transactionTemplate;

  public BookService(TransactionTemplate transactionTemplate) {
    this.transactionTemplate = transactionTemplate;
  }

  public void update() {
    transactionTemplate.execute(status -> {});
  }
}
```

Declarative transaction management can be done using the `@Transactional` annotation.
The `@EnableTransactionManagement` must be configured to use this annotation

## `@PersistenceContext`

JPA's entity manager is not thread-safe. Therefore if we make the entity manager as a bean
that multiple threads can access, concurrency problems may occur. In order to prevent this,
Spring provides the `@PersistenceContext` annotation for entity managers.

Spring enables thread-safety for the entity managers by wrapping the entity manager with a
proxy, in which the proxy will create a new entity manager for each transaction or return
an existing entity manager for a currently running transaction.

```java
public class BookRepository {

  @PersistenceContext private final EntityManager em;

  public BookRepository(EntityManager em) {
    this.em = em;
  }
}
```
