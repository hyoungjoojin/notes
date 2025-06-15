+++
title = "oauth"
+++

# OAuth

## Client Registration

Before the OAuth protocol initiates, the client must be registered to the authorization server.

## Authorization Grant Types

An authorization grant is a credential that represents the resource owner's authorization to
access protected resources. The client uses the authorization grant to obtain an access token
from the authorization server.

The following are authorization grant types in OAuth.

- Authorization Code
- Implicit
- Resource Owner Password Credentials
- Client Credentials
- Device Authorization

## Authorization Flows

The following are authorization flow types in OAuth.

- Authorization Code Flow
- Implicit Flow
- Resource Owner Password Credentials Flow
- Client Credentials Flow
- Device Authorization Flow

## DPoP (Demonstrating Proof of Possession)

Without DPoP, access tokens can be used by anyone to get access to protected resources. To prevent
token replay attacks, DPoP introduces sender-constraints to OAuth tokens by using a client-side
private keys and a proof-of-possession mechanism on the application level.

## References

- Hardt, D., Ed., "The OAuth 2.0 Authorization Framework", RFC 6749, DOI 10.17487/RFC6749, October 2012, <https://www.rfc-editor.org/info/rfc6749>.
- Denniss, W., Bradley, J., Jones, M., and H. Tschofenig, "OAuth 2.0 Device Authorization Grant", RFC 8628, DOI 10.17487/RFC8628, August 2019, <https://www.rfc-editor.org/info/rfc8628>.
- Fett, D., Campbell, B., Bradley, J., Lodderstedt, T., Jones, M., and D. Waite, "OAuth 2.0 Demonstrating Proof of Possession (DPoP)", RFC 9449, DOI 10.17487/RFC9449, September 2023, <https://www.rfc-editor.org/info/rfc9449>.
