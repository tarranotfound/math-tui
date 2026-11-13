# History data model

Each history entry should preserve enough information to review a previous calculation.

## Suggested entry fields

- Original expression text.
- Successful numeric result, when available.
- Error category, when evaluation failed.
- A stable ordering index or timestamp.

History navigation should not modify stored entries. If a previous expression is restored for editing, treat the editor buffer as a separate copy.
