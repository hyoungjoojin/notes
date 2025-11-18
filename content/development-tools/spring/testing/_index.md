+++
title = "testing"
+++

# Testing Spring Applications

## Spring TestContext Framework

The Spring TestContext Framework caches application contexts between tests to improve test performance.
This is based on the context configuration, so if two tests use the same configuration, they will share the same context.
Adding mock beans, changing properties, or modifying the context configuration will create a new context and therefore
a new application context will be created for the test.
Due to this, it is best to avoid annotations like `@ActiveProfiles`, `@MockitoBean`, or `@DirtiesContext`.

Shared contexts can make the tests faster, but the tests will share the state and therefore each test must clean up context
state to avoid interference between tests.
`@DirtiesContext` can fix this, but it is better to manually clean up the state to avoid creating new contexts using
`@BeforeEach` or `@AfterEach` methods.

The context cache is a LRU cache with a default size of 32.

## Spring Boot Testing

Spring Boot provides the `@SpringBootTest` annotation.
`@SpringBootTest` is annotated with `@ExtendWith(SpringExtension.class)`, which integrates the Spring TestContext Framework
into JUnit 5 (`@ExtendWith` is a JUnit annotation).

### Web Environment

The `@SpringBootTest` annotation provides configuration for `webEnvironment`.
This is defaulted to `WebEnvironment.MOCK`, which provides a mock server that does not start up a real server.
This can be changed to `RANDOM_PORT` or `DEFINED_PORT` to start up a real server on a random or defined port respectively.
It is not advised to use `DEFINED_PORT` since it can lead to port conflicts when running tests.
If we use a random port, the port can be injected using the `@LocalServerPort` annotation.
Openning up a real server is useful for integration tests that test the entire application stack.

### Test Slices

Spring Boot provides test slice annotations, which are annotations that only contain a specific layer of the entire context.
For example, `@DataJpaTest` only contains the JPA layer of the context and `@WebMvcTest` only contains the web layer of the
context.

These annotations are faster since they only load a part of the context, but since not all beans are loaded, the required
beans must be either mocked of stubbed.
If the required beans are not mocked or stubbed, the tests will fail.

## Web Layer Testing

### MockMVC

The web layer can be tested using MockMVC.
In newer versions of Spring Boot, the `MockMvcTester` class can be used for a more fluent API that is similar to RestClient.

```java
@AutoConfigureMockMvc
class MockMVCTest {

  @Autowired MockMvcTester mockMvc;

  @Test
  public void testEndpoint() throws Exception {
    mockMvcTester
        .get()
        .uri("/api/endpoint")
        .exchange()
        .expectStatus()
        .isOk()
        .expectBody(String.class);
  }
}
```

## Testing Security Features

Spring security provides support for testing security features.

The `@WithMockUser` annotation can be used to mock an authenticated user for testing purposes.

When using MockMVC, the `SecurityMockMvcRequestPostProcessors` class can be used to mock security features.

```java
@SpringBootTest
public class SecurityTest {

  @Autowired MockMvcTester mockMvc;

  @Test
  public void secureEndpoint_unauthorized() throws Exception {
    mockMvc.get("/").andExpect(status().isUnauthorized());
  }

  @Test
  @WithMockUser
  public void secureEndpoint_authorized() throws Exception {
    mockMvc.get("/").andExpect(status().isOk());
  }

  @Test
  public void oidc() throws Exception {
    mockMvc
        .get("/")
        .with(
            SecurityMockMvcRequestPostProcessors.oidcLogin()
                .idToken(token -> token.claim("email", "")))
        .andExpect(status().isOk());
  }

  @Test
  public void csrf() throws Exception {
    mockMvc.post("/").with(SecurityMockMvcRequestPostProcessors.csrf()).andExpect(status().isOk());
  }
}
```

## External Libraries

The Spring testing library includes libraries like JUnit, Mockito, Hamcrest, AssertJ, and more by default.
This section covers these libraries, and also other external libraries that can be added to the application.

### Mockito

Mockito is used for mocking objects in tests.

Mockito can be configured with `RETURNS_DEEP_STUBS` to allow deep stubbing, which means the chained method
will be mocked instead of having to mock each method in the chain individually.

