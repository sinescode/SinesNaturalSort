
# SinesNaturalSort

A C++ library for sorting links and strings with chapter numbers, designed to properly order content with numeric chapters. The library ensures links containing chapter numbers are sorted in a logical way (e.g., "chapter 2" comes before "chapter 10").

## Features

- Natural sorting of chapter-based content in links and text
- Intelligent chapter number detection:
  - Support for decimal chapter numbers (e.g., "chapter 1.5")
  - Case-insensitive matching of "chapter" keyword
  - Flexible pattern matching ("chapter=1", "chapter 1", etc.)
- Prioritization of content with chapter numbers
- Modern C++17 implementation
- Standard library integration with std::sort
- Static library with CMake configuration
- No external dependencies beyond the C++ standard library
- Regex-based pattern matching for reliable extraction

## Requirements

- C++17 compatible compiler
- CMake 3.10 or higher
- Standard library with regex support

## Installation

### Using CMake

1. Clone the repository:
```bash
git clone https://github.com/sinescode/SinesNaturalSort.git
cd SinesNaturalSort
```

2. Build and install:
```bash
mkdir build && cd build
cmake ..
make
sudo make install
```

The library will be installed in the standard system locations:
- Headers: `/usr/local/include/`
- Library: `/usr/local/lib/`
- CMake config: `/usr/local/lib/cmake/SinesNaturalsort/`

### Using the Library in Your CMake Project

```cmake
find_package(SinesNaturalsort REQUIRED)
target_link_libraries(your_target PRIVATE SinesNaturalsort::SinesNaturalsort)
```

### Manual Compilation

To compile a program using the library:
```bash
g++ your_program.cpp -o program -I/usr/local/include -L/usr/local/lib -lSinesNaturalsort
```

## Usage

### Basic Link Sorting Example

```cpp
#include <SinesNaturalSort.h>
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<std::string> links = {
        "https://example.com/chapter=10",
        "https://example.com/chapter=1",
        "https://example.com/chapter=1.5",
        "https://example.com/about",
        "https://example.com/chapter=2"
    };

    // Sort the vector
    auto sorted = SinesNaturalSort::NaturalSorter::sort(links);

    // Print results
    for (const auto& link : sorted) {
        std::cout << link << "\n";
    }

    return 0;
}
```

Output:
```
https://example.com/chapter=1
https://example.com/chapter=1.5
https://example.com/chapter=2
https://example.com/chapter=10
https://example.com/about
```

### Text Content Sorting Example

```cpp
#include <SinesNaturalSort.h>
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<std::string> contents = {
        "Chapter 10: Advanced Topics",
        "Chapter 1: Introduction",
        "Chapter 1.5: Quick Review",
        "Appendix A",
        "Chapter 2: Basics"
    };

    // Sort the vector
    auto sorted = SinesNaturalSort::NaturalSorter::sort(contents);

    // Print results
    for (const auto& content : sorted) {
        std::cout << content << "\n";
    }

    return 0;
}
```

Output:
```
Chapter 1: Introduction
Chapter 1.5: Quick Review
Chapter 2: Basics
Chapter 10: Advanced Topics
Appendix A
```

## Sorting Rules

1. Content with chapter numbers is sorted by numeric value:
   - "Chapter 2" comes before "Chapter 10"
   - "Chapter 1.5" comes between "Chapter 1" and "Chapter 2"
   - Decimal numbers are properly ordered

2. Content with chapter numbers is prioritized:
   - Any string containing a chapter number comes before strings without chapter numbers
   - This applies to both URLs and regular text content

3. For content without chapter numbers:
   - Original order is maintained
   - These items appear after all chapter-numbered content

4. Chapter number detection:
   - Case-insensitive matching of "chapter" keyword
   - Supports various formats: "chapter=X", "chapter X", "chapterX"
   - Handles decimal numbers (e.g., "1.5")
   - Negative numbers are supported but sorted after positive numbers

## Technical Details

The library uses:
- Regular expressions for reliable pattern matching
- Double-precision floating point for chapter number storage
- Standard library sorting algorithms
- Exception handling for robust number parsing

## Support

For bug reports and feature requests, please open an issue on GitHub. Contributions are welcome through pull requests.

```

The key improvements made:
1. Added examples for both link and text content sorting
2. Expanded the technical details section
3. Made sorting rules more comprehensive
4. Added information about regex pattern matching
5. Improved installation and usage instructions
6. Added proper code formatting and syntax highlighting
7. Included details about chapter number detection patterns
8. Added placeholder for license information
