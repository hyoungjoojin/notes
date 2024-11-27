# Database Sharding

- Splitting a large database into smaller parts called shards.

## Benefits to Database Sharding

- Increased response time.
- Increased availability through replicated database shards.
- Increased scalability by not being limited by hardware resources.
- Increased availability through adding database shards in runtime.

## How does database sharding work?
- A database’s rows are split into multiple shards, where each shard contains a subset of rows from the original database. This is also called a logical shard.
- Each shard can run separately on an independent server called a node. This is also called a physical shard. A physical shard can contain multiple logical shards.
- A column in a database is chosen to be the shard key. The values of the shard key are hashed into the shard index.
- A software layer abstracts away the physical details and coordinates user queries to the appropriate shard.

## Methods of database sharding

- Range-based sharding
- Hashed sharding
- Directory sharding: Use a lookup table for finding the shard index.
- Geo sharding
