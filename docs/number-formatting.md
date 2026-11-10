# Number formatting

Keep numeric formatting separate from evaluation so presentation choices never change arithmetic results.

- Avoid unnecessary trailing zeroes.
- Preserve a decimal point only when it communicates precision.
- Use a consistent policy for very large and very small values.
- Document whether displayed precision is rounded or truncated.
- Keep the full internal value available to later calculations.