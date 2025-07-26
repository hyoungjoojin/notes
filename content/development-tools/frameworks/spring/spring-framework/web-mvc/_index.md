+++
title = "web-mvc"
+++

# Spring Web MVC

Spring Web MVC is a web framework built on top of the Java Servlet API.

## Spring Web MVC Components

The following are the major components of Spring Web MVC.

- `DispatcherServlet`
- `HandlerMapping`
- Controller
- `ViewResolver`

The overall flow of request processing is as below.

1. Spring Web MVC follows the front-controller pattern, where all requests are passed through one
   single component, in this case its the `DispatcherServlet`.
2. After the `DispatcherServlet` receives the request, based on the request a decision is made on
   which controller should process the request.
3. A Spring controller is responsible for processing a client's request.
4. If the controller returns a view, the `ViewResolver` renders the view.

## Controller

### Annotations

- `@Controller`
- `@ResponseBody`: The result of the controller is serialized and should not be processed by the `ViewResolver`.
- `@RestController`