```java
@SpringBootTest
public class MockitoTest {

  @MockitoBean private BookRepository bookRepository;

  @InjectMocks private BookService bookService;

  @Test
  void test() {
    when(bookRepository.findById(1L))
        .thenReturn(Optional.of(new Book(1L, "Mockito in Action")))
        .thenReturn(Optional.empty())
        .thenThrow(new RuntimeException("Database error"));

    assertThat(bookService.getBookTitle(1L)).isEqualTo("Mockito in Action");
    assertThat(bookService.getBookTitle(1L)).isNull();
    assertThatThrownBy(() -> bookService.getBookTitle(1L))
        .isInstanceOf(RuntimeException.class)
        .hasMessage("Database error");

    when(bookRepository.save(any(Book.class)))
        .thenAnswer(
            invocation -> {
              Book book = invocation.getArgument(0);
              book.setId(2L);
              return book;
            });

    assertThat(bookService.addBook("New Book").getId()).isEqualTo(2L);
  }

  @Test
  void deepStubbing() {
    var client = mock(RestClient.class, RETURNS_DEEP_STUBS);
    when(client.get().uri("/").retrieve().bodyToMono(String.class).block())
        .thenReturn("mocked response");
  }
}
```

### AssertJ

AssertJ is a fluent assertion library.
AssertJ is highly readable and can use chained assertions for better clarity.

```java
assertThat(actualList)
    .isNotNull()
    .hasSize(3)
    .contains("item1", "item2")
    .doesNotContain("item4")
    .allMatch(item -> item.startsWith("item"));
```

AssertJ can be extended to support custom assertions as well.
This can be done by extending the `AbstractAssert` class.

### Testcontainers

Testcontainers is a container-based testing library.

Configuring Testcontainers require configuring the containers and modifying the properties.

The following are two methods to configure Testcontainers in Spring Boot tests.
The first configuration class sets up a generic container running Nginx.
We can use `@DynamicPropertySource` to modify the properties of the application context based on the container's properties.

The second configuration class uses static containers with the `@Container` annotation.
The `@ServiceConnection` sets up configuration properties automatically for the container.
This annotation can be used for supported containers, for non-supported containers, the properties must be set manually using
`@DynamicPropertySource`.

This first method starts up a new container for every test context making the tests run slower.
The second method shares the containers between test contexts making the tests run faster, but the tests must
manually clean the state of the containers.

```java
@TestConfiguration
class TestcontainersConfig {

  @Bean
  @DynamicPropertySource
  GenericContainer<?> nginxContainer(DynamicPropertyRegistry registry) {
    var container = new GenericContainer<>("nginx:latest").withExposedPorts(80);
    registry.add("nginx.port", container::getFirstMappedPort);
    return container;
  }
}

@TestConfiguration
@Testcontainers
class TestcontainersConfig {

  @Container
  private static final PostgreSQLContainer<?> postgresContainer =
      new PostgreSQLContainer<>("postgres:15-alpine")
          .withDatabaseName("testdb")
          .withUsername("testuser")
          .withPassword("testpass");

  @Bean
  @ServiceConnection
  PostgreSQLContainer<?> postgresContainer() {
    return postgresContainer;
  }
}
```

`@DataJpaTest` defaults to using an in-memory database, but even if Testcontainers is configured, it will still try to
use the in-memory database.
The following configuration is required to override this behavior and use the container database instead.

```java
@DataJpaTest
@AutoconfigureTestDatabase(replace = AutoconfigureTestDatabase.Replace.NONE)
@Import(TestcontainersConfig.class)
class MyRepositoryTest {}
```

### HtmlUnit

HtmlUnit is a headless browser testing library.
It can be used to test simple web applications by simulating a real browser.

```java
@AutoConfigureMockMvc
class MockMvcTests {

  @Autowired private WebClient webClient;

  @Test
  void addTodo() throws Exception {
    HtmlPage page = webClient.getPage("/todos/new");
    page.querySelector("input[name='title']").type("New Todo");
    HtmlForm form = page.getForms().get(0);
    HtmlPage resultPage = form.getButtonByName("submit").click();
    assertThat(resultPage.asText()).contains("New Todo");
  }
}
```

This can work for simple applications, but complex web applications will be harder to test.
In these cases it is better to use a real browser testing tool like Selinium, or a dedicated Javascript testing framework
like Playwright or Cypress.

### Awaitility

Awaitility is a library for testing asynchronous code using a fluent API.
