// Topic 9: File Input and Output
// Writes some lines to a text file, reads them back, then appends and cleans up.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o file_io 09_file_io.cpp
// Run:     ./file_io

#include <cstdio>      // std::remove, used to delete the file at the end
#include <fstream>
#include <iostream>
#include <string>

int main() {
    const std::string fileName = "scores.txt";

    // --- Writing to a file (ofstream = output file stream) ---
    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cout << "Could not open the file for writing\n";
        return 1;
    }
    outFile << "Ada 85\n";
    outFile << "Bola 72\n";
    outFile << "Chidi 90\n";
    outFile.close();
    std::cout << "Saved 3 lines to " << fileName << '\n';

    // --- Appending to the end of the file ---
    std::ofstream appendFile(fileName, std::ios::app);
    appendFile << "Dayo 66\n";
    appendFile.close();

    // --- Reading the whole file line by line (ifstream = input file stream) ---
    std::ifstream inFile(fileName);
    if (!inFile) {
        std::cout << "Could not open the file for reading\n";
        return 1;
    }

    std::cout << "\nFile contents:\n";
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << "  " << line << '\n';
    }
    inFile.close();

    // --- Reading word by word and doing maths ---
    std::ifstream scoresFile(fileName);
    std::string name;
    int score;
    int total = 0;
    int count = 0;

    while (scoresFile >> name >> score) {   // reads a name, then a number
        total += score;
        ++count;
    }
    scoresFile.close();

    std::cout << "\nStudents: " << count << ", average score: "
              << static_cast<double>(total) / count << '\n';

    // --- Cleaning up: delete the file we created ---
    std::remove(fileName.c_str());
    std::cout << "Deleted " << fileName << '\n';

    return 0;
}
