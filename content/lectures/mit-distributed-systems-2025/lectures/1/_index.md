+++
title = "1"
+++

# Lecture 1

> Introduction

## Distributed System

A distributed system is a system of multiple networked cooperating computing nodes.

The following are some of the main reasons to use distributed systems.

- Connect physically separated machines for sharing data between nodes.
- Increase capacity through parallelism.
- Build a fault tolerant system.
- Achieve security by isolating specific nodes within a network.

Distributed systems first appeared around the 1980s when local area networks (LANs) first appeared.
DNS and email were major distributed applications at the time and there were distributed services like AFS.

In the 1990s, websites became bigger with a lot of users and a lot of data due to commercial traffic being flowed through
the Internet and data centers becoming more popular.
In the 2000s, cloud computing emerged and the internal architectural designs in the 1990s were being accessed by a lot
more people in the public.
Distributed systems is still a highly studied, active research field.

Distributed systems deal with the infrastructure of the applications, mainly the storage, computation, or communication aspects.

Distributed systems are challenging because it has many concurrent parts and the systems must deal with partial failures.
Distributed systems have to achieve fault tolerance, consistency, and performance, which are hard to achieve all at once.

Fault tolerance relates to availability and recoverability.
Replication and transactional logging can be used to implement fault tolerance.
Consistency is the system behaving as if it is operating on one single node.
Performance can be measured by the system's throughput and latency, and in order to achieve a reasonable amount of performance,
a certain bit of fault tolerance and consistency must be sacrificed.

## MapReduce

MapReduce was created as Google's internal framework for large data processing, where it can be accessed through an an
interface that can be used by non-experts in distributed systems.
This is achieved by building a MapReduce framework, which is a distributed system that can take in two user-specified
sequential functions (`map` and `reduce`) and process the end result.

The `map` and `reduce` functions work in the following steps.

1. For every input file, the `map` function will process the input file and emit some key-value pair when necessary.
   For example, if the task is implementing `wc`, then `map` will read the file and emit $(word, 1)$ every time it sees a word.
2. The `map` phase worker runs on one single node and the result is written to a local intermediate file.
3. In the `reduce` phase, the `reduce` worker reads values by the key, where each worker will read key-value pairs that have
   a specific key.
   The workers therefore have to read through multiple `map` result files.
   This process is called shuffling and this is the most expensive process of the entire framework.
4. The `reduce` worker will then have an input value pair of a key and a list of values, which then the `reduce` worker will
   reduce into a key-value pair that will be written to a final output file.

The MapReduce framework is composed of multiple worker nodes and one single master node.
The master node will direct worker nodes for `map` or `reduce` tasks using its global knowledge of the
input, intermediate, output files, and also information about the nodes themselves.

Fault tolerance for the worker nodes is achieved by having the master node receive state information of the workers and
reassigning new workers if existing workers fail.
Since the map and reduce functions are functional declarative functions that do not change state, the map and reduce functions
can be run multiple times, which helps in reducing complexity of handling faults of worker nodes.

The MapReduce paper does not include fault tolerance mechanisms for the master node.
Also, slow workers (called stragglers in the paper) are handled by the master node spinning up different worker nodes to
run the same tasks in parallel.
