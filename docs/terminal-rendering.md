# Terminal rendering

Rendering should be isolated from input handling and arithmetic.

## Rules

- Redraw only the regions that need updating when practical.
- Keep prompts and result areas visually distinct.
- Handle narrow terminal widths without writing beyond the viewport.
- Restore terminal state when the application exits.
- Keep color optional so the interface remains readable in monochrome terminals.

Rendering code should receive state and produce the view; it should not own calculation logic.
