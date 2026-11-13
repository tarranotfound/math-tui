# Error message guidelines

Errors should explain what went wrong without overwhelming the calculator display.

## Guidelines

- Use short, plain-language messages.
- Identify the relevant token or position when possible.
- Distinguish syntax errors from evaluation errors.
- Keep the current expression available so it can be corrected.
- Do not expose internal implementation details in user-facing text.

Detailed diagnostic context can be reserved for tests or development logs.
