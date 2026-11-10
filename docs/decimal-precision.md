# Decimal precision

Define the numeric model before exposing precision controls.

Binary floating-point is convenient but cannot represent every decimal fraction exactly. If exact decimal behavior becomes a requirement, evaluate a decimal arithmetic type and its performance implications. Tests should cover values such as 0.1 + 0.2 and repeated operations. Never imply exactness when the implementation uses approximate floating-point arithmetic.