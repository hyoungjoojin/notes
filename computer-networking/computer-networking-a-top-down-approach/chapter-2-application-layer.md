# Chapter 2: Application Layer

# Network Applications

- Network application developers are provided with network services that are assumed to provide certain functionalities such as data transfer between two hosts. Application developers should not and cannot develop software that run on network devices and instead develop application programs running on end hosts.
- Network Application Architecture
    - Client-Server Architecture
    - P2P Architecture
- Message Communication
    - Regardless of the network application architecture, the message sending side is called the server process and the recieving side is called the client process.
    - Sockets are interfaces applications can use to send messages. It’s like a door, where applications send and recieve data through the socket but do not care how the data is transfered between doors.
    - For successful message transfer, the address of the end-host and an identifier for which process the message will be recieved at is needed. The IP address and the port number does this task in the Internet.
    - Application layer protocols define the syntax and sematics of the messages being transferred. Protocols such as HTTP are specified in RFCs and some are proprietary.

### Transport Layer Services

- Transport Layer Protocols
    - TCP
        - Messages in TCP are transferred after the client and server makes a connection via a handshaking procedure.
        - The connection is a full-duplex connection.
        - A congestion-control mechanism is used to limit network congestion.
    - UDP
        - A connection-less unreliable data transfer service.
- Functionalities that may be provided by transport layer services are as below.
    - Reliable Data Transfer
        - Except for loss-tolerant applications such as multimedia applications, most application would require to have uncorrupted data when sending and recieving information.
        - The TCP protocol offers reliable data transfer.
    - Throughput
        - Offering a constant guaranteed network throughput is important for bandwidth-sensitive applications such as multimedia applications.
        - The current Internet model does not provide throughput guarantees.
    - Timing
        - Guarantees for when a packet should arrive is important for building interactive real-time applications.
        - The current Internet model does not provide timing guarantees.
    - Security
        - Transport layer protocols can offer data encryption, data integrity, confidentiality, and end-point authentication.
        - TCP and UDP does not provide data encryption, this can be achieved by manually using an enhancement to TCP called TLS (Transport Layer Security).