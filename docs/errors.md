# Error handling

Errors should explain what the user can do next without discarding their work.

Suggested categories: empty expression, unexpected token, missing closing parenthesis, invalid numeric literal, division by zero, and result outside the supported numeric range.

Where possible, associate a parse error with the character position so the interface can move the cursor to the relevant location.