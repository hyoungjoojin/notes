# JPA

## JPA (Java Persistence API)

```java
@Entity // We want to map this class to a database table
@Table(name = "USER_TABLE") // Which database table should it map to
public class User {
  @Id // This field is the primary key to the database
  @GeneratedValue(strategy = GenerationType.IDENTITY) // This field is auto-generated via the specified strategy
  private String id;
  
  @Column(name = "user_name") // Which column should this field map to
  private String name;
  
  // Empty constructors are necessary for Hibernate to build empty objects.
  public User() { }
  
  public User(String name) {
    this.name = name;
  }
}
```

### Hibernate

```java
void insert() {
  User user = new User("Bob");
  
  try(Session session = sessionFactory.openSession()) {
    session.beginTransaction();
    
    session.persist(user);
    
    session.getTransaction().commit();
  }
}

void fetch() {
  try(Session session = sessionFactory.openSession()) {
    session.beginTransaction();
    
    List<User> users = session.createQuery("select u from User u", User.class)
                         .list();
    
    session.getTransaction().commit();
  }
}
```