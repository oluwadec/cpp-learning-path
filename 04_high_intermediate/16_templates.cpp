// Topic 16: Templates
// A template lets you write one function or class that works with many types.
// The compiler creates the right version for each type you use.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o templates 16_templates.cpp
// Run:     ./templates

#include <iostream>
#include <string>

// --- A function template ---
// T stands for "some type". It is filled in when you call the function.
template <typename T>
T biggerOf(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}

template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// --- A class template: a simple box that holds one value of any type ---
template <typename T>
class Box {
private:
    T value;

public:
    Box(T v) : value(v) {}

    T get() const {
        return value;
    }

    void set(T v) {
        value = v;
    }

    void print() const {
        std::cout << "Box contains: " << value << '\n';
    }
};

// --- A class template with a tiny array inside: a very simple stack ---
template <typename T>
class SimpleStack {
private:
    T items[10];
    int count;

public:
    SimpleStack() : count(0) {}

    void push(T item) {
        if (count < 10) {
            items[count] = item;
            ++count;
        }
    }

    T pop() {
        --count;
        return items[count];
    }

    bool isEmpty() const {
        return count == 0;
    }
};

int main() {
    // The same function works with different types.
    std::cout << biggerOf(3, 8) << '\n';                    // int
    std::cout << biggerOf(2.5, 1.5) << '\n';                // double
    std::cout << biggerOf<std::string>("apple", "pear") << '\n';

    int x = 1, y = 2;
    swapValues(x, y);
    std::cout << "x = " << x << ", y = " << y << '\n';

    std::string s1 = "left", s2 = "right";
    swapValues(s1, s2);
    std::cout << "s1 = " << s1 << ", s2 = " << s2 << '\n';

    // The same class works with different types.
    Box<int> numberBox(42);
    Box<std::string> textBox("hello");
    numberBox.print();
    textBox.print();

    numberBox.set(7);
    std::cout << "New number: " << numberBox.get() << '\n';

    // Stack: last in, first out.
    SimpleStack<std::string> stack;
    stack.push("first");
    stack.push("second");
    stack.push("third");

    std::cout << "\nPopping the stack: ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << ' ';
    }
    std::cout << '\n';

    return 0;
}
