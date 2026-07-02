+++
title = "spring"
heading = "Spring"
+++

## Spring Beans

### Conditional Beans

Conditional beans are a Spring Boot feature for configuring beans to load only
under certain conditions. This can be configured using annotations on beans.

- `@Conditional`

  ```java
  @Service
  @Conditional(MyCondition.class)
  public class MyService {}

  public class MyCondition implements Condition {

    @Override
    public boolean matches(ConditionContext context, AnnotatedTypeMetadata metadata) {
      return true;
    }
  }
  ```

- `@ConditionalOnBean`

  ```java
  @Service
  @ConditionalOnBean(MyService.class)
  public class MyOtherService {}
  ```

## Spring Actuator

It is possible to change the port of the Spring Actuator endpoints by setting
the property `management.server.port`. The default security filter is still
applied to the actuator endpoints, so a separate security filter chain is needed
to allow access to the actuator endpoints.

```java
@Bean
@Order(Ordered.HIGHEST_PRECEDENCE)
SecurityFilterChain actuatorSecurityFilterChain(HttpSecurity http) throws Exception {
return http.securityMatcher("/actuator/**")
    .authorizeHttpRequests(requests -> requests.anyRequest().permitAll())
    .csrf(csrf -> csrf.disable())
    .build();
}

@Bean
SecurityFilterChain appSecurityFilterChain(HttpSecurity http) throws Exception {
    ...
}
```

## Spring REST Docs

### Troubleshooting

- When using CSRF tokens in tests, the default configuration adds the token as a
  form parameter. This leads to an error from REST Docs saying that the CSRF
  token is undocumented. To fix this, the CSRF token can be sent as a header in
  the test request using `csrf().asHeader()`.
