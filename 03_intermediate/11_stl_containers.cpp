// Topic 11: STL Containers
// Introduces std::vector, std::map and std::set.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o stl_containers 11_stl_containers.cpp
// Run:     ./stl_containers

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
    // --- vector: a resizable array ---
    std::vector<int> nums = {5, 2, 9};
    nums.push_back(14);                // add to the end
    nums.insert(nums.begin(), 1);      // insert at the front

    std::cout << "Vector: ";
    for (std::size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << ' ';
    }
    std::cout << '\n';

    nums.pop_back();                   // remove the last element
    std::cout << "Size after pop: " << nums.size() << '\n';
    std::cout << "Front: " << nums.front() << ", Back: " << nums.back() << '\n';

    // --- map: key -> value pairs, sorted by key ---
    std::map<std::string, int> ages;
    ages["Ada"] = 21;
    ages["Bola"] = 26;
    ages["Chidi"] = 23;

    std::cout << "\nAges:\n";
    for (const auto& entry : ages) {
        std::cout << entry.first << " -> " << entry.second << '\n';
    }

    if (ages.find("Bola") != ages.end()) {
        std::cout << "Bola is present\n";
    }

    // --- set: unique values, automatically sorted ---
    std::set<int> uniqueMarks = {70, 55, 70, 90, 55};

    std::cout << "\nUnique marks: ";
    for (int mark : uniqueMarks) {
        std::cout << mark << ' ';      // 55 70 90
    }
    std::cout << '\n';

    return 0;
}
