+++
title = "udp"
+++

# UDP (User Datagram Protocol)

The User Datagram Protocol (UDP) is a connectionless transport layer protocol.
UDP provides the minimum services necessary for transport layer protocols, it
only provides transport layer multiplexing and error checking. UDP can be used
when the application service needs a finer control over the data transmission or
when the cost of connection establishment cannot be tolerated.

## UDP Features

- Finer application-level control over data transmission.
- No connection establishment.
- No connection state.
- Smaller packet header than TCP.
- Error checking using checksums.

## UDP Downsides

- For security reasons, UDP traffic can be blocked.
- UDP provides no congestion control, which can be a feature in some cases but
  loss rates can be high in congested networks.
