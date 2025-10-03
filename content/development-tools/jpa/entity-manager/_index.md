+++
title = "entity-manager"
+++

# Entity Manager

An entity manager can be created from a `EntityManagerFactory`. The `EntityManagerFactory` is
a heavy thread safe object created once on application startup. An `EntityManager` is a lightweight
non-thread safe object that is meant to live for a single unit of work.
