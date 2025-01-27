#ifndef SINES_NATURAL_SORT_H
#define SINES_NATURAL_SORT_H

#include <string>
#include <vector>
#include <regex>

namespace SinesNaturalSort {

class NaturalSorter {
public:
    static std::vector<std::string> sort(std::vector<std::string>& links);

private:
    static double extractChapterNumber(const std::string& url);
    static bool compareLinks(const std::string& a, const std::string& b);
};

} // namespace SinesNaturalSort

#endif // SINES_NATURAL_SORT_H