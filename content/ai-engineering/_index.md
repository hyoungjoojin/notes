+++
title = "ai-engineering"
+++

# AI Engineering

## Retrieval-Augmented Generation (RAG)

Retrieval-Augmented Generation (RAG) is a technique that can help solve the
problem with generative AI models where they can only generate responses based
on the information they were trained on. This is problematic for the case where
the model has to answer queries related to a large knowledge base or requires
up-to-date information. RAG addresses this issue by having the model look up
relevant information from an external knowledge base and use that information to
generate a more accurate response.

RAG works in three steps: retrieval, augmentation, and generation. The model
retrieves relevant information, augments the input with that information, and
then generates a response based on the augmented input.

### Vector RAG

Vector RAG breaks data into chunks and converts them into vector embeddings,
which are then stored in a vector database. Retrieval is done by converting the
query into a vector and finding the most similar vectors in the database.

### Graph RAG

Graph RAG represents the knowledge base as a graph, and the retrieval process
navigates through the graph's connections to find relevant information. Since it
uses explicit relationships between entities, it is more interpretable and can
provide more accurate results than vector RAG which uses simple similarity
measures.

## Model Context Protocol (MCP)

The Model Context Protocol (MCP) is a proposed standard for communication
between AI models and external systems. The protocol defines a common interface
between the MCP host and the MCP server. The MCP host is the system that runs
the AI model.

The following is the general workflow of the MCP protocol.

1. The MCP host requests the available tools from the MCP server.
2. The MCP server responds with a list of available tools and their
   descriptions.
3. The MCP host provides the available tools to the AI model.
4. The AI model decides which tools to use and how to use them to achieve its
   goals.
5. The AI model provides the tool usage information back to the MCP host.
6. The MCP host calls the tools by requesting the MCP server.
7. The MCP server executes the tools, which can be a database query, an API
   call, or any other operation, and returns the results to the MCP host.
8. The MCP host returns the results to the client.
