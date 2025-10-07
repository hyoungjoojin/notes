+++
title = "troubleshooting"
+++

# Spring Security Troubleshooting

<details>
<summary>
java.lang.ClassNotFoundException: org.bouncycastle. ...
</summary>

### Environment

- Spring Boot v3.5.6

### Cause

Bouncycastle was set as an optional dependency by the Spring Boot team.

### Solution

Manually add the dependency for org.bouncycastle.

```gradle
implementation('org.bouncycastle:bcprov-jdk18on:1.78.1')
```

</details>
