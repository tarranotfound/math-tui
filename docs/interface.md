# Interface principles

The interface should prioritize the expression being edited and its result.

- Use a compact layout that works in narrow terminals.
- Keep prompts and status messages visually distinct.
- Never rely on color alone to communicate an error.
- Preserve the current expression when evaluation fails.
- Recalculate layout after terminal resize events.

Avoid decorative panels that consume space without adding information.