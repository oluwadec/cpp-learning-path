#include <iostream>
#include <vector>

int main () {
    int score = 72;

    if (score >= 70){
        std::cout << " Grade: A " << std::endl;
    } else if (score >= 60){
        std::cout << " Grade: B " << std::endl;   
    } else {
        std::cout << " Grade: C or below " << std::endl;    
    }

    int day = 3;
    switch (day) {
        case 1: std::cout << " Monday " << std::endl; break;
        case 2: std::cout << " Tuesday " << std::endl; break;
        case 3: std::cout << " Wednesday" << std::endl; break;
        case 4: std::cout << " Friday " << std::endl; break;
        default: std::cout <<" Unkown day " << std::endl;
    }
   
    for (int i = 1; i <= 5; ++i){
        if ( i == 4) continue; // skip 4
        std::cout << i << " ";
    }
    std::cout << " " << std::endl;

    // while loop
    int n = 5; 
    while (n > 0) {
        std::cout << n << " ";
        --n;
    }
    std::cout << " " << std::endl; 

    // range-based for (modern c ++)
    std::vector<int> marks = {90, 85, 77, 60};
    for (int m : marks)  {
        if (m < 65) break; // stop early
        std::cout << m << " ";
    }
    std::cout << " " << std::endl;

    return 0;
}
