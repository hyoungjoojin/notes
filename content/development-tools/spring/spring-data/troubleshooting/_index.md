+++
title = "troubleshooting"
+++

# Spring Data Troubleshooting

<details>
<summary> 
The value of an enum constant cannot be mapped.
</summary>

```
org.springframework.dao.InvalidDataAccessApiUsageException: No enum constant X
java.lang.IllegalArgumentException: No enum constant X
```

### Problem

In this case, I used the `@DiscriminatorColumn` and `@DiscriminatorValue` annotations to represent
the discriminator fields. I also used a read-only column definition to map the discriminator value
to a field. The problem was, when I set the field value of the entity (`entity.setType(type)`),
the value that was saved wasn't the parameter I passed into but instead it was the lowercase version
of that field. When I fetched the entity from the database, since it doesn't map to any enum fields
the illegal argument exception was thrown.

### Solution

The value that I want to save as the enum value needs to be passed directly to the discriminator value
annotation.

```java
@Entity
@DiscriminatorValue(value = "X")
public class Entity extends BaseEntity {}
```

</details>
