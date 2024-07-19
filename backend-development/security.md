# Backend Security

## Defensive Strategies
### Testing
    - Fuzz Testing: Automated testing method that injects malformed inputs into the system.

### API Contracts (Swagger/OpenAPI Definitions)
- API contracts specify how the API should behave. Security tools can use the definitions for automatic vulnerability detection.
- Tools
    - API Fuzzer
    - Runtime Analyzer

### Authorization
- Enforce authorization at the function level by applying sensible permission checks to every single endpoint.
- Enforce auditability. By making authorization logics more explicit, it can help debug security issues.
    - Even when an endpoint doesn't require any authorization, make an access level for public access and go through this logic.
- Centralize complex authorization logic. This could be in the form of a separate dedicated class or a whole service. Just don't scatter out authorization policies for every function.
- Traditional web session management is safer with the trade-off of scalability. Sometimes managing sessions might be a much better choice.

### JSON Web Tokens (JWT)
- Best Practices
    - Algorithm Verification
        - Enforce the algorithm used for the tokens, use only one single algorithm.
        - Use appropriate algorithms.
        - The best algorithm may change, therefore systems should be able to adapt to this change.
    - Encoding/Decoding
        - Do not use compression for the tokens, this may reveal plaintext information.
        - Use only UTF-8 encoding.
    - Validation Rules
        - All cryptographic operations should be validated.
        - All cryptographic inputs should be validated.
        - Validate issuer and subject claims.
        - Use and validate the audience ('aud') claim.
    - Keys
        - Keys should have sufficient entropy.
    - Claims
        - Recieved claims should be sanitized before doing operations such as database lookup.


## Vulnerabilities
### Broken Object Level Authorization (BOLA)
- Cases where some authorization information from one user works on another user.
- This happens because authorization information was not checked for user identities.

### Broken Function Level Authorization (BFLA)
- Cases where some authorization information from one function works on another function (ex. getting and deleting).
- Different functionalities should each enforce their own set of access controls.
- Solution: Check authorization permissions for each function-level actions.

### Excessive Data Exposure
- APIs should send only the neccesary information required by the client. Excessive data exposure may lead to security vulnerabilities.
- Solution: Use DTOs (Data Transfer Objects) to create the response in the backend. The schema will include only the neccesary information.

### Mass Assignment
- APIs should accept only the verified fields in the request body. Having an entire object be used in the request body may allow a user to change fields that are not expected.
- Solution: Use DTOs for request bodies.

## References
- [Getting API security right - Philippe De Ryck - NDC London 2023](https://www.youtube.com/watch?v=7UBm8QFTaq0)
- [RFC 8725](https://www.rfc-editor.org/rfc/rfc8725)

