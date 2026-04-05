+++
title = "computer-networking"
+++

# Computer Networking

## Application Layer

In the application layer, processes running on different hosts can communicate
with each other using a software interface called a socket. The processes are
identified by their IP address and port number.

### Application Layer Protocols

- [HTTP](./http)
- [DASH](./dash): Protocol for streaming media content over the internet.
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
