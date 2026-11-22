#include "math_tui/calculator.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string_view>

namespace {
int failures = 0;

void expect_near(std::string_view expression, double expected) {
    try {
        const double actual = math_tui::evaluate(expression);
        if (std::abs(actual - expected) > 1e-10) {
            std::cerr << "FAIL: " << expression << " expected " << expected
                      << ", got " << actual << '\n';
            ++failures;
        }
    } catch (const std::exception& error) {
        std::cerr << "FAIL: " << expression << " threw " << error.what() << '\n';
        ++failures;
    }
}

void expect_error(std::string_view expression) {
    try {
        (void)math_tui::evaluate(expression);
        std::cerr << "FAIL: expected an error for " << expression << '\n';
        ++failures;
    } catch (const math_tui::ParseError&) {
        // Expected.
    }
}
}

int main() {
    expect_near("2 + 3", 5.0);
    expect_near("8 - 3 * 2", 2.0);
    expect_near("(8 - 3) * 2", 10.0);
    expect_near("7 / 2", 3.5);
    expect_near("-4 + 6", 2.0);
    expect_near("1.25 + .75", 2.0);
    expect_near("--5", 5.0);
    expect_near(" 2 + (3 * 4) ", 14.0);

    expect_error("");
    expect_error("1 / 0");
    expect_error("(2 + 3");
    expect_error("2 +");
    expect_error("2 3");
    expect_error(".");

    if (failures != 0) {
        std::cerr << failures << " test(s) failed\n";
        return EXIT_FAILURE;
    }
    std::cout << "All calculator tests passed\n";
    return EXIT_SUCCESS;
}
