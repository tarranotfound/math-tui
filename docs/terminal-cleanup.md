# Terminal state cleanup

Interactive terminal programs may change terminal modes while running. Cleanup should be centralized and safe to call more than once.

Restore the previous input mode, cursor visibility, and screen state on normal exit and handled failures. Keep cleanup independent from rendering code. Test interruption paths where practical, and avoid swallowing errors that prevent the program from restoring the terminal.