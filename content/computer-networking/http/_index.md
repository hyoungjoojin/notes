+++
title = "http"
+++

# HyperText Transfer Protocol (HTTP)

The HyperText Transfer Protocol (HTTP) is a stateless application layer protocol
that specifies how a client and a server can communicate with each other.

## HTTP Message Format

### HTTP Request

An HTTP request message consists of a request line, headers, and an optional
body. Each of these components is separated by a carriage return and line feed
(CRLF).

The request line is composed of the HTTP method, request URI, and HTTP version.

```text
GET /index.html HTTP/1.1
```

### HTTP Response

An HTTP response message consists of a status line, headers, and an optional
body.

The status line is composed of the HTTP version, status code, and the
corresponding status message.

```text
HTTP/1.1 200 OK
```

## HTTP Features

### Cookies

HTTP is a stateless protocol, but the server can use cookies to maintain state
across multiple requests from the same client.

Cookies can be sent by the server using the `Set-Cookie` header in the HTTP
response, and the client can send the cookies back to the server using the
`Cookie` header in the HTTP request.

### Persistent Connections

HTTP/1.1 introduced persistent connections, where multiple HTTP requests and
responses can be sent over a single TCP connection. The default mode of HTTP
uses persistent connections.

### Pipelining

### Conditional GET Requests

To improve performance, HTTP responses can be cached by the client or proxy
servers like CDNs. This means that there is a possibility that the client is
currently viewing a stale version of the data. To address this issue, the client
and server can communicate the last modified time of the data using the
`Last-Modified` header in the HTTP response and the `If-Modified-Since` header
in the HTTP request. If the data has not been modified since the last time it
was fetched, the server can respond with a `304 Not Modified` status code,
indicating that the client can use the cached version of the data.

### Multiplexing

Multiplexing in HTTP splits each HTTP message into smaller frames, which can
then be interleaved and sent over the same TCP connection. This allows multiple
HTTP requests and responses to be sent simultaneously without blocking each
other.

### Message Prioritization

Message prioritization allows servers to mark HTTP messages with different
priority levels.

### Server Push

Server push allows servers to send multiple HTTP responses for a single HTTP
request.

## HTTP Issues

### Head-of-Line (HoL) Blocking

Head-of-Line (HoL) blocking is a problem where a large HTTP request or response
can block subsequent messages from being processed until the current message is
fully processed. This issue is fixed in HTTP/2 by using multiplexing.

## Appendix

### HTTP Status Codes

- `200 OK`
- `304 Not Modified`

### HTTP Versions

#### HTTP/1.1

The following features were introduced in HTTP/1.1.

- Persistent Connections

#### HTTP/2

The following features were introduced in HTTP/2.

- Multiplexing
- Request Prioritization
- Server Push
- Header Compression

#### HTTP/3

The following features were introduced in HTTP/3.

- QUIC Transport Protocol
