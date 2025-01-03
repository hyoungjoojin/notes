# Chapter 2: Parallel Hardware and Parallel Software

## Serial Systems

### The von Neumann architecture

- The von Neumann architecture consists of the CPU, main memory, and the interconnect between the CPU and memory.
- The CPU consists of the control unit and the processing unit.
    - The control unit stores the program counter and decides which instruction to execute.
    - The processing unit executes the actual instructions.
- von Neumann Bottleneck: The interconnect becomes the bottleneck since the CPU can execute instructions faster than memory I/O. The following methods are ways to mitigate this bottleneck.
    - CPU Caching: Store blocks of data in a cache that can be accessed faster than other memory locations.
        - Caches exploit the spatial locality and temporal locality patterns of data access.
        - Caches operate on blocks of data and instructions called cache lines.
        - Caches could either be write-through caches or write-back caches.
        - Cache mappings could be fully associative, direct mapped, or *n*-way set associative.
    - Virtual Memory: Allows for multiple processes to share the same main memory.
        - Memory is split into pages, and they can be placed in memory or in the swap space.
        - The page table and translation-lookaside buffer helps address translation.
    - Instruction-level Parallelism (ILP)
        - Pipelining: Split the CPU into multiple stages and execute instructions at the same time on different CPU stages.
        - Multiple Issue: Execute multiple instructions at the same time.
            - If the instructions are scheduled at compile time, it’s called a static multiple issue. If they’re scheduled at run-time, the system is a dynamic multiple issue and the processor is called a superscalar.
            - System uses techniques such as speculation or loop unrolling to maximize throughput.
    - Thread-level Parallelism (TLP): The processor switches execution between threads.
        - Fine-grained multithreading switches between every instruction, and coarse-grained multithreading switches when a stall happens.
        - Simultaneous multithreading (SMT) uses a superscalar processor to run multiple threads at the same time.