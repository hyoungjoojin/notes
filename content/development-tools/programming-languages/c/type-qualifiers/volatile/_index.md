+++
title = "volatile"
+++

# C Volatile Keyword

Declaring a variable as volatile adds optimization-related properties to that variable.

The compiler compiles the program in a way that volatile variables are always accessed by their
memory without any memory access optimizations.

```c
int main() {
  int i = 0;
  volatile int x = 0;

  for(i = 0; i < 10; i++) {
    x++;
  }

  return 0;
}
```
