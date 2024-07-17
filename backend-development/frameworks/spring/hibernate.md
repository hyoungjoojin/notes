# Java Hibernate ORM

## Annotations
- Mapping
    - @OneToMany, @ManyToOne
        - Given an ER diagram like below, the hibernate mapping annotation is done like this.
        ```mermaid
        erDiagram
            Customer ||--|{ Order : has

            Customer {
                string id PK
            }
            Order {
                string id PK
                string customer_id FK
            }
        ```

        - @OneToMany
        ```java
        // Customer
        @OneToMany(mappedBy="customer_id")
        private List<Order> orders;
        ```

        - @ManyToOne
        ```java
        // Order
        @ManyToOne()
        @JoinColumn(nullable = false)
        private String customer_id;
        ```

- Timestamps
    - @CreationTimestamp
    - @UpdateTimestamp
