# Evaluator contract

The evaluator accepts a valid parsed expression and returns either a numeric result or a typed evaluation error.

## Expected behavior

- Apply operators according to the parsed structure.
- Report division by zero explicitly.
- Detect results that are not finite.
- Avoid silently converting invalid input into zero.
- Keep error reporting separate from terminal rendering.

The evaluator should not read keyboard input, print output, or mutate the expression history.
