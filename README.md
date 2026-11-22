# math-tui

A small C++20 terminal calculator with a keyboard-friendly command-line interface.

## Features

- Addition, subtraction, multiplication, and division
- Parentheses and unary plus/minus
- Standard operator precedence
- Whitespace between tokens
- Position-aware parse errors
- Automated tests with CTest

The current version is a command-line expression calculator. A full-screen,
cursor-driven TUI and interactive history are planned, not yet implemented.

## Build

Requires CMake 3.20+ and a C++20 compiler.

```sh
cmake -S . -B build
cmake --build build
```

## Run

```sh
./build/math-tui "8 - 3 * 2"
# 2

./build/math-tui "(8 - 3) * 2"
# 10

./build/math-tui --help
```

Pass the expression as one quoted argument when it contains spaces. The
calculator uses binary floating-point (`double`), so decimal results are
approximate rather than exact.

## Test

```sh
ctest --test-dir build --output-on-failure
```

## Supported grammar

```text
expression := sum
sum        := product (('+' | '-') product)*
product    := unary (('*' | '/') unary)*
unary      := ('+' | '-') unary | primary
primary    := number | '(' expression ')'
number     := digits ('.' digits)? | '.' digits
```

Division by zero, malformed expressions, and trailing characters are reported
as errors. See [docs](docs/) for design notes and planned behavior.
