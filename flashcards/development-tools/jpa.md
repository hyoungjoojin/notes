# JPA

> 2

Represent the following SQL DDL using a JPA entity class in Java.
Also, define a public constructor that contains all fields.

```sql
CREATE TABLE books (
    id bigint PRIMARY KEY,
    title varchar(50) NOT NULL
);

```

--

```java
@Entity
@Table(name = "books")
public class Book {

  @Id private Long id;

  @Column(name = "title", nullable = false, length = 50)
  private String title;

  protected Book() {}

  public Book(Long id, String title) {
    this.id = id;
    this.title = title;
  }
}
```

--
