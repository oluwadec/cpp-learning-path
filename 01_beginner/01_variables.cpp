// Topic 1: Variables, Types and Operators
// Shows the basic data types, how to print them, and the arithmetic operators.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o variables 01_variables.cpp
// Run:     ./variables

#include <iostream>
#include <string>

int main() {
    // --- Basic data types ---
    int age = 20;               // whole numbers
    double gpa = 3.80;          // decimal (floating-point) numbers
    char grade = 'A';           // a single character
    bool passed = true;         // true or false
    std::string name = "Ada";   // text (needs the <string> header)

    std::cout << name << " is " << age << " years old, GPA: " << gpa << '\n';
    std::cout << "Grade: " << grade
              << ", passed: " << std::boolalpha << passed << '\n';
    std::cout << "Size of int: " << sizeof(int) << " bytes\n";

    // --- Arithmetic operators ---
    int a = 17;
    int b = 5;

    std::cout << "\nArithmetic with a = " << a << " and b = " << b << '\n';
    std::cout << "a + b = " << a + b << '\n';
    std::cout << "a - b = " << a - b << '\n';
    std::cout << "a * b = " << a * b << '\n';
    std::cout << "a / b = " << a / b << "  (integer division drops the decimal)\n";
    std::cout << "a % b = " << a % b << "  (remainder)\n";
    std::cout << "a / (double)b = " << a / static_cast<double>(b) << '\n';

    return 0;
}
