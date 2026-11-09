# Testing strategy

Prioritize deterministic tests for the expression parser and evaluator.

## Parser cases
- Operator precedence and left associativity.
- Nested and unmatched parentheses.
- Unary plus and minus.
- Decimal and integer literals.
- Empty input and trailing tokens.

## Evaluator cases
- Basic arithmetic operations.
- Division by zero.
- Negative values and fractional results.
- Large values and non-finite results.

Keep terminal interaction tests separate from pure arithmetic tests.