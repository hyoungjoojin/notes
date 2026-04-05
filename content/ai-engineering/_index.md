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
navigates through the graph's connections to find relevant information.

## Model Context Protocol (MCP)

The Model Context Protocol (MCP) is a proposed standard for communication
between AI models and external systems. The protocol defines a common interface
between the MCP host and the MCP server. The MCP host can communicate with an
MCP server to get its available tools and use them to perform various tasks. The
tools can be database queries, API calls, or any other operation. In a full
operation, the MCP host will provide the available tools to the AI model, which
will then decide on which tools to use and how to use them to achieve its goals.
This information is passed back to the MCP host, which will then call the tools
to the MCP server and then return the results to the client.
