+++
title = "sse"
+++

# Server-Sent Events

Server-Sent Events (SSE) is a uni-directional communication protocol that uses HTTP to send real-time updates from a
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
Disconnecting a client from the server will trigger the client for reconnection attempts, and this can be disabled by either
sending a 204 response code or implementing a custom disconnection event on the client.

### Graceful Shutdown

When the client disconnects, the server is notified and can perform any necessary cleanup operations.
Even if the client does not disconnect gracefully, the server can still detect this disconnection through TCP timeouts.

## SSE Limitations

### SSE and HTTP

SSE's specification has the following limitations regarding HTTP.

- Only `GET` requests are possible.
- Custom headers cannot be sent with SSE requests.
- Parameters can only be sent as query parameters.

### Uni-directional Communication

Since SSE is a uni-directional communication protocol, SSE cannot be used in cases where bi-directional communication is required.

### Server Load

When using SSE, the server may experience high load if many clients are connected simultaneously.
If many clients do not disconnect properly, this will lead to an even higher load on the server.
Using HTTP/2 can help mitigate this issue, but that doesn't really solve the problem.
The number of concurrent SSE connections a server can handle is chosen by the server's resource configuration, the number of
possible concurrent TCP connections, and how much resource each SSE connection consumes.
SSE isn't particularly resource-intensive compared to WebSockets, but it sends more data per message due to HTTP overhead
therefore causing higher network bandwidth usage.

### Text-Only Data

SSE can only send UTF-8 encoded text data and if binary data must be send, it must be base-64 encoded first.

## JavaScript API

The `EventSource` API specifies SSE connection establishment and event handling.
