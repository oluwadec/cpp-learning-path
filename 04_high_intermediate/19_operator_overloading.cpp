// Topic 19: Operator Overloading
// You can teach +, -, ==, << and other operators how to work with your own classes.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o operator_overloading 19_operator_overloading.cpp
// Run:     ./operator_overloading

#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double xValue = 0, double yValue = 0) : x(xValue), y(yValue) {}

    // a + b
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // a - b
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    // a * 3  (multiply by a number)
    Vector2D operator*(double factor) const {
        return Vector2D(x * factor, y * factor);
    }

    // a == b
    bool operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }

    // a != b
    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    // a += b
    Vector2D& operator+=(const Vector2D& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    // Lets us write std::cout << vector. It is a friend so it can read x and y.
    friend std::ostream& operator<<(std::ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }
};

int main() {
    Vector2D a(1, 2);
    Vector2D b(3, 4);

    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';

    std::cout << "a + b = " << a + b << '\n';
    std::cout << "b - a = " << b - a << '\n';
    std::cout << "a * 3 = " << a * 3 << '\n';

    std::cout << std::boolalpha;
    std::cout << "a == b? " << (a == b) << '\n';
    std::cout << "a == (1, 2)? " << (a == Vector2D(1, 2)) << '\n';
    std::cout << "a != b? " << (a != b) << '\n';

    // A moving object: add its speed to its position over and over.
    Vector2D position(0, 0);
    Vector2D speed(2, 1);

    std::cout << "\nMoving:\n";
    for (int step = 1; step <= 3; ++step) {
        position += speed;
        std::cout << "  step " << step << ": " << position << '\n';
    }

    return 0;
}
