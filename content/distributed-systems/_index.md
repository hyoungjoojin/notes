+++
title = "distributed-systems"
+++

# Distributed Systems

## Consistency

### Consistency Guarantees

#### Weak Consistency

Weak consistency is where after a write operation happens, read operations may
or may not see the updated value. This is a best-effort approach to consistency,
and can be used in systems where consistency is not critical. Online gaming,
voice calls, video streaming are examples of systems that use weak consistency.

#### Eventual Consistency

Eventual consistency is where read operations will eventually see the updated
value after a write operation. DNS, SMTP are examples of systems that use
eventual consistency.

#### Strong Consistency

Strong consistency is where read operations will always see the updated value
after a write operation. File systems, databases are examples of systems that
use strong consistency.

### Distributed Transactions

#### Master-Slave Replication

Master-slave replication is a technique where the master node is responsible for
handling write operations, while the slave nodes are responsible for handling
read operations. The replication process is asynchronous, therefore the latency
and throughput are not affected. Weak to eventual consistency can be achieved
with full transactional support. It can have some data loss and read-only
downtime in the case of a failover.

#### Multi-Master Replication

Multi-master replication is where all nodes can handle both read and write
operations, and the writes get merged later on with some type of conflict
resolution. Like master-slave replication, since the replication process is
asynchronous, the latency and throughput are not affected and eventual
consistency can be achieved. Writes can happen in multiple nodes, therefore only
local transactions are supported. It can have some data loss on failover, but
there is no downtime since all nodes can handle read and write operations.

#### Two-Phase Commit (2PC)

2PC uses a coordinator to manage distributed transactions, where the coordinator
is responsible for gathering votes from all nodes to decide whether to commit or
abort a transaction. The coordinator sends a prepare message to all nodes, and
if all nodes vote to commit, the coordinator sends a commit message to all
nodes. If any node votes to abort, the coordinator sends an abort message to all
nodes. 2PC is not fully distributed in that it relies on the coordinator. There
is a fault-tolerant 2PC variant for handling coordinator failures.

2PC can achieve strong consistency with full transactional support and no data
loss. However, 2PC is heavy and synchronous, meaning it has high latency and low
throughput. 3PC can be used for asynchronous replication, but it still adds an
extra round trip.

#### Paxos

Paxos is a fully distributed consensus algorithm that can achieve strong
consistency with full transactional support and no data loss.
