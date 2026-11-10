# Input safety

Treat expression text as data, never as executable shell or language source.

- Parse only the explicitly supported grammar.
- Do not pass expressions to a shell.
- Avoid dynamic code evaluation.
- Reject unsupported tokens clearly.
- Keep file access and configuration parsing separate from expression evaluation.

These constraints keep the calculator's behavior narrow and easier to audit.