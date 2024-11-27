# Garbage Collection

- Reference counting
  - Keep an additional reference count variable stored along the object and remove it when the reference count hits 0.
  - Can’t detect cycles

- Mark-and-sweep
  - Periodically sweep through stack frame and find directly referenced variables and indirectly referenced variables.
  - Any variable that is not marked will be sweeped and garbage collected.
