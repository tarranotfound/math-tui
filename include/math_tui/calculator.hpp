#pragma once

#include <cmath>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <string_view>

namespace math_tui {

class ParseError : public std::runtime_error {
public:
    ParseError(std::string message, std::size_t position)
        : std::runtime_error(std::move(message)), position_(position) {}

    [[nodiscard]] std::size_t position() const noexcept { return position_; }

private:
    std::size_t position_;
};

class Parser {
public:
    explicit Parser(std::string_view input) : input_(input) {}

    double parse() {
        skip_whitespace();
        if (at_end()) {
            throw ParseError("empty expression", position_);
        }

        const double result = parse_sum();
        skip_whitespace();
        if (!at_end()) {
            throw ParseError("unexpected character", position_);
        }
        if (!std::isfinite(result)) {
            throw ParseError("result is outside the supported numeric range", position_);
        }
        return result;
    }

private:
    std::string_view input_;
    std::size_t position_ = 0;

    [[nodiscard]] bool at_end() const noexcept {
        return position_ >= input_.size();
    }

    void skip_whitespace() {
        while (!at_end() && (input_[position_] == ' ' ||
               input_[position_] == '\t' || input_[position_] == '\n' ||
               input_[position_] == '\r')) {
            ++position_;
        }
    }

    bool consume(char expected) {
        skip_whitespace();
        if (!at_end() && input_[position_] == expected) {
            ++position_;
            return true;
        }
        return false;
    }

    double parse_sum() {
        double value = parse_product();
        while (true) {
            if (consume('+')) {
                value += parse_product();
            } else if (consume('-')) {
                value -= parse_product();
            } else {
                return value;
            }
        }
    }

    double parse_product() {
        double value = parse_unary();
        while (true) {
            if (consume('*')) {
                value *= parse_unary();
            } else if (consume('/')) {
                const std::size_t operator_position = position_ - 1;
                const double divisor = parse_unary();
                if (divisor == 0.0) {
                    throw ParseError("division by zero", operator_position);
                }
                value /= divisor;
            } else {
                return value;
            }
        }
    }

    double parse_unary() {
        if (consume('+')) return parse_unary();
        if (consume('-')) return -parse_unary();
        return parse_primary();
    }

    double parse_primary() {
        skip_whitespace();
        if (consume('(')) {
            const double value = parse_sum();
            if (!consume(')')) {
                throw ParseError("missing closing parenthesis", position_);
            }
            return value;
        }
        return parse_number();
    }

    double parse_number() {
        skip_whitespace();
        const std::size_t start = position_;
        bool has_digits = false;

        while (!at_end() && input_[position_] >= '0' && input_[position_] <= '9') {
            has_digits = true;
            ++position_;
        }
        if (!at_end() && input_[position_] == '.') {
            ++position_;
            while (!at_end() && input_[position_] >= '0' && input_[position_] <= '9') {
                has_digits = true;
                ++position_;
            }
        }

        if (!has_digits) {
            throw ParseError("expected a number or opening parenthesis", start);
        }

        try {
            return std::stod(std::string(input_.substr(start, position_ - start)));
        } catch (const std::out_of_range&) {
            throw ParseError("numeric literal is outside the supported range", start);
        }
    }
};

inline double evaluate(std::string_view expression) {
    return Parser(expression).parse();
}

} // namespace math_tui
