# HTTP (Hypertext Transfer Protocol)

## HTTPS (Hypertext Transfer Protocol Secure)
- HTTPS adds a layer of security on top of HTTP using TLS.

### TLS (Transport Layer Security)
- TLS is used for the purpose of having a shared private symmetric key between the server and client.
  - The private symmetric key is obtained from a key sharing process called the TLS handshake.
  - This is done because asymmetric encryption is much slower than symmetric encryption.

### Certificate Authority (CA)
- The CA is a trusted third-party entity for verifying the identity of websites.
  - MITM(Man-in-the-middle) attack without the existance of a CA.
    - The server has its own public and private key. It sends the public key to the client.
      - The attacker intercepts this response and sends the client its own public key.
    - The client encrypts a shared key using the server's public key.
      - The client actually encrypted the shared key with the attacker's public key.
      - The attacker obtains the shared key between the client and creates its own shared key between the server.
    - The server decrypts the encrypted key using the server's private key to obtain the shared key.
      - The client talks to the attacker thinking its talking to the server.

- Communication process with the CA
  - The client requests the server for its certificate.
  - The server asks the CA for a certificate by giving the server's public key.
  - The CA creates a certificate by including the following information.
    - Information on the issuer (the server) and the CA.
    - The server's public key.
    - A signature which is the server's public key encrypted using the CA's private key.
  - The CA sends the certificate to the server which gets passed down to the client. 
  - The client verifies the certificate using the CA's public key.
  - The client encrypts the shared key with the server's public key.
  - The server decrypts the encrypted key using the server's private key to obtain the shared key.

