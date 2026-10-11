// Topic 5: Arrays and Strings
// Covers plain arrays, 2D arrays and the most useful std::string operations.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o arrays_and_strings 05_arrays_and_strings.cpp
// Run:     ./arrays_and_strings

#include <iostream>
#include <string>

int main() {
    // --- A plain array: a fixed number of values of the same type ---
    int scores[5] = {70, 85, 90, 62, 78};
    int total = 0;

    for (int i = 0; i < 5; ++i) {
        total += scores[i];             // arrays start counting at 0
    }
    std::cout << "Total: " << total << ", average: " << total / 5.0 << '\n';

    // --- Finding the biggest value ---
    int biggest = scores[0];
    for (int i = 1; i < 5; ++i) {
        if (scores[i] > biggest) {
            biggest = scores[i];
        }
    }
    std::cout << "Highest score: " << biggest << '\n';

    // --- A 2D array: rows and columns ---
    int grid[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    std::cout << "\nGrid:\n";
    for (int row = 0; row < 2; ++row) {
        for (int col = 0; col < 3; ++col) {
            std::cout << grid[row][col] << ' ';
        }
        std::cout << '\n';
    }

    // --- Strings ---
    std::string word = "programming";

    std::cout << "\nWord: " << word << '\n';
    std::cout << "Length: " << word.length() << '\n';
    std::cout << "First letter: " << word[0] << '\n';
    std::cout << "First 7 letters: " << word.substr(0, 7) << '\n';

    std::size_t position = word.find("gram");
    if (position != std::string::npos) {
        std::cout << "\"gram\" starts at index " << position << '\n';
    }

    std::string sentence = "I love ";
    sentence += "C++";                  // += joins strings together
    std::cout << sentence << '\n';

    // --- Counting vowels with a loop ---
    int vowels = 0;
    for (char c : word) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ++vowels;
        }
    }
    std::cout << "Vowels in \"" << word << "\": " << vowels << '\n';

    return 0;
}
