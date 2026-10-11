// Topic 12: STL Algorithms
// The <algorithm> and <numeric> headers have ready-made tools for sorting,
// searching and counting, so you do not have to write the loops yourself.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o stl_algorithms 12_stl_algorithms.cpp
// Run:     ./stl_algorithms

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

// A small helper to print a vector.
void printVector(const std::string& label, const std::vector<int>& v) {
    std::cout << label << ": ";
    for (int x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

// A comparison function: tells sort() to put bigger numbers first.
bool biggerFirst(int a, int b) {
    return a > b;
}

int main() {
    std::vector<int> nums = {42, 7, 19, 3, 25, 7, 11};
    printVector("Original", nums);

    // --- sort ---
    std::sort(nums.begin(), nums.end());
    printVector("Sorted (small to big)", nums);

    std::sort(nums.begin(), nums.end(), biggerFirst);
    printVector("Sorted (big to small)", nums);

    // --- min and max ---
    int smallest = *std::min_element(nums.begin(), nums.end());
    int largest = *std::max_element(nums.begin(), nums.end());
    std::cout << "Smallest: " << smallest << ", largest: " << largest << '\n';

    // --- find ---
    auto it = std::find(nums.begin(), nums.end(), 19);
    if (it != nums.end()) {
        std::cout << "Found 19 at index " << (it - nums.begin()) << '\n';
    }

    // --- count ---
    std::cout << "The number 7 appears " << std::count(nums.begin(), nums.end(), 7)
              << " times\n";

    // --- accumulate: adds everything up ---
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    std::cout << "Sum: " << sum << ", average: "
              << static_cast<double>(sum) / nums.size() << '\n';

    // --- count_if with a tiny lambda (an unnamed function) ---
    int bigOnes = std::count_if(nums.begin(), nums.end(), [](int x) { return x > 10; });
    std::cout << "Numbers greater than 10: " << bigOnes << '\n';

    // --- reverse ---
    std::reverse(nums.begin(), nums.end());
    printVector("Reversed", nums);

    // --- binary_search needs a sorted vector ---
    std::sort(nums.begin(), nums.end());
    std::cout << "Is 25 in the list? " << std::boolalpha
              << std::binary_search(nums.begin(), nums.end(), 25) << '\n';

    // --- removing duplicates: sort, then unique, then erase ---
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    printVector("Without duplicates", nums);

    return 0;
}
