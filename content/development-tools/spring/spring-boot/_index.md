+++
title = "spring-boot"
+++

# Spring Boot

## Database Connection

### Database Connection Pool

By default, Spring Boot will use HikariCP as its connection pool. Although we can modify the
connection pool size, it is best to leave it minimal with a few dozen connections since a large
connection pool size will only degrade the system performance due to intensive context switching
between threads.

### Auto Commit

Spring defaults to using auto commits in database connections.
This can hurt performance since the method will hold on to transaction connections even when
its not needed. Auto commits can be turned off by configuration.

```yaml
spring.datasource.hikari.auto-commit: false
```

### OSIV

Open session in view (OSIV) refers to having the entity manager be open until web views.
The default configuration enables OSIV, which can hurt performance because the database connection
won't be closed even when the transaction is finished.

```yaml
spring.jpa.open-in-view: false
```
