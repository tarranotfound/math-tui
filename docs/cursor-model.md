# Expression cursor model

The expression editor should track a cursor position independently from the rendered screen coordinates.

## Invariants

- The cursor position is always within the expression bounds.
- Insertion occurs at the logical cursor position.
- Deletion updates the cursor without skipping adjacent characters.
- Rendering translates the logical position into a terminal cell position.
- Resizing the terminal must not change the expression or logical cursor position.

Test cursor behavior with empty, one-character, and long expressions.
