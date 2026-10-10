// Topic 2: Control Flow
// Covers if / else if / else, switch, for, while and range-based for loops.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o control_flow 02_control_flow.cpp
// Run:     ./control_flow

#include <iostream>
#include <vector>

int main() {
    // --- if / else if / else ---
    int score = 72;

    if (score >= 70) {
        std::cout << "Grade: A\n";
    } else if (score >= 60) {
        std::cout << "Grade: B\n";
    } else {
        std::cout << "Grade: C or below\n";
    }

    // --- switch ---
    int day = 3;

    switch (day) {
        case 1: std::cout << "Monday\n";    break;
        case 2: std::cout << "Tuesday\n";   break;
        case 3: std::cout << "Wednesday\n"; break;
        case 4: std::cout << "Thursday\n";  break;
        case 5: std::cout << "Friday\n";    break;
        default: std::cout << "Unknown day\n"; break;
    }

    // --- for loop with continue ---
    std::cout << "Numbers 1 to 5 (skipping 4): ";
    for (int i = 1; i <= 5; ++i) {
        if (i == 4) {
            continue;  // skip the rest of this round
        }
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // --- while loop ---
    std::cout << "Countdown: ";
    int n = 5;
    while (n > 0) {
        std::cout << n << ' ';
        --n;
    }
    std::cout << '\n';

    // --- range-based for loop with break ---
    std::vector<int> marks = {90, 85, 77, 60};

    std::cout << "Marks (stopping below 65): ";
    for (int mark : marks) {
        if (mark < 65) {
            break;  // leave the loop early
        }
        std::cout << mark << ' ';
    }
    std::cout << '\n';

    return 0;
}
