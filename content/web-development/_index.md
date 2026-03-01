+++
title = "web-development"
+++

# Web Development

## Email Verification

### Things To Consider

- Email verification is necessary for preventing spam and ensuring that users do
  not create multiple accounts to abuse the system.
- Email verification should handle alias emails like subaddressing or plus
  addressing, which allows users to create multiple email addresses that point
  to the same inbox. For example, email addresses like `user@gmail.com` and
  `user+1@gmail.com` go to the same inbox.
- Requiring email verification upfront can lead to a poor user experience. In
  order to reduce friction, email verification should be deferred until the user
  tries to access features that require a verified email address. Another way
  would be to ask for email verification after a certain amount of time has
  passed since the account has been created.
