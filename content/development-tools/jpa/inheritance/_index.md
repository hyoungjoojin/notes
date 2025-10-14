+++
title = "inheritance"
+++

# JPA Inheritance

## Accessing Discriminator Values

By creating a read-only column definition, the discriminator column value can be mapped to a field
in the class.

```java
@Inheritance(strategy = InheritanceType.JOINED)
@DiscriminatorColumn(name = "type", discriminatorType = DiscriminatorType.STRING)
public class Base {

  @Column(name = "type", insertable = false, updatable = false)
  protected String type;
}
```
