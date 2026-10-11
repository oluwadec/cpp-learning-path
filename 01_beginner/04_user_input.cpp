// Topic 4: User Input
// Shows how to read numbers and text from the keyboard with std::cin and std::getline.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o user_input 04_user_input.cpp
// Run:     ./user_input

#include <iostream>
#include <string>

int main() {
    // --- Reading a single word ---
    std::string firstName;
    std::cout << "Enter your first name: ";
    std::cin >> firstName;              // stops reading at the first space

    // --- Reading numbers ---
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;

    double height;
    std::cout << "Enter your height in metres: ";
    std::cin >> height;

    // --- Reading a whole line (with spaces) ---
    std::cin.ignore(1000, '\n');        // throw away the leftover newline first
    std::string hobby;
    std::cout << "Describe your favourite hobby: ";
    std::getline(std::cin, hobby);

    // --- Using what we read ---
    std::cout << "\nHello, " << firstName << "!\n";
    std::cout << "Next year you will be " << age + 1 << ".\n";
    std::cout << "Your height is " << height * 100 << " cm.\n";
    std::cout << "Your hobby: " << hobby << '\n';

    // --- A tiny calculator ---
    double x, y;
    std::cout << "\nEnter two numbers to add: ";
    std::cin >> x >> y;                 // you can read several values in one line
    std::cout << x << " + " << y << " = " << x + y << '\n';

    return 0;
}
