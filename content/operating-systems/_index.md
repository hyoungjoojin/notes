+++
title = "operating-systems"
+++

# Operating Systems

## I/O System

### Memory-Mapped I/O

Each I/O device can be communicated with either port-mapped I/O or memory-mapped I/O.
Port-mapped I/O uses special hardware instructions for communication, but memory-mapped I/O
uses memory load and store instructions to communicate with the I/O device.
Memory-mapped I/O works by allocating a piece of memory to an I/O port, in which
instructions targeted to the allocated memory goes to the I/O device's port.

### Direct I/O & Buffered I/O

Direct I/O is a feature for directly reading storage device data into memory without
passing through the page cache. The `O_DIRECT` flag is used in Linux to use direct I/O.
Buffered I/O is the opposite of direct I/O, where the page cache is used, and is the
default mode for most operating systems.
