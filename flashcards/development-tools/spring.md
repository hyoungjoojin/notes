# Spring

> 7

What happens when you call `save` on an entity in Spring Data JPA?

--

When you call `save` on an entity in Spring Data JPA, the framework first checks the state of the entity to determine
whether it is new or already persisted. Depending on this state, it will either call `persist` for new entities or
`merge` for existing ones.

The state detection can be based on several factors, such as whether the entity's identifier (`@Id`) is null,
whether a version field (`@Version`) is null, or if the entity implements the `Persistable` interface and its
`isNew` method returns true.

--

> 7

What is OSIV in the context of Spring Data JPA?

--

OSIV (Open Session In View) is a design pattern used in Spring Data JPA to manage the lifecycle of the Hibernate
Session throughout the entire request processing cycle. It keeps the Hibernate Session open during the rendering
of the view, allowing for lazy loading of associated entities even after the initial database transaction has completed.

This can lead to performance issues and potential memory leaks if not managed properly, as it may result in
unintended database access during view rendering and unclosed sessions even after the transaction is complete.

--
