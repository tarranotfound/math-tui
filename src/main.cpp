#include "math_tui/calculator.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

namespace {
void print_help(const char* program) {
    std::cout << "math-tui - a small terminal calculator\n\n"
              << "Usage: " << program << " <expression>\n"
              << "       " << program << " --help\n\n"
              << "Operators: +  -  *  /  parentheses\n";
}
}

int main(int argc, char* argv[]) {
    if (argc == 2 && (std::string(argv[1]) == "--help" ||
                      std::string(argv[1]) == "-h")) {
        print_help(argv[0]);
        return EXIT_SUCCESS;
    }

    if (argc < 2) {
        print_help(argv[0]);
        return EXIT_FAILURE;
    }

    std::string expression;
    for (int i = 1; i < argc; ++i) {
        if (!expression.empty()) expression += ' ';
        expression += argv[i];
    }

    try {
        const double result = math_tui::evaluate(expression);
        std::cout << std::setprecision(15) << result << '\n';
        return EXIT_SUCCESS;
    } catch (const math_tui::ParseError& error) {
        std::cerr << "error at position " << error.position()
                  << ": " << error.what() << '\n';
        return EXIT_FAILURE;
    }
}
