+++
title = "sse"
+++

# Server-Sent Events

Server-Sent Events (SSE) is a one-way communication protocol created in 2006 that uses HTTP to send real-time updates from a
server to a client.
SSE is less flexible than WebSockets, but it is easier to implement and integrates well with existing HTTP infrastructure.

## SSE Features

### SSE and HTTP

SSE works on top of HTTP, making the implementation straightforward.
SSE uses the chunked transfer encoding feature HTTP/1.1 for sending data.
Chunked transfer encoding is where data sent from the server is split into chunks without specifying the total content length
and instead uses the `Transfer-Encoding: chunked` header.

Data is sent as a `text/event-stream` MIME type, and each event is encoded as simple text lines each separated with a pair of
newline characters.

SSE does not require HTTP/2, but using HTTP/2 can improve performance by allowing multiplexing of multiple SSE connections
over a single TCP connection.
SSE also benefits from other HTTP features like compression.

### Automatic Reconnection

Clients using SSE have built-in support for automatic reconnection.
When the connection is lost, the client will automatically attempt to reconnect to the server after a specified timeout period.

## SSE Limitations

### SSE and HTTP

SSE's specification has the following limitations regarding HTTP.

- Only `GET` requests are possible.
- Headers cannot be sent with SSE requests.
- Parameters can only be sent as query parameters.

This limitation exists to support a simpler model and to prevent header injection attacks or developer mistakes like sending
sensitive information in headers.

### One-Way Communication

Since SSE is a one-way communication protocol, the server cannot know if the client is still connected or not.
Also, the server cannot cancel or abort requests once they are sent.

### Server Load

When using SSE, the server may experience high load if many clients are connected simultaneously.
If many clients do not disconnect properly, this will lead to an even higher load on the server.
Using HTTP/2 can help mitigate this issue, but that doesn't really solve the problem.

## Javascript API

The `EventSource` API specifies SSE connection establishment and event handling.
