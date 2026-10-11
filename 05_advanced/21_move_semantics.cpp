// Topic 21: Move Semantics
// Copying big objects is slow. Moving "steals" the insides of a temporary or
// no-longer-needed object instead, which is much faster.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o move_semantics 21_move_semantics.cpp
// Run:     ./move_semantics

#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Buffer {
private:
    int* data;
    int size;

public:
    Buffer(int length) : data(new int[length]), size(length) {
        for (int i = 0; i < size; ++i) {
            data[i] = i;
        }
        std::cout << "  constructed (" << size << " ints)\n";
    }

    ~Buffer() {
        delete[] data;                  // deleting nullptr is safe, so moved-from objects are fine
    }

    // Copy constructor: allocates new memory and copies every value (slow).
    Buffer(const Buffer& other) : data(new int[other.size]), size(other.size) {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        std::cout << "  COPIED (" << size << " ints)\n";
    }

    // Move constructor: takes the other object's memory (fast, no copying).
    // The && means "a temporary or an object we are allowed to steal from".
    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;           // leave the old object empty but safe
        other.size = 0;
        std::cout << "  MOVED (stole the memory)\n";
    }

    // Copy assignment and move assignment are written the same way as the constructors.
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
            std::cout << "  copy-assigned\n";
        }
        return *this;
    }

    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "  move-assigned\n";
        }
        return *this;
    }

    int getSize() const {
        return size;
    }
};

// Builds a Buffer and returns it. The compiler moves (or skips) the copy.
Buffer makeBuffer() {
    Buffer b(4);
    return b;
}

int main() {
    // --- Strings: see std::move in action ---
    std::string original = "a long piece of text";
    std::string moved = std::move(original);    // original's contents go to moved

    std::cout << "moved = \"" << moved << "\"\n";
    std::cout << "original is now length " << original.size() << " (empty)\n";

    // --- A vector of strings ---
    std::vector<std::string> names;
    std::string name = "Ada";
    names.push_back(name);                      // copies name
    names.push_back(std::move(name));           // moves name (cheaper)
    std::cout << "names holds " << names.size() << " entries\n";

    // --- Our own class ---
    std::cout << "\nCopy:\n";
    Buffer a(3);
    Buffer b = a;                               // copy constructor

    std::cout << "Move:\n";
    Buffer c = std::move(a);                    // move constructor
    std::cout << "  a has size " << a.getSize() << " now, c has size " << c.getSize() << '\n';

    std::cout << "Returning from a function:\n";
    Buffer d = makeBuffer();
    std::cout << "  d has size " << d.getSize() << '\n';

    std::cout << "Move assignment:\n";
    Buffer e(2);
    e = std::move(b);
    std::cout << "  e has size " << e.getSize() << '\n';

    return 0;
}
