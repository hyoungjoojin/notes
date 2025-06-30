+++
title = "https"
+++

# HTTPS

HTTPS is an extension over HTTP, where the data is encrypted using the TLS (Transport Layer Security)
protocol.

## Certificate Authority

The Certificate Authority (CA) is an entity that issues and validates certificates.

### Issuing Certificates

Before initiating the TLS handshake, the application server must possess a certificate issued by a CA.
The process for issuing the certificate is as below.

1. The application server creates their own private key and public key.
2. The application server gives the chosen CA their public key.
3. The CA signs the application server's public key with their private key.

The application server's public key signed with the CA's private key is the certificate.

## TLS Handshake

In order to open a secure communication channel between the server and the client, a shared private key
must exist. In order to share the private key, the TLS handshake protocol is used.

The following are the steps for the TLS 1.2 handshake protocol.

1. Client Hello

   - The client sends a request to the application server.
   - The client sends a list of supported TLS versions and encryption algorithms (cipher suite).

2. Server Hello

   - The application server chooses the TLS version and encryption algorithm.

3. Certificate

   - The application server sends their certificate.

4. Client Key Exchange

   - The client checks the certificate.
   - The client creates and sends an encrypted pre-master key.
   - The pre-master key is a generated secret key that gets encrypted using the application server's
     public key found in the certificate.

5. Change Cipher Spec

   - The server decrypts the encrypted pre-master key using their private key to get the shared key.
   - All prior messages have been open, and subsequent messages will be encrypted using the shared key.
