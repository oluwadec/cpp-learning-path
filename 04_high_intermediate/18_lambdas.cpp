// Topic 18: Lambdas and std::function
// A lambda is a small unnamed function you write right where you need it.
// Syntax: [capture](parameters) { body }
//
// Compile: g++ -std=c++17 -Wall -Wextra -o lambdas 18_lambdas.cpp
// Run:     ./lambdas

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

// A function that takes another function as a parameter.
void applyToAll(std::vector<int>& values, std::function<int(int)> action) {
    for (int& v : values) {
        v = action(v);
    }
}

int main() {
    // --- The simplest lambda ---
    auto sayHi = []() {
        std::cout << "Hi from a lambda!\n";
    };
    sayHi();

    // --- A lambda with parameters and a return value ---
    auto add = [](int a, int b) {
        return a + b;
    };
    std::cout << "add(3, 4) = " << add(3, 4) << '\n';

    // --- Capturing a variable from outside ---
    int bonus = 5;
    auto addBonus = [bonus](int score) {    // [bonus] copies bonus into the lambda
        return score + bonus;
    };
    std::cout << "addBonus(70) = " << addBonus(70) << '\n';

    // --- Capturing by reference lets the lambda change the outside variable ---
    int counter = 0;
    auto increment = [&counter]() {
        ++counter;
    };
    increment();
    increment();
    increment();
    std::cout << "counter = " << counter << '\n';

    // --- Lambdas with algorithms ---
    std::vector<int> nums = {5, 12, 8, 21, 3, 16};

    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;                       // biggest first
    });
    std::cout << "\nSorted: ";
    for (int n : nums) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    int evens = std::count_if(nums.begin(), nums.end(), [](int n) {
        return n % 2 == 0;
    });
    std::cout << "Even numbers: " << evens << '\n';

    // --- Passing a lambda to our own function ---
    applyToAll(nums, [](int n) { return n * 2; });
    std::cout << "Doubled: ";
    for (int n : nums) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    // --- std::function stores any function or lambda ---
    std::function<double(double)> halve = [](double x) { return x / 2; };
    std::cout << "halve(9) = " << halve(9) << '\n';

    // --- A little calculator using a vector of named lambdas ---
    std::vector<std::pair<std::string, std::function<int(int, int)>>> operations = {
        {"add",      [](int a, int b) { return a + b; }},
        {"subtract", [](int a, int b) { return a - b; }},
        {"multiply", [](int a, int b) { return a * b; }}
    };

    std::cout << "\nOperations on 12 and 4:\n";
    for (const auto& op : operations) {
        std::cout << "  " << op.first << ": " << op.second(12, 4) << '\n';
    }

    return 0;
}
