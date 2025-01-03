# Chapter 3: Machine-Level Representation of Programs

## Machine-Level Code

- Machine-level programs have abstracted away two concepts.
    - Instruction Set Architecture (ISA)
        - The ISA defines the processor state, format of the instructions, and the effect of each instruction.
        - Machine-level programs uses the instructions defined in the ISA.
        - Hardware components guarantee that these instructions follow the specification.
    - Memory Address
        - Memory addresses used in a machine-level program are virtual addresses.
- Differences between higher level programs
    - Program counter (`%rip` in x86-64), integer registers, condition code registers are visible.
    - Machine-level code has no distinctions between data types.
- Data Formats
    - x86-64 uses word for 16-bit data types, double word for 32-bits, and quad word for 64-bits.
    - The following table shows x86-64 assembly code’s suffixes, used like `movq` or `movl`.
        
        
        | Intel Data Type | Assembly-code Suffix | # of Bytes |
        | --- | --- | --- |
        | Byte | b | 1 |
        | Word | w | 2 |
        | Double Word | l | 4 |
        | Quad Word | q | 8 |
        | Single Precision Float | s | 4 |
        | Double Precision Float | l | 8 |

## Other Topics

### GCC Commands

```bash
gcc -Og -o p p1.c
```

- Optimization: Users can specify the levels of optimization, the `-Og` flag tells the compiler to output machine code that follows the structure of the source code.
- Output
    - `-S`: Output an assembly file and exit. Code goes through the compiler.
    - `-c`: Output an object file and exit. Code goes through the compiler and assembler.

### Programs

- Object Dump (`objdump`)
    - `objdump -d main.o`: Disassemble the input object file.