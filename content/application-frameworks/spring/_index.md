+++
title = "spring"
+++

# Spring

## Spring Beans

### Conditional Beans

Conditional beans are for declaring beans that should only be created under
certain conditions. This can be configured using annotations on beans.

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
