#include <iostream>

int main () {
    int age = 21; // whole numbers
    double gpa = 4.87; // floating point
    char grade = 'A'; // single character
    bool passed = true; // ture / false
    std::string name = "Logo"; // text (needs<string>)
   
    std::cout << name << " is " << age << " years old , GPA: " << gpa << std::endl;
    std::cout << " Size of int: " << sizeof(int) << " bytes " << std::endl;
    
    return 0;

}