# Evaluation behavior

The evaluator should follow the grammar's precedence and associativity rules.

- Binary operators are left-associative.
- Division by zero produces a user-facing error.
- Non-finite results should not be presented as ordinary numbers.
- Preserve precision internally for subsequent operations.
- Format displayed values separately from numeric evaluation.

Do not use string substitution or shell evaluation as an arithmetic engine.