+++
title = "make"
+++

# Make

## Makefile Keywords

### `.PHONY`

When a target name is the same as a file or directory in the same directory,
Make will prioritize the file or directory over the target. In order to ignore
this and have the Makefile target always run, we can declare the target as
`.PHONY`:

```makefile
.PHONY: clean

clean:
    rm -rf build
```
