+++
title = "identifiers"
+++

# JPA Identifiers

Identifers in JPA represent the primary key of an entity.

## Generated Identifiers

The primary key values can be automatically generated using the `@GeneratedValue` annotation.
The following are the generation types available for `@GeneratedValue`.

- Auto: Determine the generation type by looking at the attribute of the primary key.
- Identity: The primary keys are assigned using the database identity column.
  - Since this strategy uses the database generated values, the primary key value is accessible
    only after the data is inserted into the database. This prevents JPA from applying transactional
    write-behinds, because the identifier is required for an entity to become a persisted state.
- Sequence: The primary keys are assigned using a database sequence.
  - The sequence generator can be specified using the `@SequenceGenerator` annotation.
  - Sequence generation is different from the identity strategy in that, the sequence strategy
    will look up the database sequence and then allocate the primary key value to the entity.
    This happens before saving to the datatabse, meaning that transactional write-behinds are possible.

  ```java
  @Entity
  @SequenceGenerator(
      name = "BOOK_SEQUENCE_GENERATOR",
      sequenceName = "BOOK_SEQ",
      initialValue = 1,
      allocationSize = 50)
  public class Book {

    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "BOOK_SEQUENCE_GENERATOR")
    private Long id;
  }
  ```

  - The allocation size refers to the increment size of the sequence numbers, and a large number
    is chosen to reduce database calls for the sequence generator.

- Table: The primary keys are assigned using an underlying database table.
  - The table generator can be specified using the `@TableGenerator` annotation.
- UUID: The primary keys are generated from a UUID generator.

#### Composite Keys

Composite keys are primary keys composed of more than one columns. Composite keys are especially
useful for many-to-many associations where each association has additional data to maintain.

```java
@Entity
public class Book {

  @EmbeddedId private BookId id;

  @ManyToOne
  @JoinColumn(name = "company_id", insertable = false, updatable = false)
  private Company company;
}

@Embeddable
public class BookId implements Serializable {

  @ManyToOne
  @JoinColumn(name = "author_id")
  private User author;

  @Column(name = "title")
  private String title;

  @Column(name = "company_id")
  private String companyId;
}
```
