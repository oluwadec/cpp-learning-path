// Topic 20: Copying Objects and RAII
// When a class owns memory, copying it needs care. The "rule of three" says: if you
// write a destructor, you almost always need a copy constructor and a copy
// assignment operator too. RAII means the object cleans up after itself.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o copy_and_raii 20_copy_and_raii.cpp
// Run:     ./copy_and_raii

#include <iostream>

class IntArray {
private:
    int* data;
    int size;

public:
    // Constructor: acquires the memory (RAII: resource acquired when object is created).
    IntArray(int length) : data(new int[length]), size(length) {
        for (int i = 0; i < size; ++i) {
            data[i] = 0;
        }
        std::cout << "  created array of " << size << '\n';
    }

    // 1. Destructor: releases the memory automatically when the object dies.
    ~IntArray() {
        delete[] data;
        std::cout << "  destroyed array of " << size << '\n';
    }

    // 2. Copy constructor: makes a deep copy (its own separate memory).
    IntArray(const IntArray& other) : data(new int[other.size]), size(other.size) {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        std::cout << "  copied array of " << size << '\n';
    }

    // 3. Copy assignment: same idea, but we must clean up the old memory first.
    IntArray& operator=(const IntArray& other) {
        if (this == &other) {           // guard against a = a
            return *this;
        }
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        std::cout << "  assigned array of " << size << '\n';
        return *this;
    }

    void set(int index, int value) {
        data[index] = value;
    }

    int get(int index) const {
        return data[index];
    }

    void print() const {
        std::cout << "  [";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i];
            if (i < size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }
};

int main() {
    std::cout << "Create the original:\n";
    IntArray original(3);
    original.set(0, 10);
    original.set(1, 20);
    original.set(2, 30);
    original.print();

    std::cout << "\nCopy constructor:\n";
    IntArray copy = original;           // calls the copy constructor
    copy.set(0, 99);                    // changing the copy...
    std::cout << "original: ";
    original.print();                   // ...does not change the original
    std::cout << "copy: ";
    copy.print();

    std::cout << "\nCopy assignment:\n";
    IntArray another(2);
    another = original;                 // calls operator=
    another.print();

    std::cout << "\nScope and RAII:\n";
    {
        IntArray temporary(5);
        std::cout << "  inside the block\n";
    }                                   // temporary is destroyed here automatically
    std::cout << "  after the block\n";

    std::cout << "\nEnd of main:\n";
    return 0;
}
