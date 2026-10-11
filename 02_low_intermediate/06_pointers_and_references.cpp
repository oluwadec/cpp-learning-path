// Topic 6: Pointers and References
// A pointer stores the memory address of another variable. A reference is another name for one.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o pointers_and_references 06_pointers_and_references.cpp
// Run:     ./pointers_and_references

#include <iostream>

// Takes a pointer, so the function can change the caller's variable.
void addTen(int* number) {
    *number = *number + 10;             // * means "the value the pointer points to"
}

// Swaps two values using references (no * needed inside the function).
void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    // --- Pointer basics ---
    int score = 50;
    int* ptr = &score;                  // & means "the address of"

    std::cout << "score = " << score << '\n';
    std::cout << "ptr points to a value of " << *ptr << '\n';

    *ptr = 75;                          // changing the value through the pointer
    std::cout << "score after *ptr = 75: " << score << '\n';

    // --- Passing a pointer to a function ---
    addTen(&score);
    std::cout << "score after addTen: " << score << '\n';

    // --- nullptr: a pointer that points to nothing ---
    int* empty = nullptr;
    if (empty == nullptr) {
        std::cout << "empty pointer: do not use it!\n";
    }

    // --- Pointers and arrays ---
    int numbers[3] = {10, 20, 30};
    int* p = numbers;                   // an array name acts like a pointer to its first item

    std::cout << "\nWalking through the array with a pointer: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << *(p + i) << ' ';   // p + i moves along the array
    }
    std::cout << '\n';

    // --- References ---
    int apples = 4;
    int& alias = apples;                // alias is another name for apples
    alias = 9;
    std::cout << "\napples = " << apples << " (changed through the alias)\n";

    int first = 1;
    int second = 2;
    swapValues(first, second);
    std::cout << "After swap: first = " << first << ", second = " << second << '\n';

    return 0;
}
