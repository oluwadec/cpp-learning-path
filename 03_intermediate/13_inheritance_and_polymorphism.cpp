// Topic 13: Inheritance and Polymorphism
// A child class can reuse everything from a parent class. With "virtual" functions,
// one pointer type can run different code depending on the real object behind it.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o inheritance 13_inheritance_and_polymorphism.cpp
// Run:     ./inheritance

#include <iostream>
#include <string>
#include <vector>

// Parent (base) class.
class Shape {
protected:
    std::string name;

public:
    Shape(const std::string& shapeName) : name(shapeName) {}

    // virtual: lets child classes replace this function.
    virtual double area() const {
        return 0;
    }

    virtual void describe() const {
        std::cout << name << " with area " << area() << '\n';
    }

    // A virtual destructor is needed when deleting through a parent pointer.
    virtual ~Shape() {}
};

// Child class: Rectangle IS-A Shape.
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

    void describe() const override {
        std::cout << "A square! ";
        Rectangle::describe();          // reuse the parent's version too
    }
};

int main() {
    Rectangle rect(4, 5);
    Circle circle(3);
    Square square(6);

    rect.describe();
    circle.describe();
    square.describe();

    // --- Polymorphism: one list holding different kinds of shapes ---
    std::cout << "\nUsing pointers to the base class:\n";
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle(2, 3));
    shapes.push_back(new Circle(1.5));
    shapes.push_back(new Square(4));

    double totalArea = 0;
    for (Shape* s : shapes) {
        s->describe();                  // each object runs its own version
        totalArea += s->area();
    }
    std::cout << "Total area: " << totalArea << '\n';

    // Clean up the objects we created with new.
    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}
