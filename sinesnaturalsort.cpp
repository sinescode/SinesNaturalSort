// sinesnaturalsort.cpp
#include "sinesnaturalsort.hpp"
#include <algorithm>
#include <sstream>

namespace sinesnaturalsort {

std::vector<std::string> NaturalSorter::sort(const std::vector<std::string>& input) {
    std::vector<std::string> result = input;
    sort(result.begin(), result.end());
    return result;
}

template<typename Iterator>
void NaturalSorter::sort(Iterator begin, Iterator end) {
    std::sort(begin, end, [](const std::string& a, const std::string& b) {
        return compareTokens(tokenize(a), tokenize(b));
    });
}

std::vector<Token> NaturalSorter::tokenize(const std::string& str) {
    std::vector<Token> tokens;
    std::regex pattern(R"(([+-]?\d*\.\d+|[+-]?\d+|\D+))");
    
    std::sregex_iterator it(str.begin(), str.end(), pattern);
    std::sregex_iterator end;
    
    while (it != end) {
        std::string token = it->str();
        tokens.push_back(parseToken(token));
        ++it;
    }
    
    return tokens;
}

Token NaturalSorter::parseToken(const std::string& token) {
    // Try parsing as double first (handles both integers and decimals)
    try {
        // Check if it's a number pattern
        if (std::regex_match(token, std::regex(R"([+-]?\d*\.?\d+)"))) {
            // If it contains a decimal point, parse as double
            if (token.find('.') != std::string::npos) {
                return std::stod(token);
            }
            // Otherwise parse as integer
            return std::stoll(token);
        }
    } catch (...) {
        // If parsing fails, return as string
    }
    
    // Convert to lowercase for case-insensitive comparison
    std::string lowercase = token;
    std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(), 
                  [](unsigned char c) { return std::tolower(c); });
    return lowercase;
}

bool NaturalSorter::compareTokens(const std::vector<Token>& a, const std::vector<Token>& b) {
    size_t minSize = std::min(a.size(), b.size());
    
    for (size_t i = 0; i < minSize; ++i) {
        if (a[i].index() != b[i].index()) {
            return a[i].index() < b[i].index();
        }
        
        if (const auto* aStr = std::get_if<std::string>(&a[i])) {
            const auto* bStr = std::get_if<std::string>(&b[i]);
            if (*aStr != *bStr) return *aStr < *bStr;
        }
        else if (const auto* aInt = std::get_if<int64_t>(&a[i])) {
            const auto* bInt = std::get_if<int64_t>(&b[i]);
            if (*aInt != *bInt) return *aInt < *bInt;
        }
        else if (const auto* aDouble = std::get_if<double>(&a[i])) {
            const auto* bDouble = std::get_if<double>(&b[i]);
            if (*aDouble != *bDouble) return *aDouble < *bDouble;
        }
    }
    
    return a.size() < b.size();
}

} // namespace sinesnaturalsort