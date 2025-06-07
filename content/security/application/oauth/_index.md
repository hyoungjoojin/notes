+++
title = "OAuth"
toc = true
+++

OAuth is a framework for delegated authorization.

## OAuth Terminology

### Roles

In OAuth, the resource owner wants to give the client access to resources in the resource server,
in which the authorization server provides the client an access token to do just that.

- Resource Owner: The user that owns the data in the resource server.
- Resource Server: The server that stores the user's data.
- Client: The appliation server that needs access to the protected resources.
- Authorization Server: The server that provides access tokens to clients.

### Communication Channels

Depending on how secure the communication channel is, they can be classified into the following.

- Front Channel: An insecure data communication channel through the user agent's address bar.
- Back Channel: A secure and encrypted data communication channel between the client and the server.

### Other Terminology

- Scope: Scopes limit a client's access to the protected resources.
- Grant Type: The steps clients must take to get access tokens.
- Flow: Depending on the grant type, the steps to requiring access tokens differ, and is called a flow.

## OAuth Flows

### Authorization Code Grant Flow

#### Steps

1. The client asks the authorization server for an authorization code.
2. The authorization server gives the client the authorization code.
3. The client asks the authorization server for an access token using the authorization code.
4. The authorization server gives the client an access token.
5. The client uses the access token to communicate with the resource servers.

### Authorization Code Grant Flow with Proof Key for Code Exchange (PKCE)

For clients that cannot securely store the client secret,
for example single-page applications or mobile applications,
we need a secure method for the authorization server to verify the client.

#### Steps

1. The client generates a code verifier and a code challenge.
  - The code verifier is a cryptographically random high-entropy string.
  - The code challenge is a hashed version of the code verifier.
2. The client gets redirected to the authorization server.
  - Here, the generated code challenge is presented to the authorization server.
3. The authorization server generates an authorization code and sends it to the client.
4. The client asks the authorization server for the access token.
  - Here, the authorization code and the code verifier gets sent together.
5. The authorization server gives the access token to the client.

### Client Credentials Grant Flow

If the resource owner is the client itself, meaning that the client wants to access
the client's resource in the resource server, the client credentials grant can be used.

### Device Authorization Grant Flow

For devices that are input-constrained, for example a TV or a speaker,
the device authorization grant can be used.

### Refresh Token Grant Flow

### Implicit Grant Flow

The implicit grant flow is a simplified version of the authorization code grant flow,
that returns the access token without the authorization code. The implicit grant flow
is not recommended.

### Resource Owner Credentials Grant Flow

The resource owner credentials grant flow takes the user's authentication information directly,
and is not recommended.

## OpenID Connect (OIDC)

OpenID Connect extends the OAuth framework to support authentication by using an ID token.

### Token Management

In OAuth, access tokens and refresh tokens are used in communication.

#### Access Token

The access token is data that the client gives to the resource server to request resources.
Access tokens may be reference tokens or self-encoded tokens.

Reference tokens are random strings that contain no information and is used to direct to the
actual information stored in the database.
Reference tokens can be easily revoked by simply deleting from a database, and can easily show
a list of active tokens to the user.
Reference tokens requires storing the tokens, and the resource server must check the token's validity
by making a database lookup or a network call.
Reference tokens are good for small scale APIs with an integrated OAuth server.

Self-encoded tokens, for example JWTs, have all the necessary information stored in the token itself.
Self-encoded tokens are scalable due to better separation of concerns, but revoking tokens or getting
a list of active tokens is not easy.

Self-encoded tokens are signed by the authorization server. Information about the key is contained
within the token (for example the key ID in the JWT header), where the key information can be found
in the metadata of the authorization server. The resource server can ask the authorization server
for the public keys, and the resource server will use the key that matches the key's ID.

#### Refresh Token
Refresh token: Data that the client gives to the authorization server to get a new access token.
