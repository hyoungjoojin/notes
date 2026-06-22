+++
title = "computer-networking"
+++

# Computer Networking

## Network Devices

### Network Switch

A network switch is a device that provices connectivity to hosts within the same
local network. A network switch has many ports or interfaces that end hosts can
connect to. Network switches do not provice connectivity over the Internet or
between different local networks.

### Network Router

Network routers are used to provide connectivity between different local
networks and over the Internet. A network router has fewer ports than a network
switch, and each port is connected to a different local network.

### Network Firewall

A network firewall is a hardware device that monitors and controls incoming and
outgoing network traffic based on predetermined security rules. A firewall can
be placed within the network or outside the network, by placing it before or
after the router.

Network firewalls that provide advanced security features are called
next-generation firewalls (NGFWs).

## Error Detection and Correction

Error detection and correction (EDC) is essential in computer networking where
data can easily be lost or corrupted during transmission. EDC can be done in any
network layer. EDC does not guarantee that all errors will be detected or
corrected, therefore it is important to choose the right EDC method to decrease
the probability of undetected errors.

Bit errors commonly occur in bursts, where the probability of a bit error is not
independent of the previous bit.

The ability to detect and correct errors is essential for efficient
communication, since it removes the need for retransmission. This is called
forward error correction (FEC).

### Parity Check

Parity checks use additional parity bits that are derived from the data bits to
detect errors.

A one-bit parity check counts the number of 1s in the data bits and set the
parity bit to 1 or 0 based on the parity scheme to make the total number of 1s
in the data bits and parity bit even or odd. This scheme is simple but has a low
error detection capability, especially when bit errors occur in bursts.

Two-dimensional parity checks use multiple parity bits by arranging the data
bits into a two-dimensional matrix and calculating parity bits for each row and
column. Using these parity bits, it is possible to not only detect but also
correct single-bit errors.

### Checksum

Checksums view data bits as a sequence of $k$-bit integers. Checksum algorithms
are simple and fast, but they provide weaker capabilities. Checksum algorithms
are typically used in the transport layer and network layer because they have to
run on software and therefore need to be efficient. Link layer protocols
typically run on hardware and therefore can implement more complex EDC
algorithms.

The Internet checksum used in IP, TCP, and UDP works with 16-bit integers and
adds all the integers in the data bits to get the checksum value. The checksum
value is the one's complement of the sum, therefore the receiver can check for
errors by adding 16-bit integers in the data bits and the checksum value to see
if the result is all 1s.

### Cyclic Redundancy Check (CRC)

Cyclic redundancy check (CRC) is a error detection mechanism that treats the
data bits as a large binary number and divides it by a chosen binary number to
get the remainder as the CRC value.

CRC can't correct errors, but it is robust for burst errors. This is because the
generator value is chosen so that consecutive bit errors will produce different
CRC values.

CRC can also be efficiently implemented in hardware for error detection. CRC is
commonly used in the link layer.

In CRC, the sender and receiver agrees on some bit pattern called the generator
$G$. $G$ has $r+1$ bits for a $r$-bit CRC value. For example, the IEEE standard
for link layer CRC-32 uses the generator of
$G=100000100110000010001110110110111$ which has 33 bits. The CRC value is then
calculated by dividing the data bits (appended with $r$ 0 bits) by $G$ and
taking the remainder. Division works by performing bitwise XOR operations for
each step.

## Link Layer

The link layer in a network is responsible for direct communication between
adjacent nodes. A node is any device that runs a link layer protocol, and
devices can be connected by communication channels called links. Link layer
components are commonly implemented in hardware, which can be integrated within
the main chipset or as a separate chip called a network adapter (also called a
network interface card, NIC).

Link layer protocols can provide services of framing, reliable delivery, error
detection and correction, and access management. Framing is the process of
encapsulating network layer datagrams into link layer frames. Reliable delivery
isn't implemented in most link layer protocols due to its overhead, but
hardware-level error detection and correction mechanisms are usually
implemented. Access management is the process of determining which node can
transmit data at a given time, and this can get complicated when multiple nodes
share the same link.

## Application Layer

In the application layer, processes running on different hosts can communicate
with each other using a software interface called a socket. The processes are
identified by their IP address and port number.

### Application Layer Protocols

- [HTTP](./http)
- Multimedia Streaming Protocols (RTSP)
- [Video Streaming Protocols (DASH)](./video-streaming)
- [Email Protocols (SMTP, IMAP, POP3)](./email)
- [DNS](./dns)

## Transport Layer Protocols

- [UDP](./udp)
- [TCP](./tcp)

## Network Layer

### Network Layer Protocols

- [IP](./ip)

## Network Performance

Latency is the time it takes for data to travel from the source to the
destination. Latency includes various factors, such as the propagation delay,
transmission delay, processing delay, or queueing delay. Users will start to
perceive a lag when the latency gets to about 100-200 milliseconds. Latency is
usually the core factor in determining the performance of a web application, not
factors like bandwidth or throughput. However, improving latency is difficult
since the distance between two points is fixed and physical limitations exist.
Therefore, web applications must be designed to minimize latency by using
techniques like caching, pre-fetching, or reducing round-trips.

Bandwidth is the maximum rate of data transfer across a given path. Bandwidth is
determined by the lowest capacity link in the network path, and this can vary
widely based on the technology used and the conditions of the network. High
bandwidth is important for applications that require large amounts of data like
video streaming platforms. Improving bandwidth is easier than improving latency,
since it can be done by upgrading the hardware or increasing capacity.

### Bufferbloat

Bufferbloat is a problem that occurs when network devices have large buffers,
where network packets are not dropped and instead queued up in the buffer. This
happened because memory became more affordable, and the bufferbloat problem
leads to larger queueing delays and increased latency. TCP congestion control
algorithms use packet loss as a signal to reduce the sending rate, but since
packets are not dropped due to large buffers, TCP does not reduce the sending
rate, leading to an even worse situation.

#### Active Queue Management (AQM) Algorithms

AQM algorithms actively monitor and control the queue to avoid network
congestion and fully utilize the network capacity. CoDel, PIE, FQ-CoDel, FQ-PIE
are examples of AQM algorithms.

## Networking Diagnostic Tools

### `traceroute`

Traceroute is a network diagnostics tool for tracking the path a packet takes
from the source to the destination. It works by sending packets with different
hop limits, where each router along the path decrements the hop limit by 1.
Then, if a router receives a packet with a hop limit of 0, an ICMP Time Exceeded
message will be sent back to the source, allowing the source to identify the
time it takes to reach each hop.
