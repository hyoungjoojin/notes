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

### Databases

- [ ] Microsoft SQL Server
  - [ ] Memory-optimized Tables

## Programming Languages

### Java

- [ ] Java Reflection API

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
