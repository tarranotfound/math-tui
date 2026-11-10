# Command-line options

If command-line options are added, keep them small and discoverable.

Potential options include `--help`, `--version`, and a non-interactive expression argument. Define exit codes for successful evaluation, invalid input, and runtime failure. Ensure command-line mode does not initialize interactive terminal features unnecessarily.