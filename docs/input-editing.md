# Expression editing

The editor should maintain a clear distinction between the expression buffer and the cursor position.

- Insert text at the cursor.
- Delete before or at the cursor without corrupting adjacent characters.
- Keep cursor movement bounded by the expression length.
- Preserve the draft after parse and evaluation errors.
- Define how pasted text and unsupported characters are handled.