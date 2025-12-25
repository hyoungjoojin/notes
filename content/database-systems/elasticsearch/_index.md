+++
title = "elasticsearch"
+++

# ElasticSearch

ElasticSearch is a distributed NoSQL JSON-based data store used for near real-time searching and data analysis over a RESTful
API.
ElasticSearch can be used for implementing search engines and managing application observability data.

## ElasticSearch Architecture

### ElasticSearch Data Model

ElasticSearch is a document-oriented database, and the database itself is called an index.
Within an index, there are multiple fields, which are similar to columns in relational databases.
Each field can contain multiple documents, which are JSON objects containing fields and their values.

### ElasticSearch Cluster Architecture

The entire system of ElasticSearch is called an ElasticSearch cluster.
Within the cluster, there are multiple nodes, which are individual servers that host ElasticSearch instances.
Each node can hold multiple indices, which can contain shards of data of the index.
Shards are partitions of data and can be either a primary or replica shard.

The number of primary shards is defined at the time of index creation and can be changed later by reindexing the data.
Resizing the number of primary shards is expensive and should not be the main method for scaling an ElasticSearch cluster.

### ElasticSearch Search Engine

The search engine of ElasticSearch is a Java-based engine built on top of Apache Lucene.

ElasticSearch maintains an inverted index on the words of the data, making searching for content faster than relational databases.
This however makes updates and deletes more expensive than traditional database systems.

ElasticSearch provides tokenizers to break down text content into smaller tokens (words) and build the inverted index.
This is useful for providing a proper search experience by allowing a correct partial match searching.
The tokenizer can be customized based on the application requirements.
Synonyms can also be customized to improve the search experience.

## ELK Stack

The ELK stack is an ecosystem of tools built around ElasticSearch to provide data collection and visualization.
The ELK stack is composed of the following tools.

- ElasticSearch: Data Engine
- LogStash: Data Injestion & Transformation
- Beats: Data Collection
- Kibana: Visualization

In a typical ELK stack setup, Beats agents are installed on the application servers to collect logs and metrics data.
The collected data is sent to LogStash for transformation and enrichment before being indexed into ElasticSearch.
Kibana is then used to visualize and analyze the data stored in ElasticSearch.

## ElasticSearch System Design

### ElasticSearch Use Cases

ElasticSearch is commonly used for the following use cases.

- Searching for text content in applications while also providing filtering and sorting capabilities.
- Time series data analysis and aggregation, such as application observability data like logs and metrics.
  - For larger and more complex query, dedicated time series databases are more suitable, but ElasticSearch can still be used
    for simpler time series data analysis.

### Handling Write-Heavy Workloads

For write-heavy workloads, if the search engine does not require real-time updates, they can be stored in another database
system first and then indexed into ElasticSearch in batches.

**Full Index Updates**

Full index updates can be very expensive, and they should be done during off-peak hours.
This can be done by either having the application service or a separate worker service to write out the data to a file and then
uploading it to a shared storage like AWS S3 first.
Then, a separate worker service can read the data from the shared storage and perform the full index update.
ElasticSearch provides a bulk API to perform bulk index updates efficiently by chunking the data into smaller batches.
Using the bulk API with a parallel processing approach can significantly speed up the full index update process.

When performing full index updates, the old index should be kept as backup data.
This can be implemented using index aliases in ElasticSearch, where an alias can point to the main index and when performing
a full index update, a new index is created and the alias is switched to point to the new index after the update is complete.

**Partial Index Updates**

Partial index updates can be done asynchronously using a separate worker service and a message queue like Kafka.
Partial index updates and full index updates should not be done at the same time to avoid data inconsistency, and this can
be done using distributed locks like Redis Redlocks.
If the partial index update must be error-tolerant, the worker service can write the update tasks to a separate data store.
Inconsistencies might stack when using partial index updates, and therefore a periodic full index update should be scheduled.

### Speeding Up Search Queries

ElasticSearch provides caching mechanisms, but using an external caching layer like Nginx Web Cache or Redis can further speed
up search queries.
