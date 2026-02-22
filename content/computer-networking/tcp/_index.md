+++
title = "tcp"
+++

# TCP (Transmission Control Protocol)

TCP is a connection-oriented transport layer protocol that provides a reliable
host-to-host communication channel over an unreliable underlying network.

## TCP Packet Structure

The size of a TCP packet is limited by the Maximum Segment Size (MSS). The MSS
is the maximum TCP payload size per segment negotiated during the three-way
handshake process. This value is typically 1460 bytes, which is the maximum
transmission unit (MTU) without the TCP/IP headers of 40 bytes.

## TCP Three-Way Handshake

TCP connections must be established through a three-way handshake process to set
and synchronize the initial variables for the connection. The handshake process
is as below.

1. SYN
   - The client initializes a sequence number to a random value $x$.
   - The client includes additional TCP flags and options in the SYN packet, and
     sends it to the server.

2. SYN ACK
   - The server receives the SYN packet.
   - The server increments the client's sequence number to $x + 1$ and sends it
     back to the client in the ACK field of the packet.
   - The server initializes its own sequence number to a random value $y$.

3. ACK
   - The client receives the SYN ACK packet.
   - The client increments the server's sequence number to $y + 1$ and sends it
     back to the server in the ACK field of the packet.

Each new TCP connection takes at least one full network round-trip due to the
three-way handshake. Although there are attempts to optimize the handshake
process, such as TCP Fast Open, they only work in certain cases and have
limitations. This is why reusing connections is important for performance when
using TCP.

## Flow Control

Flow control is a mechanism that prevents the sender from overwhelming the
receiver with too much data. This can be done by communicating each other's
receive window size, which indicates the size of available buffer space for
holding incoming data.

When the connection is first established, both sides set their receive window
size to their default values. Every single packet will contain the sender's
current receive window size, which is a value greater than or equal to 0.

### TCP Window Scaling

The receive window is allocated 16 bits in the TCP header. This means that the
maximum receive window size is restricted to 65,535 bytes. TCP window scaling is
a mechanism to increase the maximum receive window size by using a scaling
factor. TCP window scaling is enabled by default on modern systems.

The window scaling factor is set in the TCP options during the three-way
handshake process, where the receive window size is bit-shifted to the left by
the scaling factor.

## Congestion Control

Congestion control is a mechanism to prevent the sender from overwhelming the
network with too much data. This is required because even if there are flow
control mechanisms, the underlying network can be congested. If congestion
control is not implemented, data sent from nodes can pile up in the network,
making packets being dropped at intermediate routers.

### Slow Start

Slow start is when the sender starts sending data at a slow rate and then
increases the sending rate rapidly until it detects congestion. Slow start
initializes a congestion window size to a small conservative value, so that it
can estimate the available capacity between the sender and the receiver. The
initial congestion window size if 1 to 4 segments for older systems and 10
segments for modern systems.

The congestion window size is the amount of data the sender can have in flight
before receiving an acknowledgment from the receiver. The congestion window size
is not a value sent in the packet, instead it is a private variable maintained
by the sender. The maximum amount of data in flight, which is the amount of data
sent but not yet acknowledged, is the minimum of the congestion window size and
the receive window size.

For every received acknowledgment, the congestion window size is increased by
one segment, effectively doubling the congestion window size every round-trip
time. This is known as exponential growth.

Therefore, the following is the time required to reach a specific throughput
target, where $r$ is the round-trip time, $c$ is the initial congestion window
size, and $N$ is the target congestion window size. From this, we can see that
the initial congestion window size has a significant impact on the time since
each doubling requires one extra round-trip time.

$$
T = r\times \ceil \log_2 (\frac{N}{c}) \ceil
$$

Slow start is not an issue for streaming large amounts of data since the cost
can be amortized over the entire transfer. However for short transfers, which is
common for most TCP connections, requests are terminated before the congestion
window size can grow to a large enough value.

#### Slow Start Restart

Slow start restart is a mechanism that resets the congestion window size to the
initial value if the connection has been idle for some amount of time. This is
because the network conditions might have changed during the idle time, but this
is bad for long lived connections like HTTP keep-alive connections. This setting
can be disabled and is recommended to do so.

### Congestion Avoidance

Congestion avoidance is triggered in one of the following conditions.

- The congestion window size (`cwnd`) grows larger than the slow-start threshold
  (`ssthresh`).
- Duplicated ACKs
- Retransmission timeout

TCP originally used AIMD (Additive Increase Multiplicative Decrease) for
congestion avoidance, where the congestion window size decreases by half when
congestion is detected. However, AIMD is very conservative, and other algorithms
like PRR (Proportional Rate Reduction) have been implemented to improve the
performance of congestion avoidance.

### Fast Retransmit

### Fast Recovery

### Congestion Control Algorithms

#### CUBIC

#### BBR

## TCP Fast Open

TCP Fast Open (TFO) is a mechanism that sends data during the handshake process,
where data transfer starts in the initial SYN packet the client sends to the
server.
