# Terminal resizing

The layout should adapt when terminal dimensions change.

- Re-read terminal dimensions after a resize event.
- Keep the expression editor visible at small sizes.
- Hide optional history details before clipping important controls.
- Avoid writing outside current screen bounds.
- Restore terminal state on normal exit and handled errors.

Test both shrinking and growing the terminal while the application is running.