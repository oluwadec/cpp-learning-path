// Topic 10: Recursion
// A recursive function calls itself. Every recursive function needs a base case
// (when to stop) and a recursive case (how to get closer to the base case).
//
// Compile: g++ -std=c++17 -Wall -Wextra -o recursion 10_recursion.cpp
// Run:     ./recursion

#include <iostream>
#include <string>

// Counts down from n to 1.
void countdown(int n) {
    if (n == 0) {                       // base case: stop here
        std::cout << "Liftoff!\n";
        return;
    }
    std::cout << n << ' ';
    countdown(n - 1);                   // recursive case: a smaller problem
}

// factorial(4) = 4 * 3 * 2 * 1 = 24
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Fibonacci: 0 1 1 2 3 5 8 13 ...
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Adds up the digits of a number: 1234 -> 1 + 2 + 3 + 4 = 10
int sumDigits(int n) {
    if (n < 10) {
        return n;
    }
    return (n % 10) + sumDigits(n / 10);
}

// Raises a number to a power: power(2, 5) = 32
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return base * power(base, exponent - 1);
}

// Reverses a string by moving its first letter to the end.
std::string reverseText(const std::string& text) {
    if (text.length() <= 1) {
        return text;
    }
    return reverseText(text.substr(1)) + text[0];
}

int main() {
    std::cout << "Countdown: ";
    countdown(5);

    std::cout << "factorial(5) = " << factorial(5) << '\n';

    std::cout << "First 10 Fibonacci numbers: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << fibonacci(i) << ' ';
    }
    std::cout << '\n';

    std::cout << "sumDigits(1234) = " << sumDigits(1234) << '\n';
    std::cout << "power(2, 10) = " << power(2, 10) << '\n';
    std::cout << "reverseText(\"recursion\") = " << reverseText("recursion") << '\n';

    return 0;
}
