// Topic 15: Dynamic Memory
// "new" creates a variable that lives until you remove it with "delete".
// Every new must be matched with a delete, otherwise memory is leaked.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o dynamic_memory 15_dynamic_memory.cpp
// Run:     ./dynamic_memory

#include <iostream>

int main() {
    // --- A single value on the heap ---
    int* number = new int(42);
    std::cout << "Value: " << *number << '\n';

    *number = 100;
    std::cout << "Changed to: " << *number << '\n';

    delete number;                      // give the memory back
    number = nullptr;                   // avoid a dangling pointer

    // --- A dynamic array whose size is decided while the program runs ---
    int size = 5;
    int* squares = new int[size];       // use new[] for arrays

    for (int i = 0; i < size; ++i) {
        squares[i] = i * i;
    }

    std::cout << "\nSquares: ";
    for (int i = 0; i < size; ++i) {
        std::cout << squares[i] << ' ';
    }
    std::cout << '\n';

    delete[] squares;                   // use delete[] for arrays
    squares = nullptr;

    // --- Growing an array by hand (this is what std::vector does for you) ---
    int capacity = 2;
    int count = 0;
    int* data = new int[capacity];

    for (int value = 10; value <= 50; value += 10) {
        if (count == capacity) {
            int newCapacity = capacity * 2;
            int* bigger = new int[newCapacity];
            for (int i = 0; i < count; ++i) {
                bigger[i] = data[i];    // copy the old items across
            }
            delete[] data;
            data = bigger;
            capacity = newCapacity;
            std::cout << "Array grew to capacity " << capacity << '\n';
        }
        data[count] = value;
        ++count;
    }

    std::cout << "Data: ";
    for (int i = 0; i < count; ++i) {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';

    delete[] data;

    return 0;
}
