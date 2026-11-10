# Continuous integration

A future CI workflow should validate changes consistently.

Suggested checks:

1. Build from a clean environment.
2. Run parser and evaluator unit tests.
3. Run formatting or lint checks when configured.
4. Verify documentation examples where automation is practical.

Keep CI focused on reproducible checks and document any platform-specific jobs.