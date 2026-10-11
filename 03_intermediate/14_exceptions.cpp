// Topic 14: Exceptions
// Exceptions let a function report that something went wrong, and let the caller
// decide how to handle it. Use try, throw and catch.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o exceptions 14_exceptions.cpp
// Run:     ./exceptions

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// Throws an exception when the divisor is zero.
double divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("cannot divide by zero");
    }
    return a / b;
}

// Throws when the age does not make sense.
void checkAge(int age) {
    if (age < 0 || age > 120) {
        throw std::invalid_argument("age must be between 0 and 120");
    }
    std::cout << "Age " << age << " is valid\n";
}

// Our own exception type.
class OutOfStockError : public std::runtime_error {
public:
    OutOfStockError(const std::string& item)
        : std::runtime_error(item + " is out of stock") {}
};

void buyItem(const std::string& item, int stock) {
    if (stock == 0) {
        throw OutOfStockError(item);
    }
    std::cout << "Bought " << item << '\n';
}

int main() {
    // --- Basic try / catch ---
    try {
        double first = divide(10, 4);
        std::cout << "10 / 4 = " << first << '\n';

        double second = divide(10, 0);          // throws here, so we jump to catch
        std::cout << "10 / 0 = " << second << '\n';
        std::cout << "This line never runs\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Error caught: " << e.what() << '\n';
    }

    // --- Different exception types ---
    try {
        checkAge(25);
        checkAge(-5);                   // throws here
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid input: " << e.what() << '\n';
    }

    // --- Our own exception ---
    try {
        buyItem("Bread", 12);
        buyItem("Milk", 0);             // throws here
    } catch (const OutOfStockError& e) {
        std::cout << "Sorry: " << e.what() << '\n';
    }

    // --- Standard library functions throw too ---
    std::vector<int> numbers = {1, 2, 3};
    try {
        std::cout << numbers.at(10) << '\n';    // at() checks the index
    } catch (const std::out_of_range& e) {
        std::cout << "Bad index: " << e.what() << '\n';
    }

    // --- A catch-all for anything else ---
    try {
        throw 42;                       // you can even throw plain values
    } catch (...) {
        std::cout << "Caught something unexpected\n";
    }

    std::cout << "Program finished normally\n";
    return 0;
}
