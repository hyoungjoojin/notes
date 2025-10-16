+++
title = "troubleshooting"
+++

# Spring Security Troubleshooting

<details>
<summary>
Class not found for Bouncy Castle Argon2Parameters.
</summary>

### Problem

When calling the method `Argon2PasswordEncoder.defaultsForSpringSecurity_v5_8()`, I got the following
exception.

```
java.lang.ClassNotFoundException: org.bouncycastle.crypto.params.Argon2Parameters$Builder
```

### Solution

The issue was that Bouncy Castle was set as an optional dependency by the Spring Boot team.
Manually added the dependency to solve the issue.

```gradle
implementation('org.springframework.boot:spring-boot-starter-security')
implementation('org.bouncycastle:bcprov-jdk18on:1.78.1')
```

### Environment

- Spring Boot v3.5.6
- Java 21

</details>
