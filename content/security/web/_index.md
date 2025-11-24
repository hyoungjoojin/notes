+++
title = "web security"
+++

# Web Security

## Web Security Concepts

### Cookies

Cookies are small pieces (maximum 4KB) of encoded data that are sent between the browser and the server to maintain state.
Cookies can be set by the server using the `Set-Cookie` header, and the browser sends cookies to the server automatically
in a `Cookie` header.

However, the browser does not send all cookies in its header, this choice is determined by the attributes of the cookie.
These attributes can be set by the server when creating the cookie.

- Domain
- Path
- Expire & Max-Age
- Secure
- HttpOnly
- SameSite

**Domain**
A cookie is sent only if the requested domain matches or is a subdomain of the domain attribute of the cookie.

**Path**
A cookie is sent only if the requested path is or is a subpath of the cookie's path attribute.

**Expiration**
The expire attribute and max-age attributes can determine when a cookie expires.
If a cookie is expired, it is removed from the browser and the cookies will not be sent to the server.

**Secure**
If the secure attribute is set, the cookie is only sent over HTTPS connections.

**HttpOnly**
HttpOnly cookies can only be accessed by the browser and is not accessible via Javascript APIs.
This attribute is required for preventing XSS attacks.

**SameSite**
This attribute defines whether or not a cookie should be sent with cross-site requests.
This attribute is required for preventing CSRF attacks.

Two websites are considered same-sites if they have the same domain until the level below the effective top-level domain
(ex. for https://www.google.com, https://login.google.com is a same site but https://www.apple.com is not).

SameSite can have one of three values: Strict, Lax, or None.

- Strict: The cookie is only sent with same-site requests.
- Lax: The cookie can be sent with some cross-site requests, only if they are in a secure HTTP method and the request
  is made on the highest level (iframes are excluded).
- None: The cookie is sent with all requests. The Secure attribute must be set.

### Same-Origin Policy (SOP)

The Same-Origin Policy (SOP) states that a website can only access resources from the same origin.
An origin is defined as the combination of the protocol, domain name (host name), and port.
SOP restricts cross-origin requests, which are scripts running on one origin accessing data from another origin.
SOP is built into web browsers and it intercepts and blocks cross-origin requests made by web applications.

SOP policies do allow the following things.

- Cross-Origin Resource Embeddings: Resources like images, iframes, stylesheets, and scripts can be embedded from other origins.
  - Servers can use CSP (Content Security Policy) headers to prevent cross-site resource embeddings.
  - Cross-origin iframe embeddings are possible, but the embedded iframe and parent page cannot interact with each other.
- Cross-Origin Write Requests: Links, redirects, form submissions are typically allowed.
  - The response of the request cannot be accessed unless CORS is configured on the server.

### Cross-Origin Resource Sharing (CORS)

Any cross-origin request made by a web application is intercepted by the browser due to SOP.
Cross-Origin Resource Sharing (CORS) is a mechanism to relax this restriction by allowing servers to configure which origins
are allowed to make cross-origin requests.

After the intervention by the browser, the browser sends a CORS preflight request to ask the server if it is allowed to make
a cross-origin request to the server.
A CORS preflight request is an HTTP OPTIONS requests that includes the headers `Origin`, `Access-Control-Request-Method`,
and an optional `Access-Control-Request-Headers`.
A preflight request never sends credentials.

The origin information is included in the `Origin` header of the request.
The value of the origin header can be one of the following.

- If the request is not a cross-origin request, the `Origin` header is not included.
- If the origin header's value is a wildcard (`*`), then the request is a simple cross-origin request that does not contain
  credentials.
- Otherwise, the origin header specifies the origin of the requesting site. This value should contain all three parts of the
  origin(protocol, domain, port) and should not contain a traling slash and a partial wildcard.

The `Access-Control-Request-Method` header specifies the HTTP method of the actual request that will be made.

The optional `Access-Control-Request-Headers` header specifies any headers that will be included in future requests.

The response to a CORS preflight request includes the following information.
Successful responses to preflight requests will have an HTTP status code of 200 or 204.

- `Access-Control-Allow-Origin`: This header specifies which origin is allowed to access the resource.
  The value can be either a specific origin or a wildcard (`*`) to allow any origin.
- `Access-Control-Allow-Methods`: This header specifies which HTTP methods are allowed for cross-origin requests.
- `Access-Control-Allow-Headers`: This header specifies which headers can be used in the actual request.
- `Access-Control-Allow-Credentials`: If the server allows credentials such as cookies or HTTP authentication, the server
  can include this information by setting this header to `true`.

Not all cross-origin requests trigger a CORS preflight request.

## Web Security Vulnerabilities

### CSRF

CSRF (Cross-Site Request Forgery) is a web security vulnerability where an attacker can force an authenticated user
to do some unwanted action on a web application.
This happens because the browser automatically includes credentials associated with the site when sending a request.

CSRF attacks target state-changing requests only, since responses to malicious requests are not visible to the attacker.
It is possible for the attacker to read the response, however, in attacks called login CSRF.
Login CSRF attacks force a non-authenticated user to log into an account that the attacker controls.
Credentials entered by the user will then be visible to the attacker.

CSRF attacks are only possible if the session is handled by cookies, the victim is authenticated, and there are no
unpredictable request parameters.

#### CSRF Exploitations

**GET-based CSRF**

When a GET operation on an application is a state-changing operation, the victim can either be tricked into clicking a link
(ex. `<a href="malicious_url" >Link</a>`) or opening an image that automatically sends a GET request to the target application
by having the source attribute be the malicious URL (ex. `<img src="malicious_url" width="0" height="0" border="0" />`).

**POST-based CSRF**

POST-based operations can be exploited by using a hidden form that automatically submits itself using JavaScript.

```html
<html>
  <body onload="document.forms[0].submit()">
    <form action="malicious_url" method="POST">
      <input type="hidden" name="email" value="" />
    </form>
  </body>
</html>
```

## CSRF Protection

CSRF can be prevented using the following steps.

First, if the application framework has built-in CSRF protection, it should be used.
Frameworks like Spring, .NET, Django, and Rupy on Rails all have built-in CSRF protection.

These application frameworks use the most recommended CSRF protection method, the synchronizer token pattern,
which is to use a CSRF token.
CSRF tokens are server-side generated random tokens that are associated with the user's session.
CSRF tokens can be generated either for each user session or for each request.
Per-request tokens are more secure, but they have limitations such as not being able to use the back button or use multiple
tabs.
Obviously, the CSRF token should not be stored in cookies.
Servers must check for CSRF token leaks in logs or in the URL since these can easily be logged.

Finally, Cross-Site Scripting (XSS) attacks can be used to steal CSRF tokens, and therefore XSS protection should be
implemented as well for proper CSRF protection.
