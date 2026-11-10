# Performance considerations

A basic calculator should remain responsive without complex optimization.

- Keep parsing proportional to expression length.
- Avoid redrawing unchanged regions when the terminal library supports it.
- Bound history memory usage.
- Avoid unnecessary allocations in repeated cursor movement.
- Measure before introducing caching or more complex data structures.

Use representative long expressions and history sizes when profiling.