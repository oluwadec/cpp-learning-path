// Topic 7: Structs
// A struct groups related variables into one new type.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o structs 07_structs.cpp
// Run:     ./structs

#include <iostream>
#include <string>
#include <vector>

// A struct describing one student.
struct Student {
    std::string name;
    int age;
    double gpa;
};

// Structs can be passed to functions like any other type.
void printStudent(const Student& s) {
    std::cout << s.name << ", age " << s.age << ", GPA " << s.gpa << '\n';
}

int main() {
    // --- Creating a struct ---
    Student ada;
    ada.name = "Ada";
    ada.age = 20;
    ada.gpa = 3.8;

    // Shorter: give all the values at once.
    Student bola = {"Bola", 22, 3.2};

    printStudent(ada);
    printStudent(bola);

    // --- A vector of structs ---
    std::vector<Student> classList;
    classList.push_back(ada);
    classList.push_back(bola);
    classList.push_back({"Chidi", 21, 3.5});

    std::cout << "\nClass list:\n";
    for (const Student& s : classList) {
        printStudent(s);
    }

    // --- Finding the student with the highest GPA ---
    Student best = classList[0];
    for (const Student& s : classList) {
        if (s.gpa > best.gpa) {
            best = s;
        }
    }
    std::cout << "\nTop student: " << best.name << '\n';

    // --- Average GPA ---
    double total = 0;
    for (const Student& s : classList) {
        total += s.gpa;
    }
    std::cout << "Average GPA: " << total / classList.size() << '\n';

    return 0;
}
