#include <iostream>
#include <string> // FIX 1: Added missing header for strings

 int add(int a, int b) { return a + b; } 
 double add(double a, double b) { return a + b; } // overload

 // FIX 2: Fixed the typo from 'std::sring' to 'std::string'
 void greet(std::string name, std::string greeting = "Hello") {
    std::cout << greeting << ", " << name << std::endl;
 }

 void doubleIt(int &x) { 
    x *=2;
 }

 int main () {
    std::cout << add(2, 3) << std::endl; // calls int version
    std::cout << add(2.5, 3.1) << std::endl;
    
    greet("Logo");
    greet("Logo", " Welcome Back" );

    int value = 10;
    doubleIt(value);
    std::cout << " Value = " << value << std::endl; // 20

    return 0;
 }
