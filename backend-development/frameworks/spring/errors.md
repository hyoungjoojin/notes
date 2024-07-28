# Java Spring Framework Errors & Solutions

## Logging
- Spring Security Logging
    1. In resources/application.yml
    ```yml
    logging:
      level:
        org:
          springframework:
            security: TRACE
    ```
    2. In SecurityConfig.java
    ```java
    @EnableWebSecurity(debug = true)
    ```

## Errors
- org.hibernate.LazyInitializationException: failed to lazily initialize a collection of role
    - Cause: A JPA mapped entity was lazily loaded and was not initialized.
    - Solution:
        - Use FetchType.EAGER
        ```java
        @OneToMany(mappedBy = "user", cascade = CascadeType.ALL, fetch = FetchType.EAGER)
        private List<Role> roles;
        ```
        - Use JOIN FETCH directive in JPQL (Haven't tried this yet)

