# Roadmap

## Database Systems

### Buffer Manager

- [x] Buffer Pools (#1)
  - [ ] How do distributed database systems work with buffer pools, especially dirty pages?
  - [ ] Buffer pool page tables can be made durable, but is it worth the implementation cost?

#### Buffer Replacement Policy

- [ ] LRU-K Buffer Replacement Policy
- [ ] MySQL's Buffer Replacement Policy
- [ ] ARC (Adaptive Replacement Cache) Buffer Replacement Policy

### Database Replication

- [ ] Database Replication Lag

### Databases

- [ ] Microsoft SQL Server
  - [ ] Memory-optimized Tables
- [ ] MySQL
  - [ ] Consistent Nonlocking Reads
  - [ ] Locking Reads
  - [ ] Transaction Isolation Levels

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

## Programming Languages

### Java

- [ ] Java Reflection API

#### JVM

- [ ] JVM Class Loader
  - [ ] Why do class not found exceptions occur at runtime?

## Development Tools

### ORM Tools

#### JPA & Hibernate

- [ ] JPA GeneratedValue
  - [ ] `@GeneratedValue` can't be used with non-primary keys
- [ ] JPA Inheritance Mapping
- [ ] JPA Fetch Strategies
- [ ] JPA Proxy Objects
- [ ] JPA Transactional Write-Behind
- [ ] JPA Cache
- [ ] Transaction-scoped Persistence Context & Extended-scoped Persistence Context
- [ ] JPA `@ElementCollection`, `@CollectionTable`

### Spring Framework

#### Spring Core

- [ ] Spring Circular Dependencies

#### Spring Security
