# Roadmap

## Algorithms

### Data Structures

- [ ] Priority Queue
- [ ] B-Tree
- [ ] Trie
- [ ] Skip Lists
- [ ] Red-Black Tree

### Sorting Algorithms

- [ ] Vergesort
- [ ] QuickSort
- [ ] TimSort
- [ ] RadixSort
- [ ] HeapSort
- [ ] PowerSort

## Computer Hardware

### Solid-State Drives

- [ ] Write Amplification

## Database Systems

### Buffer Manager

- [x] Buffer Pools (#1)
  - [ ] How do distributed database systems work with buffer pools, especially dirty pages?
  - [ ] Buffer pool page tables can be made durable, but is it worth the implementation cost?
- [ ] Database Scan Sharing

#### Buffer Replacement Policy

- [ ] LRU-K Buffer Replacement Policy
- [ ] MySQL's Buffer Replacement Policy
- [ ] ARC (Adaptive Replacement Cache) Buffer Replacement Policy

### Database Replication

- [ ] Database Replication Lag

### Database Storage

- [ ] Index-organized Storage
- [ ] Log-structured Storage
- [ ] Column Stores
- [ ] N-ary Storage Model
- [ ] Decomposition Storage Model
- [ ] Hybrid Storage Model
- [ ] Heap Files

### Databases

- [ ] SingleStore
- [ ] YugabyteDB
- [ ] Microsoft SQL Server
  - [ ] Memory-optimized Tables
- [ ] MySQL
  - [ ] Consistent Nonlocking Reads
  - [ ] Locking Reads
  - [ ] Transaction Isolation Levels

### Other Concepts

- [ ] Database Partitioning
- [ ] Database Sharding

#### PostgreSQL

- [ ] PostgreSQL Dynamic Shared Memory

## Operating Systems

### Memory Management

- [ ] TCMalloc

## Security

### Cryptography

- [ ] Post-quantum Cryptography

## Distributed Systems

## Software Engineering

### Software Development Process

#### Software Development Approaches

- [ ] Waterfall Model
- [ ] Agile Software Development

### Software Design

#### Software Design Patterns

#### Software Design Approaches

- [x] Domain-driven Design (#4)
- [ ] CQRS
- [ ] Hexagonal Architecture
- [ ] Event-driven Architecture
- [ ] Reactive Programming
- [ ] Functional Programming

## Programming Languages

### C++

- [ ] Class Template Specialization

### Java

- [ ] Java Reflection API

#### JVM

- [ ] JVM Class Loader
  - [ ] Why do class not found exceptions occur at runtime?

## Development Tools

### Java Tools

- [ ] Vavr

### ORM Tools

#### JPA & Hibernate

- [ ] JPA GeneratedValue
  - [ ] `@GeneratedValue` can't be used with non-primary keys
- [ ] JPA Inheritance Mapping
- [ ] JPA Fetch Strategies
- [ ] JPA Proxy Objects
- [ ] JPA Entity Graph
- [ ] JPA Transactions
- [ ] JPA Bulk Updates & Deletes
- [ ] JPA Optimistic/Pessimistic Locking
- [ ] JPA Second-Level Cache
- [ ] JPA Cascading
- [ ] JPA Dirty Checking
- [ ] JPA Flush Modes
- [ ] JPA Entity Lifecycle Callbacks
- [ ] JPA Auditing
- [ ] JPA Soft Deletes
- [ ] JPA Composite Primary Keys
- [ ] JPA Criteria API
- [ ] JPA Named Queries
- [ ] JPA Native Queries
- [ ] JPA Pagination
- [ ] JPA Batch Processing
- [ ] JPA Lock Modes
- [ ] JPA Transactional Write-Behind
- [ ] JPA Cache
- [ ] Transaction-scoped Persistence Context & Extended-scoped Persistence Context
- [ ] JPA `@ElementCollection`, `@CollectionTable`
- [ ] Auto-commits
- [ ] Unique constraints

### APM Tools

- [ ] Pinpoint

### Spring Framework

#### Spring Core

- [ ] Spring Circular Dependencies

#### Spring Data JPA

- [ ] Locking
- [ ] Stored Procedures
- [ ] Domain Events

#### Spring Security
