+++
title = "software-engineering"
+++

# Software Engineering

## System Design

### CAP Theorem

The CAP theorem states that in a distributed system, only two of the three
properties: consistency, availability, and partition tolerance can be achieved
at the same time. Partition tolerance is the ability of a system to continue
functioning even when there are network partitions. Network partitions are when
two nodes in a distributed system cannot communicate with each other due to
causes like network failures.

Although the CAP theorem states that it can achieve two of the three properties,
partition tolerance isn't something that we can control. Therefore, the CAP
theorem is the trade-off between consistency and availability in the presence of
network partitions. If we prioritize consistency, then we have to sacrifice
availability, meaning that the system cannot accept requests during a network
partition. If availability is more important, then the requests can be processed
individually by each node and later synchronized when the partition is resolved.

In most cases, it isn't a strict choice between consistency and availability,
but instead designing the system so that it can provide a certain level of
consistency while still being partly available during network partitions based
on the set of requirements.

### API Design

#### Pagination

- Offset-based Pagination
- Cursor-based Pagination
- Page-based Pagination
- Time-based Pagination
- Keyset Pagination
