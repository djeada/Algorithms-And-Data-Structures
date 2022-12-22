#include <set>
#include <string>
#include <unordered_set>
#include <vector>

std::set<std::string>
generate_words(const std::vector<std::vector<char>> &board,
               const std::unordered_set<std::string> &word_dict);