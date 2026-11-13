# Parser design

The parser should turn an expression string into a structured representation before evaluation.

## Responsibilities

- Recognize numeric literals and supported operators.
- Respect parentheses and operator precedence.
- Reject malformed sequences with useful error positions.
- Distinguish unary signs from binary addition and subtraction.
- Avoid evaluating input while it is being tokenized.

A small tokenizer followed by a precedence-aware parser is a suitable starting point. Keep the grammar documented alongside parser tests.
