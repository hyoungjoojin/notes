+++
title = "computer-networking"
+++

# Computer Networking

## Computer Networking Concepts

### Error Detection

Since data is not guaranteed to be transmitted correctly over the network, error
detection should be implemented to ensure the integrity of the data.

#### Checksum

Checksums can be used to detect errors in data transmission.

### Reliable Data Transfer

In computer networking, there are a lot of cases where we have to provide
reliable data transfer services over an unreliable underlying network. The
complexity of implementing reliable data transfer can differ based on the
characteristics of the underlying network, like whether the network can lose,
corrupt, or reorder packets.

#### Acknowledgments

Just like how humans would acknowledge the receipt of a message in a
conversation, acknowledgments (ACKs) can be used in networking to confirm the
successful receipt of data. Negative acknowledgments (NAKs) can also be used to
indicate that data was not received successfully. In the event of a NAK, the
sender can retransmit the data.

#### Sequence Numbers

For acknowledgments, it is possible that the ACKs and NAKs themselves are
corrupted or lost. Simply retransmitting the data again can lead to processing
duplicate data at the receiver. Most network protocols address this using
sequence numbers, where the sender assigns a sequence number to each packet and
the receiver can use the sequence number to determine if a packet is a duplicate
or not.

#### Duplicate ACKs

Instead of sending an explicit NAK, the receiver can send duplicate ACKs to
indicate that a packet was not received successfully.

#### Timeouts

Network protocols should also consider the fact that networks can drop packets
as well. In this case, the sender can set a timer after sending a packet, where
the sender will send the packet again if the timer timeouts before the ACK is
received.

#### Automatic Repeat Request (ARQ) Protocols

Automatic Repeat Request (ARQ) is where reliable data transfer is achieved by
acknowledgments and retransmissions.

#### Stop-and-Wait Protocol

The stop-and-wait protocol is a form of an ARQ protocol. The sender will send
data and then wait for the receiver's acknowledgment before sending the next
piece of data.

#### Alternating Bit Protocol (ABP)

The alternating bit protocol is a simple form of the ARQ protocol where a single
bit is used as the sequence number. This will only work for a stop-and-wait
protocol, since there are only two possible sequence numbers.

#### Pipelining

The stop-and-wait protocol is very inefficient since the sender has to wait for
an ACK after sending each packet. Pipelining is a technique that allows the
sender to send multiple unacknowledged packets at the same time. This requires a
larger range of sequence numbers and both the sender/receiver has to buffer
packets.

#### Go-Back-N (GBN) Protocol

#### Selective Repeat (SR) Protocol

#### Maximum Packet Lifetime

To address the problem where packets can get reordered in a network, a maximum
packet lifetime can be defined. This is because sequence numbers can get reused
after a certain amount of time.

## Application Layer

In the application layer, processes running on different hosts can communicate
with each other using a software interface called a socket. The processes are
identified by their IP address and port number.

### Application Layer Protocols

- [HTTP](./http)
- [DASH](./dash): Protocol for streaming media content over the internet.
- [Email Protocols (SMTP, IMAP, POP3)](./email)
- [DNS](./dns)

## Transport Layer

The transport layer provides a logical communication channel between two
processes running on different hosts. The transport layer breaks down messages
from the application layer into transport layer segments and adds a transport
layer header to each segment. These segments are then passed down to the network
layer. The transport layer is not concerned with how the data will be
transmitted to the destination host, it exists in the end-system to only care
about communication between processes

Transport layer multiplexing and demultiplexing is the concept of extending the
network layer's host-to-host communication to process-to-process communication.
The transport layer uses port numbers to identify different processes.

### Transport Layer Protocols

- [UDP](./udp)
- [TCP](./tcp)

## Network Layer

The network layer provides a logical communication channel between two hosts.

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
