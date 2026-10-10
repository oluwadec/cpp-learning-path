// Topic 3: Functions
// Covers function overloading, default arguments and pass-by-reference.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o functions 03_functions.cpp
// Run:     ./functions

#include <iostream>
#include <string>

// Overloading: two functions with the same name but different parameter types.
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

// Default argument: "greeting" is optional when calling greet().
void greet(const std::string& name, const std::string& greeting = "Hello") {
    std::cout << greeting << ", " << name << '\n';
}

// Pass by reference: changes the caller's variable instead of a copy.
void doubleIt(int& x) {
    x *= 2;
}

int main() {
    std::cout << add(2, 3) << '\n';       // calls the int version -> 5
    std::cout << add(2.5, 3.1) << '\n';   // calls the double version -> 5.6

    greet("Ada");                         // uses the default greeting
    greet("Ada", "Welcome back");

    int value = 10;
    doubleIt(value);
    std::cout << "Value = " << value << '\n';  // 20

    return 0;
}
