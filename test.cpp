#include <iostream>
#include <vector>
#include <string>
#include "sinesnaturalsort.hpp"

using namespace sinesnaturalsort;

int main() {
    // Example 4: Using sort function on a vector of strings
    std::vector<std::string> input = {"item10", "item1", "item2", "item20", "item11"};
    std::cout << "\nSorting strings naturally using static sort function: \n";
    auto sorted = NaturalSorter::sort(input);

    std::cout << "Sorted: ";
    for (const auto& item : sorted) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Example 5: Using sort function with iterators
    std::vector<std::string> input2 = {"file30", "file2", "file10", "file1"};
    std::cout << "\nSorting strings with iterators using template sort function: \n";
    NaturalSorter::sort(input2.begin(), input2.end());

    std::cout << "Sorted: ";
    for (const auto& item : input2) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}
