#include <iostream>
#include <vector>
#include <map>
#include <set>

int main (){
    std::vector<int> nums = {5, 2, 9};
    nums.push_back(14); // add to end
    nums.insert(nums.begin(), 1); // insert at front

    for (size_t i =0; i < nums.size(); ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << " " << std::endl;
    
    nums.pop_back(); // remove last element
    std::cout << " Size after pop: " << nums.size() << std::endl;
    std::cout << " Front: " << nums.front() << ", Back: " << nums.back() << std::endl;

    std::map<std::string, int> ages; 
    ages["Logo"] = 21;
    ages["seun"] = 26;
    ages["seyi"] = 23;

 for (const auto &pair : ages) {
    std::cout << pair.first << " -> " << pair.second << std::endl;
 }

 if (ages.find("seun") != ages.end()) {
    std::cout << " seun is present " << std::endl;
 }

 std::set<int> uniqueMarks = { 70, 55, 70, 90, 55};
 for ( int m : uniqueMarks) std::cout << m << " "; // 55 70 90
 std::cout << " " << std::endl;

 return 0;
 }
