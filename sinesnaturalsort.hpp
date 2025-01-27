// sinesnaturalsort.hpp
#ifndef SINES_NATURAL_SORT_HPP
#define SINES_NATURAL_SORT_HPP

#include <string>
#include <vector>
#include <regex>
#include <variant>
#include <cctype>

namespace sinesnaturalsort {

// Token can be either a string, integer, or double
using Token = std::variant<std::string, int64_t, double>;

class NaturalSorter {
public:
    // Main sorting function for vector of strings
    static std::vector<std::string> sort(const std::vector<std::string>& input);
    
    // Sort function that works with any container using iterators
    template<typename Iterator>
    static void sort(Iterator begin, Iterator end);

private:
    // Tokenize string into components
    static std::vector<Token> tokenize(const std::string& str);
    
    // Helper function to convert string to number if possible
    static Token parseToken(const std::string& token);
    
    // Compare two vectors of tokens
    static bool compareTokens(const std::vector<Token>& a, const std::vector<Token>& b);
};

} // namespace sinesnaturalsort

#endif // SINES_NATURAL_SORT_HPP