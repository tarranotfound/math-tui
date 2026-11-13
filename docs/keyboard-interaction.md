# Keyboard interaction

Keyboard behavior should be predictable and consistent across terminal emulators.

## Interaction expectations

- Number and operator keys insert at the active cursor position.
- Backspace removes the character before the cursor.
- Delete removes the character at the cursor.
- Left and right arrows move the cursor without changing the expression.
- Enter requests evaluation.
- Escape dismisses transient help or returns to the main view when appropriate.

Document any key that differs from common terminal conventions.
