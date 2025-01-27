# SinesNaturalSort

A modern C++ natural string sorting library that handles mixed alphanumeric content intelligently. Natural sorting ensures that strings containing numbers are sorted in a human-intuitive way (e.g., "file2.txt" comes before "file10.txt").

## Features

- Natural ordering of alphanumeric strings
- Case-insensitive string comparison
- Support for:
  - Negative numbers
  - Decimal values
  - Mixed alphanumeric content
  - Leading zeros in numbers
- Modern C++17 implementation
- Static library with CMake integration
- Header-only option available
- No external dependencies

## Requirements

- C++17 compatible compiler
- CMake 3.10 or higher

## Installation

### Using CMake

1. Clone the repository:
```bash
https://github.com/sinescode/SinesNaturalSort.git
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

To compile a test program:
```bash
g++ test.cpp -o sanitizest -I/usr/local/include -L/usr/local/lib -lSinesNaturalsort
```

## Usage

### Basic Example

```cpp
#include <sinesnaturalsort.hpp>
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<std::string> files = {
        "file1.txt",
        "file10.txt",
        "file2.txt",
        "file-1.txt",
        "file1.5.txt"
    };

    // Sort the vector
    auto sorted = sinesnaturalsort::NaturalSorter::sort(files);

    // Print results
    for (const auto& file : sorted) {
        std::cout << file << "\n";
    }

    return 0;
}
```

Output:
```
file-1.txt
file1.txt
file1.5.txt
file2.txt
file10.txt
```

### Using Iterator Interface

```cpp
std::vector<std::string> files = {"file2.txt", "file10.txt", "file1.txt"};
sinesnaturalsort::NaturalSorter::sort(files.begin(), files.end());
```

## API Reference

### Class `NaturalSorter`

#### Static Methods

```cpp
static std::vector<std::string> sort(const std::vector<std::string>& input);
```
- Creates a new sorted vector from the input
- Returns: Sorted copy of the input vector
- Thread-safe: Yes

```cpp
template<typename Iterator>
static void sort(Iterator begin, Iterator end);
```
- Sorts any container in-place using iterators
- Template parameters: Any iterator type pointing to strings
- Thread-safe: Yes

### Sorting Rules

1. Numbers are compared by value:
   - "2" < "10"
   - "1.5" < "2"
   - "-1" < "1"

2. Case-insensitive string comparison:
   - "a" = "A"
   - "file" = "FILE"

3. Mixed content handling:
   - Numbers and strings are separated and compared independently
   - Leading zeros are ignored in number comparisons

## Support

For bug reports and feature requests, please open an issue on GitHub.