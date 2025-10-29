+++
title = "updates"
+++

# JPA Updating Entities

## Dynamic Updates

If we prefer to update columns that actually have been changed, we can add Hibernate's `@DynamicUpdate`
annotation to the entity so that Hibernate will only call updates for the fields that actually
have been changed.
