+++
title = "jws"
+++

# JWS (JSON Web Signature)

JWS is a specification for digitally signing JSON data.

JWS can be used for data integrity and authenticity.
Since any modification of a JWS will invalidate the JWS, JWS provides data integrity.
Authenticity is provided since only someone who has access to the secret key may generate the JWS.


## JWS Format

A JWS is composed of a base64-encoded JOSE header, JWS payload, and a JWS signature joined by a dot.

The JOSE header contains the following parameters. The algorithm header parameter must be present,
while the other header parameters are optional.

- Algorithm ("alg"): The cryptographic algorithm used to sign the JWS.

## References

- Jones, M., Bradley, J., and N. Sakimura, "JSON Web Signature (JWS)", RFC 7515, DOI 10.17487/RFC7515, May 2015, <https://www.rfc-editor.org/info/rfc7515>.
