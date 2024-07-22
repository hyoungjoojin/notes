# OAuth (Open Authorization)

## OAuth 2.0 Roles
- Resource Owner: The owner of the protected resources.
- Resource Server: The server that stores the protected resources.
- Client: The application trying to access the protected resources.
- Authorization Server: The server that checks the client's access permissions and generates access tokens.

## OAuth Flow
1. The resource owner asks the client to do some action.
2. The client asks the authorization server for authorization using the client ID and requested scope.
3. The authorization server requests the user for permission.
4. The user approves the request.
5. The authorization server grants permission to the client and gives the authorization code.
6. The client uses the authorization code, client ID, and client secret to request the authorization server for an access token.
7. The authorization server gives the client the access token.
8. The client accesses the resources using the access token.
