#include "SinesNaturalSort.h"

namespace SinesNaturalSort {

std::vector<std::string> NaturalSorter::sort(std::vector<std::string>& links) {
    std::sort(links.begin(), links.end(), compareLinks);
    return links;
}

double NaturalSorter::extractChapterNumber(const std::string& url) {
    static const std::regex chapter_pattern(R"(chapter[=\s]?(\d+(\.\d+)?))", std::regex::icase);
    std::smatch match;
    
    if (std::regex_search(url, match, chapter_pattern)) {
        try {
            return std::stod(match[1]);
        } catch(...) {
            return -1;
        }
    }
    return -1;
}

bool NaturalSorter::compareLinks(const std::string& a, const std::string& b) {
    double chapter_a = extractChapterNumber(a);
    double chapter_b = extractChapterNumber(b);

    // If both have valid chapter numbers, sort numerically
    if (chapter_a != -1 && chapter_b != -1) {
        return chapter_a < chapter_b;
    }

    // Prioritize links with chapter numbers
    if (chapter_a != -1 && chapter_b == -1) {
        return true;
    }
    if (chapter_a == -1 && chapter_b != -1) {
        return false;
    }

    // If no chapter numbers found, maintain original order
    return false;
}

} // namespace SinesNaturalSort