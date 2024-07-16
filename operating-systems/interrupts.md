# Interrupts
- An interrupt is an event that can change the normal execution flow of a program.

## Categories
- Ignorable
    - Maskable Interrupts
    - Unmaskable Interrupts
- Generation Method
    - Synchronous (Exception): Events generated from executing an instruction.
    - Asynchronous (Interrupt): External events from I/O devices.

## Interrupt Vector Table
- The interrupt vector table is always located on memory, and it contains memory addresses to each ISR (Interrupt Service Routine) for every interrupt number.

## IRQ (Interrupt Request Line)
- Each IRQ pin can be connected to the CPU by using a PIC (Programmable Interrupt Controller).
- The interrupt flow is as below:
    - A device raises an interrupt on a specific IRQ pin.
    - The PIC converts the IRQ into a vector number and writes it to a port for the CPU.
    - The PIC raises an interrupt on the CPU's INTR pin.
    - The PIC waits for the CPU to acknowledge the interrupt until another interrupt is raised.
    - The CPU acknowledges it and handles it.

## DMA (Direct Memory Access)

