# Terminal resize behavior

The interface should remain usable when the terminal dimensions change.

## Expected behavior

- Read the new terminal dimensions after a resize event.
- Recalculate layout boundaries before drawing.
- Preserve the active expression, cursor position, and history.
- Avoid writing outside the visible terminal area.
- Provide a compact layout when the available width is limited.

Resize handling belongs to the presentation layer and should not affect arithmetic results.
