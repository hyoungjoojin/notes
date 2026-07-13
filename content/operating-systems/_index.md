+++
title = "operating-systems"
heading = "Operating Systems"
+++

## Process

### Limited Direct Execution

In order to efficiently use the computer's hardware resources, the operating
system allows user programs to run directly on the hardware. This is called
direct execution, but this comes with some problems. First, the operating system
must limit user processes from running restricted operations. Also, the
operating system must be able to switch between different processes in order to
time share the CPU.

### Traps and Interrupts

To enable the operating system to interfere with user processes, the operating
system uses mechanisms called traps and interrupts. Traps are software-oriented
synchronous signals that request the operating system to perform some action and
interrupts are hardware-oriented asynchronous signals that request the operating
system to perform some action by pausing execution of the current process.

#### User Mode and Kernel Mode Separation

To solve the first problem of limiting user processes from running restricted
operations, we can separate the processor's mode into separate modes. User mode
processes can only run a limited set of instructions.

In order for user mode processes to run these restricted instructions, they must
perform a system call. To execute a system call, the user process follows the
following steps.

0. At boot time, the operating system sets up a trap table. The booting process
   is done in kernel mode and the trap table stores the addresses of each of the
   system call handlers in the kernel. The trap table is a privileged resource,
   and user processes cannot modify it. This trap table is placed in every
   process's read-only memory space.
1. The user process executes a library function, which is typically a wrapper
   around a system call and still runs in user mode.
2. The library function executes a trap instruction. This instruction switches
   the processor into kernel mode and jumps to a specific location in the kernel
   code.
3. The kernel code executes the system call, which may involve executing
   restricted instructions and accessing hardware resources.
4. The kernel calls a return-from-trap instruction, which switches the processor
   back into user mode and returns to the user process.

The processor determines which mode it is in by reading specific bits in the
processor's status register (FLAGS on x86 processors and CPSR on ARM
processors).

#### Timer Interrupts

To solve the second problem of switching between different processes, the
operating system uses timer interrupts. A timer interrupt is an interrupt that
occurs at regular intervals, that forces the processor to switch from user mode
to kernel mode and execute the kernel code.
