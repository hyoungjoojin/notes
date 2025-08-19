+++
title = "best-practices"
+++

# Java Best Practices

## Exceptions

**Exceptions should only be used for exceptional cases.**

- Using exceptions for any other purpose (_ex_. flow control for performance reasons) is a bad idea
  since exceptions would not have been optimized for other use cases and it makes debugging a lot harder.

```java
// BAD
try {
    int i = 0;
    while(true) {
        range[i++].climb();
    }
}catch(IndexOutOfBoundsException e) {}
```

**State-dependent methods should provide state-checking methods.**

- State-dependent methods are methods where it only properly behaves on a specific state.
- State-dependent methods should provide state-checking methods, except for the case where _i._ the state may change between calls to the state-dependent method and state-checking method or _ii._ both methods contain resource-intensive duplicate logic.
- State-checking methods are preferred over returning indicator values since it's more explicit.

```java
// GOOD - State-checking method
while(iter.hasNext()) {
    iter.next();
}

if(obj.isAvailable()) {
    obj.do();
}

// GOOD - Optional
iter.next().ifPresent(...);
```
