# Architecture overview

The calculator should keep its arithmetic core independent from terminal rendering.

## Main boundaries

- **Input layer:** receives key and cursor events and updates the editable expression.
- **Parser:** converts validated expression text into a structured representation.
- **Evaluator:** computes a result from that representation.
- **Presentation layer:** renders the expression, result, help text, and errors.
- **Application state:** coordinates the active expression and navigation history.

## Design principle

Keep parsing and evaluation deterministic and testable without starting a terminal session. The terminal interface should consume their results rather than reimplement arithmetic rules.
