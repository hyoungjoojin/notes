+++
title = "database-systems"
+++

# Database Systems

## Database Data Models

### Relational Data Model

- [SQL](./sql)

## Database System Components

### Storage Manager

- [Buffer Manager](./buffer-manager)
- [Database Storage](./database-storage)

### Query Processor

- [Operator Execution](./operator-execution)

## Databases

- [PostgreSQL](./postgres)
- LevelDB: On-disk key-value data store by Google

### Search Engines

There are a lot of options for search engines.
Database providers like PostgreSQL or MySQL provide search engine capabilities and can work well for small to medium datasets.
Dedicated search engines like ElasticSearch can provide more advanced search capabilities and better performance for large
datasets with the cost of additional complexity.

- [ElasticSearch](./elasticsearch)
- Apache Solr: Search engine built on top of Apache Lucene.
- OpenSearch: Fork of ElasticSearch and Kibana by Amazon.
- ParadeDB: Search engine built on top of PostgreSQL.
- Algolia, MeiliSearch, Typesense: AI-powered hosted search engine services.
