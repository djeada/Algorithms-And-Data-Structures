#include <string>
#include <vector>

/**
 * @brief Searches for all occurrences of pattern in text using KMP algorithm.
 * @param text The text to search in.
 * @param pattern The pattern to search for.
 * @return Vector of starting indices where pattern is found in text.
 */
std::vector<int> search(const std::string &text, const std::string &pattern);