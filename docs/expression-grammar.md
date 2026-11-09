# Expression grammar

A small initial grammar keeps parsing predictable.

```text
expression  := sum
sum         := product (('+' | '-') product)*
product     := unary (('*' | '/') unary)*
unary       := ('+' | '-') unary | primary
primary     := number | '(' expression ')'
number      := digits ('.' digits)? | '.' digits
digits      := [0-9]+
```

Whitespace may appear between tokens. Multiplication and division bind more tightly than addition and subtraction. Parentheses override precedence. Reject trailing tokens and malformed numbers rather than silently ignoring them.